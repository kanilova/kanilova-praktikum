def numerical_series_1(epsilon):
    sum_value = 0
    k = 1
    term = float("inf")
    while abs(term) > epsilon:
        term = 7 / (2**(k - 1)) + ((-1)**(k - 1)) / (2 * 3**(k - 1))
        sum_value += term
        k += 1
    return sum_value

epsilon = 1e-6
result = numerical_series_1(epsilon)
print("Sum of the numerical series:", result)
