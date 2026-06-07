import matplotlib.pyplot as plt

# 1. Define equation string (using raw string 'r' for LaTeX backslashes)
equation = r'$|\psi\rangle_{3} = \sum_{j=1}^{2} \beta_{j} |u_{j}\rangle_{D} \otimes \frac{1}{2} \left( \sum_{k=0}^{3} e^{i \lambda_{j} \frac{\pi}{2} k} |k\rangle_{C} \right) \otimes |0\rangle_{A}$'

eq_3b = r'$|\text{Clock}\rangle_{\lambda=2} = \frac{1}{2} \left( |00\rangle - |01\rangle + |10\rangle - |11\rangle \right)_C$'

eq_clock_expansion = r'$|\text{Clock}\rangle_{j} = \frac{1}{2} \left( |00\rangle + e^{i \lambda_j \frac{\pi}{2}} |01\rangle + e^{i 2 \lambda_j \frac{\pi}{2}} |10\rangle + e^{i 3 \lambda_j \frac{\pi}{2}} |11\rangle \right)_C$'

equation_5 = r'$|\psi\rangle_{5} = \sum_{j=1}^{2} \beta_j |u_j\rangle_D \otimes |\lambda_j\rangle_C \otimes \left( \sqrt{1 - \frac{C^2}{\lambda_j^2}} |0\rangle + \frac{C}{\lambda_j} |1\rangle \right)_A$'
eq_5a = r'$R_y(\theta_j)|0\rangle_A = \cos\left(\frac{\theta_j}{2}\right)|0\rangle + \sin\left(\frac{\theta_j}{2}\right)|1\rangle$'
eq_5b = r'$\theta_j = 2\arcsin\left(\frac{C}{\lambda_j}\right) $' 

eq_6 = r'$|\psi\rangle_{6} = \left( \sum_{j=1}^{2} \beta_j |u_j\rangle_D \otimes |0\rangle_C \otimes | \text{Rotated } \lambda_j \rangle_A \right)$'
eq_7 = r'$|x\rangle = \sum_{j=1}^{2} \beta_j \frac{C}{\lambda_j} |u_j\rangle_D \approx A^{-1}|b\rangle$'

# 2. Create a figure
fig = plt.figure(figsize=(10, 2))
plt.text(0.5, 0.5, eq_6 , size=20, ha='center', va='center')

# 3. Clean up the background and axes
plt.axis('off')

# 4. Save with transparency
# 'transparent=True' makes the figure background 0% alpha
# 'bbox_inches' removes the padding
plt.savefig("equation.png", transparent=True, bbox_inches='tight', dpi=300)

print("Equation saved as equation.png with a transparent background.")