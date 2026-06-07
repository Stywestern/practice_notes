# gp_kernels.py

"""
Definition of main computation units like matern kernel, cov matrix 
"""

import numpy as np

def matern_kernel_15(h, phi):
    """
    Formula: (1 + sqrt(3)*h/phi) * exp(-sqrt(3)*h/phi)
    """

    h = np.abs(h)
    sqrt3_h_phi = np.sqrt(3) * h / phi
    return (1 + sqrt3_h_phi) * np.exp(-sqrt3_h_phi)

def compute_covariance_matrix(time_points, sigma_sq, phi, jitter=1e-6):
    """
    Formula: Gamma_i = sigma_i^2 * rho_i(h) + jitter*I
    """

    h_matrix = np.abs(np.subtract.outer(time_points, time_points))
    K = sigma_sq * matern_kernel_15(h_matrix, phi)
    return K + jitter * np.eye(len(time_points))

def compute_car_precision_matrix(W, rho_s=0.9):
    """
    Leroux-style CAR precision matrix (Q).
    Formula : Q = rho_s * (Graph Laplacian) + (1 - rho_s) * Identity
    """
    D = np.diag(np.sum(W, axis=1))
    I = np.eye(W.shape[0])
    
    return rho_s * (D - W) + (1 - rho_s) * I