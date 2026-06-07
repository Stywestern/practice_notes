# sampler.py

"""
The main bulk of calculations and data usage. It uses MCMC to calculate the main equation's parameters and also
the kernel hyperparameters.
"""

import numpy as np
import pickle
import os
from scipy import linalg
from tqdm import tqdm

from gp_kernels import compute_covariance_matrix, compute_car_precision_matrix
from data_loader import PopulationLoader
from project_constants import QUEEN_MATRIX, REGIONS

##################################################################################################
#                                       Class
###################################s###############################################################

class SpatioTemporalSampler:
    def __init__(self, y_data, X_data, W, iterations=50000, burn_in=10000):
        # Data storage
        self.y = y_data          
        self.X = X_data          
        self.W = W               
        self.I = len(y_data)     
        self.T = len(y_data[0])  
        self.years = np.arange(self.T)
        
        self.iterations = iterations
        self.burn_in = burn_in
        
        # Bayesian Priors
        self.beta_prior_var = 1e5
        self.rho_s = 0 # network strenght coeff         
        self.spatial_tau_sq = 1.0 
        
        # Initial State
        self.log_sigma_sq = np.zeros(self.I)
        self.log_phi = np.ones(self.I)
        self.log_nu_sq = np.full(self.I, -2.0) 
        self.beta = [np.zeros(X.shape[1]) for X in self.X]
        self.Z = [np.zeros(self.T) for _ in range(self.I)]
        self.Q = compute_car_precision_matrix(self.W, self.rho_s)
        
        self.diag = {
            'sigma_acc': 0,
            'phi_acc': np.zeros(self.I),
            'total_steps': 0
        }

    def _step_1_update_variances(self):
        """Metropolis step for spatial variances."""
        proposal_width = 0.05
        current_psi = self.log_sigma_sq
        proposed_psi = current_psi + np.random.normal(0, proposal_width, self.I)
        
        def get_log_post(psi):
            # Spatial Prior: -0.5 * psi^T * Q * psi
            lp = -0.5 / self.spatial_tau_sq * (psi.T @ self.Q @ psi)
            for i in range(self.I):
                s2 = np.exp(psi[i])
                resid = self.y[i] - self.X[i] @ self.beta[i] - self.Z[i]
                # Likelihood term
                lp += -0.5 * self.T * psi[i] - 0.5 / (s2 * np.exp(self.log_nu_sq[i])) * np.sum(resid**2)
            return lp

        log_acc = get_log_post(proposed_psi) - get_log_post(current_psi)
        if np.log(np.random.rand()) < log_acc:
            self.log_sigma_sq = proposed_psi
            self.diag['sigma_acc'] += 1

    def _step_2_update_region_specific(self, i):
        """Update phi, beta, and Z for region i."""
        # Update log-phi (MH)
        prop_log_phi = self.log_phi[i] + np.random.normal(0, 0.1)
        
        def log_post_phi(val):
            phi = np.exp(val)
            rho = compute_covariance_matrix(self.years, 1.0, phi)
            try:
                # Term: -0.5 * log|rho| - 0.5 * Z^T * inv(rho) * Z
                inv_rho = linalg.inv(rho)
                return -0.5 * np.log(linalg.det(rho)) - 0.5 / np.exp(self.log_sigma_sq[i]) * (self.Z[i].T @ inv_rho @ self.Z[i])
            except: return -np.inf

        if np.log(np.random.rand()) < log_post_phi(prop_log_phi) - log_post_phi(self.log_phi[i]):
            self.log_phi[i] = prop_log_phi
            self.diag['phi_acc'][i] += 1

        # Update Beta Weights (Gibbs Sampling)
        s2 = np.exp(self.log_sigma_sq[i])
        tau2 = s2 * np.exp(self.log_nu_sq[i])
        XtX = self.X[i].T @ self.X[i]
        post_cov = linalg.inv(XtX / tau2 + np.eye(self.X[i].shape[1]) / self.beta_prior_var)
        post_mean = post_cov @ (self.X[i].T @ (self.y[i] - self.Z[i]) / tau2)
        self.beta[i] = np.random.multivariate_normal(post_mean, post_cov)

        # Update Temporal Wiggles (Z_i)
        rho_inv = linalg.inv(compute_covariance_matrix(self.years, 1.0, np.exp(self.log_phi[i])))
        post_prec = (rho_inv / s2) + (np.eye(self.T) / tau2)
        post_cov_Z = linalg.inv(post_prec)
        post_mean_Z = post_cov_Z @ (self.y[i] - self.X[i] @ self.beta[i]) / tau2
        self.Z[i] = np.random.multivariate_normal(post_mean_Z, post_cov_Z)

    def sample_iteration(self):
        self.diag['total_steps'] += 1
        self._step_1_update_variances()
        for i in range(self.I):
            self._step_2_update_region_specific(i)

    def get_diagnostics(self):
        """Returns key health metrics for the chain."""
        total = self.diag['total_steps']
        sigma_rate = (self.diag['sigma_acc'] / total) * 100
        phi_rate = (np.mean(self.diag['phi_acc']) / total) * 100
        return sigma_rate, phi_rate


##################################################################################################
#                                       Runner
##################################################################################################

def run_pipeline(target='total', iterations=50000, burn_in=10000):
    print(f"\n{'='*40}")
    print(f"PIPELINE START: Target = {target.upper()}")
    print(f"{'='*40}")

    # 1. Load and Preprocess
    loader = PopulationLoader('datasets/master_dataset.csv')
    loader.preprocess()
    
    y_list, X_list = [], []
    for region in REGIONS:
        y_reg, X_reg = loader.get_region_data(region, target_type=target)
        y_list.append(y_reg)
        X_list.append(X_reg)
    
    sampler = SpatioTemporalSampler(y_list, X_list, np.array(QUEEN_MATRIX), iterations, burn_in)
    posterior_samples = []

    # 2. Loop 
    for it in tqdm(range(iterations), desc=f"MCMC [{target}]"):
        sampler.sample_iteration()
        
        # Every 1000 iterations print
        if it % 1000 == 0 and it > 0:
            s_acc, p_acc = sampler.get_diagnostics()
            # Inspect Istanbul (Index 10) as our 'Canary'
            istanbul_beta = sampler.beta[10][1] 
            print(f"\n[Iter {it}] Acc Rates: Sigma={s_acc:.1f}% | Phi={p_acc:.1f}% | Istanbul Birth-Beta: {istanbul_beta:.4f}")

        # Store samples
        if it > burn_in and it % 10 == 0:
            posterior_samples.append({
                'beta': [b.copy() for b in sampler.beta],
                'sigma': np.exp(sampler.log_sigma_sq).copy(),
                'phi': np.exp(sampler.log_phi).copy(),
                'Z': [z.copy() for z in sampler.Z]
            })

    # 3. Save
    os.makedirs('results', exist_ok=True)
    out_file = f'results/(rho0)posterior_{target}_50k.pkl'
    with open(out_file, 'wb') as f:
        pickle.dump(posterior_samples, f)
    
    print(f"\nPipeline Complete: Results saved to {out_file}")

if __name__ == "__main__":
    # You can now run them one by one

    #run_pipeline(target='total')
    #run_pipeline(target='urban')
    run_pipeline(target='rural')