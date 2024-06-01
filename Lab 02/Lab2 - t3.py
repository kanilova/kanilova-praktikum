import random
import math

def generate_random_parabola():
    a = random.uniform(-10, 10)
    b = random.uniform(-10, 10)
    c = random.uniform(-10, 10)
    return a, b, c

def generate_random_point():
    x = random.uniform(-50, 50)
    y = random.uniform(-50, 50)
    return x, y

def is_point_on_parabola(a, b, c, x, y):
    return math.isclose(y, a * x**2 + b * x + c, abs_tol=1e-6)

def find_focus(a, b):
    h = -b / (2 * a)
    k = (4 * a * c - b**2 + 1) / (4 * a)
    return h, k + 1 / (4 * a)

def distance_directrix_focus(a):
    return 1 / (4 * abs(a))

# Генерация случайных параметров параболы и точки
a, b, c = generate_random_parabola()
x, y = generate_random_point()

# Проверка принадлежности точки параболе
belongs = is_point_on_parabola(a, b, c, x, y)

# Нахождение фокуса параболы
focus = find_focus(a, b)

# Расстояние от директрисы до фокуса
distance = distance_directrix_focus(a)

print(f"Параметры параболы: y = {a}x^2 + {b}x + {c}")
print(f"Точка: ({x}, {y})")
print(f"Точка принадлежит параболе: {belongs}")
print(f"Фокус параболы: {focus}")
print(f"Расстояние от директрисы до фокуса: {distance}")