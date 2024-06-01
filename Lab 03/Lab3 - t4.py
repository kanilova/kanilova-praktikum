import math

def numerical_series_2(x, epsilon):
    sum_value = 0
    k = 1
    term = float("inf")
    while abs(term) > epsilon:
        term = ((-1)**k) / (math.sin(k * x) + 7 + k**2)
        sum_value += term
        k += 1
    return sum_value

epsilon = 1e-6
x = 1.0  # Выберите значение x для функции
result = numerical_series_2(x, epsilon)
print("Sum of the functional series:", result)
