import math

EPS = 1e-6

def func(x):
    return math.exp(-x) - math.sqrt(x - 1)

def func_derivative(x):
    return -math.exp(-x) - 1 / (2 * math.sqrt(x - 1))

# Метод хорд (секущих)
def secant_method(x0, x1):
    f0 = func(x0)
    f1 = func(x1)
    while abs(x1 - x0) > EPS:
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0)
        x0 = x1
        f0 = f1
        x1 = x2
        f1 = func(x1)
    return x1

# Метод дихотомии (бисекции)
def bisection_method(a, b):
    while abs(b - a) > EPS:
        c = (a + b) / 2
        if func(c) == 0.0:
            return c
        elif func(c) * func(a) < 0:
            b = c
        else:
            a = c
    return c

# Метод простой итерации
def iteration_method(x0):
    x1 = 0
    while True:
        x1 = math.exp(-x0) + 1
        if abs(x1 - x0) < EPS:
            break
        x0 = x1
    return x1

# Метод Ньютона (касательных)
def newton_method(x0):
    while True:
        x1 = x0 - func(x0) / func_derivative(x0)
        if abs(x1 - x0) < EPS:
            break
        x0 = x1
    return x1


x0 = 1.1  # Начальная точка для методов Ньютона и простой итерации
a, b = 1.1, 1.5  # Интервал для методов хорд и дихотомии

print("Secant Method:", secant_method(a, b))
print("Bisection Method:", bisection_method(a, b))
print("Iteration Method:", iteration_method(x0))
print("Newton Method:", newton_method(x0))
