## run_comparison.py

import os
import numpy as np
import matplotlib.pyplot as plt
from qiskit import QuantumCircuit
from qiskit.compiler import transpile
from qiskit_aer import AerSimulator

# Import the 16-element flattened data generation routines
from modules.prepare_data import get_encoded_angles, get_encoded_amplitudes

def build_angle_circuit(angles):
    """Builds a 16-qubit parallel Ry/Rx rotation network holding the flattened matrix."""
    qc = QuantumCircuit(16)
    for i in range(16):
        qc.ry(angles[i], i)  # Ry matching the classroom blueprint convention
    return qc

def build_amplitude_circuit(normalized_amplitudes):
    """Builds a 4-qubit global superposition circuit holding all 16 features."""
    qc = QuantumCircuit(4)
    qc.initialize(normalized_amplitudes, range(4))
    return qc

def extract_metrics(transpiled_qc, name):
    """Extracts exact physical hardware resource metrics from transpiled layouts."""
    return {
        "Method": name,
        "Qubits": transpiled_qc.num_qubits,
        "Depth": transpiled_qc.depth(),
        "Total Gates": sum(transpiled_qc.count_ops().values())
    }

if __name__ == "__main__":
    print("--- Starting 16-Element Flattened Encoding Evaluation --- \n")
    os.makedirs('report/figures', exist_ok=True)
    
    # 1. Fetch 16-Element Data Vector Inputs
    angle_inputs = get_encoded_angles()
    amplitude_inputs = get_encoded_amplitudes()
    
    # 2. Construct Scaling Circuit Foundations
    angle_base_qc = build_angle_circuit(angle_inputs)
    amp_base_qc = build_amplitude_circuit(amplitude_inputs)
    
    # 3. Transpile Both Configurations to Universal Physical Gate Set
    PHYSICAL_BASIS = ['rx', 'ry', 'rz', 'cx']
    angle_qc = transpile(angle_base_qc, basis_gates=PHYSICAL_BASIS, optimization_level=1)
    amp_qc = transpile(amp_base_qc, basis_gates=PHYSICAL_BASIS, optimization_level=1)
    
    # 4. Extract Structural Resource Performance and Print Markdown Table
    angle_metrics = extract_metrics(angle_qc, "Angle Encoding (16 Qubits)")
    amp_metrics = extract_metrics(amp_qc, "Amplitude Encoding (4 Qubits)")
    
    print("| Encoding Method | Number of Qubits | Circuit Depth | Total Gate Count |")
    print("|---|---|---|---|")
    for m in [angle_metrics, amp_metrics]:
        print(f"| {m['Method']} | {m['Qubits']} | {m['Depth']} | {m['Total Gates']} |")
    print("\n" + "-"*60 + "\n")

    # 5. Generate and Save Publication Quality Circuit Graphs
    angle_img_path = 'report/figures/circuit_angle_mpl.png'
    amp_img_path = 'report/figures/circuit_amplitude_mpl.png'
    
    fig_angle = angle_qc.draw(output='mpl', scale=0.8)
    fig_angle.savefig(angle_img_path, dpi=300, bbox_inches='tight')
    plt.close(fig_angle)
    
    fig_amp = amp_qc.draw(output='mpl', scale=0.8)
    fig_amp.savefig(amp_img_path, dpi=300, bbox_inches='tight')
    plt.close(fig_amp)
    
    print(f"Exported 16-Qubit Angle Layout to: {angle_img_path}")
    print(f"Exported Transpiled 4-Qubit Amplitude Layout to: {amp_img_path}\n")

    # 6. Execute Statistical Measurement Simulations
    simulator = AerSimulator()
    shots = 4096
    
    angle_meas_qc = angle_qc.copy()
    angle_meas_qc.measure_all()
    amp_meas_qc = amp_qc.copy()
    amp_meas_qc.measure_all()
    
    angle_counts = simulator.run(angle_meas_qc, shots=shots).result().get_counts()
    amp_counts = simulator.run(amp_meas_qc, shots=shots).result().get_counts()
    
    angle_probs = {k: v / shots for k, v in angle_counts.items()}
    amp_probs = {k: v / shots for k, v in amp_counts.items()}
    
    # 7. Construct Cohesive Subplot Figure Architecture
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(11, 4.5))
    ax2.sharey(ax1)
    
    # Left Subplot: 16-Qubit Angle System Distribution
    # Sorted alphabetically by basis keys to map out the sparse probability space cleanly
    sorted_angle_keys = sorted(angle_probs.keys())
    sorted_angle_vals = [angle_probs[k] for k in sorted_angle_keys]
    
    ax1.bar(sorted_angle_keys, sorted_angle_vals, color='royalblue', alpha=0.85, width=1.0)
    ax1.set_title("Angle Encoding Probability Space (16 Qubits)")
    ax1.set_xlabel("Sparse Basis States $|q_{15}...q_0\\rangle$ (Labels Hidden for Clarity)")
    ax1.set_ylabel("Measured Probability")
    ax1.set_xticks([])  # Stripping labels prevents rendering clutter
    ax1.grid(axis='y', linestyle='--', alpha=0.5)
    
    # Right Subplot: 4-Qubit Amplitude System Distribution
    sorted_amp_keys = sorted(amp_probs.keys())
    sorted_amp_vals = [amp_probs[k] for k in sorted_amp_keys]
    
    ax2.bar(sorted_amp_keys, sorted_amp_vals, color='darkorange', alpha=0.85)
    ax2.set_title("Amplitude Encoding Probability Space (4 Qubits)")
    ax2.set_xlabel("Computational Basis States $|q_3q_2q_1q_0\\rangle$")
    ax2.tick_params(axis='x', rotation=70, labelsize=8)
    ax2.grid(axis='y', linestyle='--', alpha=0.5)
    
    plt.setp(ax2.get_yticklabels(), visible=False)
    plt.tight_layout()
    
    plot_path = 'report/figures/encoding_comparison_histogram.png'
    plt.savefig(plot_path, dpi=300)
    plt.close()
    print(f"Exported unified comparative histogram to: {plot_path}")