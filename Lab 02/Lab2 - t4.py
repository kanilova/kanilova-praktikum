import random
import numpy as np

def generate_random_elliptic_cylinder():
    a = random.uniform(1, 10)
    b = random.uniform(1, 10)
    return a, b

def generate_random_plane():
    A = random.uniform(-10, 10)
    B = random.uniform(-10, 10)
    C = random.uniform(-10, 10)
    D = random.uniform(-50, 50)
    return A, B, C, D

def generate_random_line():
    x1, y1, z1 = [random.uniform(-50, 50) for _ in range(3)]
    x2, y2, z2 = [random.uniform(-50, 50) for _ in range(3)]
    return (x1, y1, z1), (x2, y2, z2)

def generate_random_point():
    x = random.uniform(-50, 50)
    y = random.uniform(-50, 50)
    z = random.uniform(-50, 50)
    return x, y, z

def is_point_on_elliptic_cylinder(a, b, x, y, z):
    return np.isclose((x / a)**2 + (y / b)**2, 1, atol=1e-6)

def is_plane_intersecting_cylinder(a, b, A, B, C, D):
    if C == 0:
        return False
    discriminant = B**2 - 4 * A * (C * D)
    return discriminant >= 0

def is_line_intersecting_cylinder(a, b, p1, p2):
    x1, y1, z1 = p1
    x2, y2, z2 = p2
    t = np.linspace(0, 1, 100)
    x = x1 + t * (x2 - x1)
    y = y1 + t * (y2 - y1)
    return any((xi / a)**2 + (yi / b)**2 <= 1 for xi, yi in zip(x, y))

# Генерация случайных параметров
a, b = generate_random_elliptic_cylinder()
A, B, C, D = generate_random_plane()
line_p1, line_p2 = generate_random_line()
x, y, z = generate_random_point()

# Проверка принадлежности точки цилиндру
point_belongs = is_point_on_elliptic_cylinder(a, b, x, y, z)

# Проверка пересечения плоскости и прямой с цилиндром
plane_intersects = is_plane_intersecting_cylinder(a, b, A, B, C, D)
line_intersects = is_line_intersecting_cylinder(a, b, line_p1, line_p2)

print(f"Параметры эллиптического цилиндра: (x/{a})^2 + (y/{b})^2 = 1")
print(f"Параметры плоскости: {A}x + {B}y + {C}z + {D} = 0")
print(f"Координаты точки на прямой: {line_p1} -> {line_p2}")
print(f"Точка: ({x}, {y}, {z})")
print(f"Точка принадлежит цилиндру: {point_belongs}")
print(f"Плоскость пересекает цилиндр: {plane_intersects}")
print(f"Прямая пересекает цилиндр: {line_intersects}")