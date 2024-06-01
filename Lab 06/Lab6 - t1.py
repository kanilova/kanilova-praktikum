import numpy as np

def f(x):
    return np.exp(x[0]**2 + x[1]**2) + x[0] + 5*x[1]

def gradient_f(x):
    return np.array([2*x[0]*np.exp(x[0]**2 + x[1]**2) + 1, 2*x[1]*np.exp(x[0]**2 + x[1]**2) + 5])

def coordinate_descent(initial_point, max_iterations=1000, tolerance=1e-6):
    x = initial_point
    for iteration in range(max_iterations):
        prev_x = np.copy(x)
        for i in range(len(x)):
            # Update x[i] by minimizing f(x) along the i-th coordinate
            gradient_i = gradient_f(x)
            x[i] = np.argmin([lambda alpha: f(x - alpha * gradient_i)])
        if np.linalg.norm(x - prev_x) < tolerance:
            break
    return x, f(x)

# Example usage
initial_point = np.array([1.5, 0.5])
optimum, min_value = coordinate_descent(initial_point)
print("Optimal point:", optimum)
print("Minimum value:", min_value)
