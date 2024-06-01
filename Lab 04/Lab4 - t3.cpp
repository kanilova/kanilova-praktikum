#include <iostream>
#include <vector>
#include <cmath>

// Функция для вычисления новых значений переменных по методу Зейделя
std::vector<double> seidel(std::vector<std::vector<double>>& A, std::vector<double>& b, std::vector<double>& x0, double epsilon, int max_iter) {
    int n = A.size();
    std::vector<double> x(n, 0.0); // Инициализация x с нулями
    int iter = 0;
    double error = epsilon + 1;

    while (iter < max_iter && error > epsilon) {
        for (int i = 0; i < n; ++i) {
            double sum1 = 0.0;
            double sum2 = 0.0;
            for (int j = 0; j < i; ++j) {
                sum1 += A[i][j] * x[j];
            }
            for (int j = i + 1; j < n; ++j) {
                sum2 += A[i][j] * x0[j];
            }
            x[i] = (b[i] - sum1 - sum2) / A[i][i];
        }

        // Вычисление ошибки для критерия остановки
        error = 0.0;
        for (int i = 0; i < n; ++i) {
            error += std::abs(x[i] - x0[i]);
        }

        // Обновление значения x0 для следующей итерации
        x0 = x;
        iter++;
    }

    return x;
}

int main() {
    std::vector<std::vector<double>> A = {{20, 5, 7, 1},
                                           {-1, 13, 0, -7},
                                           {4, -6, 17, 5},
                                           {-9, 8, 4, -25}};
    std::vector<double> b = {-117, -1, 49, -21};
    std::vector<double> x0 = {0, 0, 0, 0}; // Начальное приближение
    double epsilon = 1e-6; // Точность
    int max_iter = 1000; // Максимальное количество итераций

    std::vector<double> solution = seidel(A, b, x0, epsilon, max_iter);

    // Вывод результатов
    std::cout << "Solution:\n";
    for (int i = 0; i < solution.size(); ++i) {
        std::cout << "x_" << i + 1 << " = " << solution[i] << std::endl;
    }

    return 0;
}
