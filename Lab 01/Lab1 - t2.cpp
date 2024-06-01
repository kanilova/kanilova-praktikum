#include <iostream>
#include <cmath>

const double EPS = 1e-6;

double func(double x) {
    return exp(-x) - sqrt(x - 1);
}

double func_derivative(double x) {
    return -exp(-x) - 1 / (2 * sqrt(x - 1));
}

// Метод хорд (секущих)
double secant_method(double x0, double x1) {
    double f0 = func(x0);
    double f1 = func(x1);
    while (fabs(x1 - x0) > EPS) {
        double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = func(x1);
    }
    return x1;
}

// Метод дихотомии (бисекции)
double bisection_method(double a, double b) {
    double c;
    while (fabs(b - a) > EPS) {
        c = (a + b) / 2;
        if (func(c) == 0.0) break;
        else if (func(c) * func(a) < 0) b = c;
        else a = c;
    }
    return c;
}

// Метод простой итерации
double iteration_method(double x0) {
    double x1;
    do {
        x1 = exp(-x0) + 1; // Переписываем уравнение в форме x = g(x)
        if (fabs(x1 - x0) < EPS) break;
        x0 = x1;
    } while (true);
    return x1;
}

// Метод Ньютона (касательных)
double newton_method(double x0) {
    double x1;
    do {
        x1 = x0 - func(x0) / func_derivative(x0);
        if (fabs(x1 - x0) < EPS) break;
        x0 = x1;
    } while (true);
    return x1;
}

int main() {
    double x0 = 1.5; // Начальная точка для методов Ньютона и простой итерации
    double a = 1.5, b = 2.5; // Интервал для методов хорд и дихотомии

    std::cout << "Secant Method: " << secant_method(a, b) << std::endl;
    std::cout << "Bisection Method: " << bisection_method(a, b) << std::endl;
    std::cout << "Iteration Method: " << iteration_method(x0) << std::endl;
    std::cout << "Newton Method: " << newton_method(x0) << std::endl;

    return 0;
}