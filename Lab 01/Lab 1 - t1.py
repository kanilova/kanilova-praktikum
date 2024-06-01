import math

# Определяем комплексные числа
z1 = (1, 1)  # 1 + i
z2 = (3, -1)  # 3 - i

# Сложение
sum_z = (z1[0] + z2[0], z1[1] + z2[1])

# Вычитание
diff_z = (z1[0] - z2[0], z1[1] - z2[1])

# Умножение
prod_z = (z1[0] * z2[0] - z1[1] * z2[1], z1[0] * z2[1] + z1[1] * z2[0])

# Деление
numerator = (z1[0] * z2[0] + z1[1] * z2[1], z1[1] * z2[0] - z1[0] * z2[1])
denominator = z2[0]**2 + z2[1]**2
quot_z = (numerator[0] / denominator, numerator[1] / denominator)

# Четвертая степень и корень третьей степени для -1 + i
z3 = (-1, 1)

# Четвертая степень
r = math.sqrt(z3[0]**2 + z3[1]**2)
theta = math.atan2(z3[1], z3[0])
r4 = r**4
theta4 = 4 * theta
z3_fourth_power = (r4 * math.cos(theta4), r4 * math.sin(theta4))

# Корень третьей степени (для трех корней)
r3 = r**(1/3)
z3_cube_roots = []
for k in range(3):
    theta3 = (theta + 2 * math.pi * k) / 3
    z3_cube_roots.append((r3 * math.cos(theta3), r3 * math.sin(theta3)))

# Выводим результаты
print(f"Сумма: {sum_z[0]} + {sum_z[1]}i")
print(f"Разность: {diff_z[0]} + {diff_z[1]}i")
print(f"Произведение: {prod_z[0]} + {prod_z[1]}i")
print(f"Частное: {quot_z[0]} + {quot_z[1]}i")
print(f"Четвертая степень числа -1+i: {z3_fourth_power[0]} + {z3_fourth_power[1]}i")
print(f"Корни третьей степени из числа -1+i:")
for root in z3_cube_roots:
    print(f"{root[0]} + {root[1]}i")