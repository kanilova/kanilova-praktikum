import numpy as np

# Функция для вычисления первой производной методом конечных разностей
def first_derivative(x, y):
    n = len(x)
    dy_dx = np.zeros(n)

    for i in range(1, n-1):
        dy_dx[i] = (y[i+1] - y[i-1]) / (x[i+1] - x[i-1])

    # Вычисление первой производной на краевых точках
    dy_dx[0] = (y[1] - y[0]) / (x[1] - x[0])
    dy_dx[-1] = (y[-1] - y[-2]) / (x[-1] - x[-2])

    return dy_dx

# Функция для вычисления второй производной методом конечных разностей
def second_derivative(x, y):
    n = len(x)
    d2y_dx2 = np.zeros(n)

    for i in range(1, n-1):
        d2y_dx2[i] = (y[i+1] - 2 * y[i] + y[i-1]) / ((x[i+1] - x[i]) * (x[i] - x[i-1]))

    # Вычисление второй производной на краевых точках
    d2y_dx2[0] = (y[2] - 2 * y[1] + y[0]) / ((x[2] - x[1]) * (x[1] - x[0]))
    d2y_dx2[-1] = (y[-1] - 2 * y[-2] + y[-3]) / ((x[-1] - x[-2]) * (x[-2] - x[-3]))

    return d2y_dx2

# Заданные значения функции y_i
x = np.array([-1.0, 0.0, 1.0, 2.2, 3.0])
y = np.array([-0.5, 0.0, 0.5, 0.86603, 1.0])

# Точка, в которой вычисляем производные
x_point = 1.0

# Находим индекс ближайшей точки в таблице
index = np.argmin(np.abs(x - x_point))

# Вычисляем первую и вторую производные в точке x=1.0
first_derivatives = first_derivative(x, y)
second_derivatives = second_derivative(x, y)

print("Первая производная в точке x=1.0:", first_derivatives[index])
print("Вторая производная в точке x=1.0:", second_derivatives[index])
