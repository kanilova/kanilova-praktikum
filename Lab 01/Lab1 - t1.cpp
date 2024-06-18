#include <iostream>
#include <cmath>
#include <vector>

int main() {
    // Определяем комплексные числа
    std::pair<double, double> z1 = {1, 1};  // 1 + i
    std::pair<double, double> z2 = {3, -1};  // 3 - i

    // Сложение
    std::pair<double, double> sum_z = {z1.first + z2.first, z1.second + z2.second};

    // Вычитание
    std::pair<double, double> diff_z = {z1.first - z2.first, z1.second - z2.second};

    // Умножение
    std::pair<double, double> prod_z = {z1.first * z2.first - z1.second * z2.second, z1.first * z2.second + z1.second * z2.first};

    // Деление
    std::pair<double, double> numerator = {z1.first * z2.first + z1.second * z2.second, z1.second * z2.first - z1.first * z2.second};
    double denominator = pow(z2.first, 2) + pow(z2.second, 2);
    std::pair<double, double> quot_z = {numerator.first / denominator, numerator.second / denominator};

    // Четвертая степень и корень третей степени для -1 + i
    std::pair<double, double> z3 = {-1, 1};

    // Четвертая степень
    double r = sqrt(pow(z3.first, 2) + pow(z3.second, 2));
    double theta = atan2(z3.second, z3.first);
    double r4 = pow(r, 4);
    double theta4 = 4 * theta;
    std::pair<double, double> z3_fourth_power = {r4 * cos(theta4), r4 * sin(theta4)};

    // Корень третей степени (для трех корней)
    double r3 = pow(r, 1.0/3);
    std::vector<std::pair<double, double>> z3_cube_roots;
    for (int k = 0; k < 3; k++) {
        double theta3 = (theta + 2 * M_PI * k) / 3;
        z3_cube_roots.push_back({r3 * cos(theta3), r3 * sin(theta3)});
    }

    // Выводим результаты
    std::cout << "Сложение: " << sum_z.first << " + " << sum_z.second << "i" << std::endl;
    std::cout << "Вычетание: " << diff_z.first << " + " << diff_z.second << "i" << std::endl;
    std::cout << "Умножение: " << prod_z.first << " + " << prod_z.second << "i" << std::endl;
    std::cout << "Деление: " << quot_z.first << " + " << quot_z.second << "i" << std::endl;
    std::cout << "Четвертая степень -1+i: " << z3_fourth_power.first << " + " << z3_fourth_power.second << "i" << std::endl;
    std::cout << "Корень третей степени -1+i:" << std::endl;
    for (const auto& root : z3_cube_roots) {
        std::cout << root.first << " + " << root.second << "i" << std::endl;
    }

    return 0;
}
