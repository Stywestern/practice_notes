import numpy as np
import matplotlib.pyplot as plt
from scipy.linalg import expm
from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.circuit.library import UnitaryGate, QFT
from qiskit_aer import Aer
from qiskit import transpile
from datetime import datetime

def analyze_complexity(qc):
    """Calculates and prints the total gate count and depth."""
    decomposed_qc = qc.decompose()
    ops = decomposed_qc.count_ops()
    total_gates = decomposed_qc.size() 
    depth = decomposed_qc.depth()
    
    print("\n" + "="*35)
    print("      QUANTUM RESOURCE REPORT")
    print("="*35)
    print(f"Total Operations: {total_gates}")
    print(f"Critical Path (Depth): {depth}")
    print("-" * 35)
    for gate, count in ops.items():
        if gate not in ['barrier', 'measure']:
            print(f"  {gate.ljust(20)}: {count}")
    print("="*35 + "\n")

def build_hhl_circuit(clock_qubits, matrix_A, t_param, C_val, b_vector):
    num_data_qubits = int(np.log2(len(b_vector)))

    # 1. Setup Registers
    q_b = QuantumRegister(num_data_qubits, 'b_reg')
    q_c = QuantumRegister(clock_qubits, 'clock')
    q_a = QuantumRegister(1, 'ancilla')
    # Use enough classical bits for data + 1 for ancilla
    c_reg = ClassicalRegister(num_data_qubits + 1, 'result')
    qc = QuantumCircuit(q_b, q_c, q_a, c_reg)

    # State Preparation
    b_norm = b_vector / np.linalg.norm(b_vector)
    qc.prepare_state(b_norm, q_b)
    qc.barrier(label="INIT")

    # 2 & 3. QPE
    qc.h(q_c)
    u_matrix = UnitaryGate(expm(1j * matrix_A * t_param))
    for i in range(clock_qubits):
        qc.append(u_matrix.power(2**i).control(), [q_c[i], *q_b])

    # 4. Inverse QFT
    qft_inv = QFT(num_qubits=clock_qubits, inverse=True, do_swaps=True).to_gate()
    qc.append(qft_inv, q_c)

    # 5. Controlled Rotation
    for state in range(1, 2**clock_qubits):
        angle = 2 * np.arcsin(C_val / state)
        custom_rot = QuantumCircuit(1)
        custom_rot.ry(angle, 0)
        controlled_rot = custom_rot.to_gate().control(num_ctrl_qubits=clock_qubits, ctrl_state=state)
        qc.append(controlled_rot, [*q_c, q_a[0]])

    # 6. Uncomputation
    qc.append(qft_inv.inverse(), q_c)
    for i in reversed(range(clock_qubits)):
        qc.append(u_matrix.power(2**i).inverse().control(), [q_c[i], *q_b])

    # 7. Measurement
    # Data qubits map to indices 0, 1...
    for i in range(num_data_qubits):
        qc.measure(q_b[i], c_reg[i])
    # Ancilla maps to the last index
    qc.measure(q_a[0], c_reg[num_data_qubits])
    
    return qc

if __name__ == "__main__":
    CLOCK_QUBITS = 2
    MATRIX_A = np.array([
    [1.2, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1],
    [0.1, 1.6, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1],
    [0.1, 0.1, 1.2, 0.1, 0.1, 0.1, 0.1, 0.1],
    [0.1, 0.1, 0.1, 1.6, 0.1, 0.1, 0.1, 0.1],
    [0.1, 0.1, 0.1, 0.1, 1.2, 0.1, 0.1, 0.1],
    [0.1, 0.1, 0.1, 0.1, 0.1, 1.6, 0.1, 0.1],
    [0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 1.2, 0.1],
    [0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 1.6]
])

    B_VEC = [2, 3, 4, 5, 6, 7, 8, 7]
    T_PARAM = np.pi / 2

    print(f"[{datetime.now()}] Starting Solo Dense 4x4 Analysis...")
    hhl_qc = build_hhl_circuit(CLOCK_QUBITS, MATRIX_A, T_PARAM, 1.0, B_VEC)
    
    # Analyze Resource Usage
    analyze_complexity(hhl_qc)

    # Run Simulation
    backend = Aer.get_backend('qasm_simulator')
    t_qc = transpile(hhl_qc, backend)
    counts = backend.run(t_qc, shots=4000).result().get_counts()

    # DYNAMIC POST-SELECTION FOR N-STATES
    solution_stats = {}
    num_data = int(np.log2(len(B_VEC)))
    
    for bitstring, count in counts.items():
        # Qiskit bitstrings are [ancilla, data_msb, ..., data_lsb]
        if bitstring[0] == '1': 
            label = f"|{bitstring[1:]}>"
            solution_stats[label] = solution_stats.get(label, 0) + count

    total_s = sum(solution_stats.values())
    print(f"Total Successes (Ancilla=1): {total_s}")
    if total_s > 0:
        for label in sorted(solution_stats.keys()):
            print(f"{label}: {solution_stats[label]/total_s:.3f}")

    hhl_qc.draw(output='mpl')
    plt.show()