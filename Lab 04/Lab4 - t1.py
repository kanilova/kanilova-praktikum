import numpy as np

# Метод обратной матрицы
def inverse_matrix(A, B):
    A_inv = np.linalg.inv(A)
    X = np.dot(A_inv, B)
    return X

# Метод Гаусса
def gaussian_elimination(A, B):
    n = len(B)
    
    # Прямой ход
    for i in range(n):
        for j in range(i+1, n):
            factor = A[j][i] / A[i][i]
            for k in range(n):
                A[j][k] -= factor * A[i][k]
            B[j] -= factor * B[i]
    
    # Обратный ход
    X = [0] * n
    for i in range(n-1, -1, -1):
        X[i] = (B[i] - sum(A[i][j] * X[j] for j in range(i+1, n))) / A[i][i]
    
    return X

# Коэффициенты системы уравнений
A = np.array([[3, -8, 1, -7],
              [6, 4, 8, 5],
              [-1, 1, -9, -3],
              [-6, 6, 9, -4]], dtype=float)

# Свободные члены
B = np.array([96, -13, -54, 82], dtype=float)

# Решение методом обратной матрицы
X_inv = inverse_matrix(A, B)
print("Решение методом обратной матрицы:")
print(X_inv)

# Решение методом Гаусса
X_gauss = gaussian_elimination(A.tolist(), B.tolist())
print("\nРешение методом Гаусса:")
print(X_gauss)
