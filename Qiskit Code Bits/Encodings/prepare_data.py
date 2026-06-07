## prepare_data.py

import numpy as np

RAW_MATRIX = np.array([
    [0.2, 0.5, 0.7, 0.1],
    [0.9, 0.3, 0.4, 0.8],
    [0.6, 0.2, 0.1, 0.5],
    [0.7, 0.8, 0.3, 0.4]
])

MATRIX_MIN, MATRIX_MAX = np.min(RAW_MATRIX), np.max(RAW_MATRIX)
FLATTENED_DATA = RAW_MATRIX.flatten()

def get_encoded_angles(vector=FLATTENED_DATA):
    """Maps 16 features to individual rotation angles within a fixed [0, pi/2] boundary."""
    return ((vector - MATRIX_MIN) / (MATRIX_MAX - MATRIX_MIN)) * (np.pi / 2)

def get_encoded_amplitudes(vector=FLATTENED_DATA):
    """Normalizes the full 16-element vector structure to achieve a unit L2 norm constraint."""
    return vector / np.linalg.norm(vector)

if __name__ == "__main__":
    print("--- Flattened 16-Element Quantum Data Preparation ---")
    print(f"Dataset Parameters -> Global Min: {MATRIX_MIN}, Global Max: {MATRIX_MAX}\n")
    
    angle_output = get_encoded_angles()
    amplitude_output = get_encoded_amplitudes()
    
    print(f"16-Element Angle Encoded Vector (Radians):\n{np.round(angle_output, 4)}\n")
    print(f"16-Element Amplitude Encoded Vector (Coefficients):\n{np.round(amplitude_output, 4)}\n")
    print(f"Verification of Amplitude Unit Norm (Sum of Squares): {np.sum(amplitude_output**2):.4f}")