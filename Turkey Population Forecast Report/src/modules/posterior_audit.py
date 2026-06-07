# posterior_audit.py

"""
This file is here to run statistics on the posterior samples calculated by the sampler.
"""

import pickle
import numpy as np
from project_constants import QUEEN_MATRIX, REGIONS

class PosteriorAuditor:
    def __init__(self, samples):
        self.samples = samples
        self.n_samples = len(samples)
        self.n_regions = len(REGIONS)

    def calculate_ess(self, chain):
        """
        Estimates Effective Sample Size. 
        Higher is better; low ESS means the thinning wasn't enough.
        """
        n = len(chain)
        if n < 2: return 0
        # Simple estimate based on autocorrelation at lag 1
        rho1 = np.corrcoef(chain[:-1], chain[1:])[0, 1]
        ess = n * (1 - rho1) / (1 + rho1)
        return max(1, ess)

    def print_statistical_audit(self, region_idx):
        region_name = REGIONS[region_idx]
        
        # Extract Chains
        intercept = np.array([s['beta'][region_idx][0] for s in self.samples])
        births = np.array([s['beta'][region_idx][1] for s in self.samples])
        sigmas = np.array([s['sigma'][region_idx] for s in self.samples])

        mean_b = np.mean(births)
        std_b = np.std(births)
        ci_95 = np.percentile(births, [2.5, 97.5])


        ess_b = self.calculate_ess(births)
        mcse = std_b / np.sqrt(ess_b) # Error in the mean due to sampling

        lag1 = np.corrcoef(births[:-1], births[1:])[0, 1]
        lag5 = np.corrcoef(births[:-5], births[5:])[0, 1] if len(births) > 5 else 0

        print(f"\nAUDIT REPORT: {region_name}")
        print(f"{'-'*40}")
        print(f"Post. Mean (Births): {mean_b:10.6f}")
        print(f"Post. SD:            {std_b:10.6f}")
        print(f"95% Credible Int:   [{ci_95[0]:.4f}, {ci_95[1]:.4f}]")
        print(f"{'-'*40}")
        print(f"Effective Sample Size (ESS): {ess_b:8.1f} / {self.n_samples}")
        print(f"MC Standard Error (MCSE):    {mcse:10.6f}")
        print(f"Autocorr Lag 1:              {lag1:10.4f}")
        print(f"Autocorr Lag 5:              {lag5:10.4f}")
        
        # Flagging Logic
        if lag1 > 0.5:
            print("WARNING: High Autocorrelation. Consider increasing thinning.")
        if ess_b < self.n_samples * 0.05:
            print("WARNING: Low ESS. Chain may not have explored enough.")
        print(f"{'-'*40}")

    def run_global_audit(self):
        """Summarizes the variance distribution across the whole country."""
        all_sigmas = np.array([s['sigma'] for s in self.samples])
        global_avg_sigma = np.mean(all_sigmas)
        global_std_sigma = np.std(all_sigmas)
        
        print("\n" + "="*50)
        print(f"GLOBAL SPATIAL AUDIT (N={self.n_regions} Regions)")
        print("="*50)
        print(f"Mean Spatial Variance (Sigma): {global_avg_sigma:.6f}")
        print(f"Variance Dispersion:           {global_std_sigma:.6f}")
        print("="*50)

# =================================================================
# EXECUTION
# =================================================================
if __name__ == "__main__":
    TARGET = 'rural' 
    PATH = f'src/results/posterior_{TARGET}_50k.pkl'
    
    with open(PATH, 'rb') as f:
        samples = pickle.load(f)
    
    auditor = PosteriorAuditor(samples)
    
    auditor.run_global_audit()
    
    for i in [10, 0, 5]:
        auditor.print_statistical_audit(i)
