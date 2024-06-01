import numpy as np

# Метод Крамера для решения системы линейных уравнений
def kramer_method(A, B):
    det_A = np.linalg.det(A)
    n = len(B)
    X = []

    for i in range(n):
        # Создаем копию матрицы A и заменяем i-ый столбец на столбец B
        Ai = A.copy()
        Ai[:, i] = B
        # Находим определитель новой матрицы и вычисляем соответствующее значение x_i
        det_Ai = np.linalg.det(Ai)
        X.append(det_Ai / det_A)

    return X

# Метод Якоби для решения системы линейных уравнений
def jacobi_method(A, B, eps=1e-10, max_iterations=1000):
    n = len(B)
    X = np.zeros(n)
    X_prev = np.zeros(n)
    iteration = 0

    while iteration < max_iterations:
        for i in range(n):
            sum_ = sum(A[i][j] * X_prev[j] for j in range(n) if j != i)
            X[i] = (B[i] - sum_) / A[i][i]

        if np.linalg.norm(X - X_prev) < eps:
            break

        X_prev = X.copy()
        iteration += 1

    return X

# Коэффициенты системы уравнений
A = np.array([[5, 2, -2],
              [3, -3, -1],
              [2, 3, -1]], dtype=float)

# Свободные члены
B = np.array([0, 1, -1], dtype=float)

# Решение методом Крамера
X_kramer = kramer_method(A, B)
print("Решение методом Крамера:")
print(X_kramer)

# Решение методом Якоби
X_jacobi = jacobi_method(A, B)
print("\nРешение методом Якоби:")
print(X_jacobi)
