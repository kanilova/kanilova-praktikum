#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для вычисления интерполяционного многочлена Лагранжа
double lagrange_interpolation(vector<double>& x, vector<double>& y, double xi) {
    double result = 0.0;
    int n = x.size();

    for (int i = 0; i < n; ++i) {
        double term = y[i];
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

// Функция для вычисления погрешности интерполяции в точке xi
double interpolation_error(double yi, double yi_interpolated) {
    return abs(yi - yi_interpolated);
}

int main() {
    // Заданные значения функции y_i = sin(x_i)
    vector<double> x = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
    vector<double> y;
    for (double xi : x) {
        y.push_back(sin(xi));
    }

    // Вычисление значения интерполяционного многочлена Лагранжа в точке x = 0.25pi
    double xi = 0.25 * M_PI;
    double yi_interpolated = lagrange_interpolation(x, y, xi);
    cout << "Интерполяционное значение в точке x = 0.25pi: " << yi_interpolated << endl;

    // Вычисление значения функции в точке x = 0.25pi
    double yi = sin(xi);

    // Вычисление погрешности интерполяции в точке x = 0.25pi
    double error = interpolation_error(yi, yi_interpolated);
    cout << "Погрешность интерполяции в точке x = 0.25pi: " << error << endl;

    return 0;
}
