import numpy as np
from datetime import datetime
import matplotlib.pyplot as plt
from scipy.linalg import expm

from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister, transpile
from qiskit.circuit.library import UnitaryGate, QFT
from qiskit_aer import Aer


def build_hhl_circuit(clock_qubits, matrix_A, t_param, C_val, b_vector):
    """Builds a parameterized HHL circuit for a 2x2 matrix."""
    
    # 1. Setup Registers
    q_b = QuantumRegister(1, 'b_reg')
    q_c = QuantumRegister(clock_qubits, 'clock')
    q_a = QuantumRegister(1, 'ancilla')
    c_reg = ClassicalRegister(2, 'result')
    qc = QuantumCircuit(q_b, q_c, q_a, c_reg)

    # Normalize the vector so the sum of squares = 1
    b_norm = b_vector / np.linalg.norm(b_vector)
    qc.prepare_state(b_norm, q_b[0]) # This prepares the data qubit to represent a specific b

    qc.barrier(label="1: INIT")

    # 2. Preparation (Superposition)
    qc.h(q_c)

    qc.barrier(label="2: SUPERPOS")

    # 3. Phase Estimation (QPE)
    # Define the Unitary e^{iAt}
    u_matrix = UnitaryGate(expm(1j * matrix_A * t_param), label="U")
    
    for i in range(clock_qubits):
        u_power = UnitaryGate(expm(1j * matrix_A * t_param)).power(2**i)
        u_power.label = f"U^{2**i}" 
        controlled_u = u_power.control()
        
        qc.append(controlled_u, [q_c[i], *q_b])

    qc.barrier(label="3: KICKBACK")
    fig = qc.draw(output='mpl', fold=-1)
    fig.savefig("hhl_circuit_debug_upto3.png", transparent=True, dpi=300, bbox_inches='tight')

    # 4. Inverse QFT
    # Parametrized to match clock_qubits size
    qft_inv = QFT(num_qubits=clock_qubits, inverse=True, do_swaps=True).to_gate()
    qft_inv.name = "QFT†"
    qc.append(qft_inv, q_c)
    
    qc.barrier(label="4: TRANSLATE")

    # 5. Controlled Rotation (The Division Step)
    for state in range(1, 2**clock_qubits):
        angle = 2 * np.arcsin(C_val / state)
        
        custom_rot = QuantumCircuit(1)
        custom_rot.ry(angle, 0)
        
        rot_gate = custom_rot.to_gate(label=f"Rot({state})")
        controlled_rot = rot_gate.control(num_ctrl_qubits=clock_qubits, ctrl_state=state)
        
        qc.append(controlled_rot, [*q_c, q_a[0]])

    qc.barrier(label="5: INVERT")
    fig = qc.draw(output='mpl', fold=-1)
    fig.savefig("hhl_circuit_debug_upto5.png", transparent=True, dpi=300, bbox_inches='tight')

    # 6. Uncomputation (Reverse everything)
    qc.append(qft_inv.inverse(), q_c)
    qc.data[-1].operation.label = "QFT"
    for i in reversed(range(clock_qubits)):
        u_inv_labeled = u_matrix.power(2**i).inverse()
        u_inv_labeled.label = f"(U^{2**i})†" 
        controlled_u_inv = u_inv_labeled.control()
        qc.append(controlled_u_inv, [q_c[i], q_b[0]])
    
    qc.barrier(label="6: CLEAN")

    # 7. Final Measurement (b_reg -> 0, ancilla -> 1)
    qc.measure(q_b[0], c_reg[0])
    qc.measure(q_a[0], c_reg[1])

    qc.barrier(label="7: MEASURE")
    
    return qc

def run_simulation(qc, shots=4000):
    backend = Aer.get_backend('qasm_simulator')
    t_qc = transpile(qc, backend)
    return backend.run(t_qc, shots=shots).result().get_counts()

def analyze_complexity(qc):
    """Prints the gate count and depth of the circuit."""
    decomposed_qc = qc.decompose()
    
    # Get the dictionary of all operations
    ops = decomposed_qc.count_ops()
    
    # Calculate Total Gates, .size() gives the total number of gate applications
    total_gates = decomposed_qc.size() 
    depth = decomposed_qc.depth()
    
    print("\n" + "="*30)
    print("      RESOURCE SUMMARY")
    print("="*30)
    print(f"Total Gate Operations: {total_gates}")
    print(f"Longest Path (Depth):  {depth}")
    print("-"*30)
    print("Gate Breakdown:")
    for gate, count in ops.items():
        if gate not in ['barrier', 'measure']: # Optional: hide metadata
            print(f"  {gate.ljust(15)}: {count}")
    print("="*30 + "\n")

# --- Main Execution Block ---
if __name__ == "__main__":
    CLOCK_QUBITS = 2 # Increase this for higher resolution
    MATRIX_A = np.array([[1.5, 0.5], [0.5, 1.5]])
    B_VEC = [2, 3]
    T_PARAM = np.pi / 2
    C_VAL = 1.0

    print(f"[{datetime.now()}] Initializing HHL with {CLOCK_QUBITS} clock qubits...")
    
    hhl_qc = build_hhl_circuit(CLOCK_QUBITS, MATRIX_A, T_PARAM, C_VAL, B_VEC)
    
    # RUN SIMULATION
    backend = Aer.get_backend('qasm_simulator')
    t_qc = transpile(hhl_qc, backend)
    counts = backend.run(t_qc, shots=4000).result().get_counts()

    # POST-SELECTION
    solution_stats = {"|0> (x1)": 0, "|1> (x2)": 0}
    for bitstring, count in counts.items():
        if bitstring[0] == '1': # Ancilla is 1
            if bitstring[1] == '0': solution_stats["|0> (x1)"] += count
            else: solution_stats["|1> (x2)"] += count

    total_success = sum(solution_stats.values())
    print(f"Total Successes (Ancilla=1): {total_success}")
    if total_success > 0:
        print(f"Distribution for b={B_VEC}:")
        print(f"x1: {solution_stats['|0> (x1)']/total_success:.3f}")
        print(f"x2: {solution_stats['|1> (x2)']/total_success:.3f}")

    custom_style = {
        "name": "iqx", 
        "displaycolor": {
            "unitary": ("#fc8d59", "#FFFFFF"), 
            "qft": ("#6baed6", "#FFFFFF"), 
            "reset": ("#000000", "#FFFFFF"),
        },
        "fontsize": 14,
        "subfontsize": 10,
    }

    fig = hhl_qc.draw(
        output='mpl', 
        style=custom_style,
        fold=-1
    )

    # Save circuit, Increase DPI for clarity 
    fig.savefig("hhl_circuit_debug.png", transparent=True, dpi=300, bbox_inches='tight')
    plt.show()

    analyze_complexity(hhl_qc)