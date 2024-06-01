#include <iostream>
#include <cmath>

double f1(double x) {
    return x * x * x * x / (7 + x * x);
}

double rectangle_method(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += f(a + i * h);
    }
    return result * h;
}

double trapezoidal_method(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        result += f(a + i * h);
    }
    return result * h;
}

double simpson_method(double (*f)(double), double a, double b, int n) {
    if (n % 2 != 0) {
        ++n; // n должен быть четным
    }
    double h = (b - a) / n;
    double result = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        result += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }
    return result * h / 3;
}

int main() {
    double a = 1.0, b = 2.0;
    int n = 1000; // Количество разбиений

    double result_rectangle = rectangle_method(f1, a, b, n);
    double result_trapezoidal = trapezoidal_method(f1, a, b, n);
    double result_simpson = simpson_method(f1, a, b, n);

    std::cout << "Method of Rectangles: " << result_rectangle << std::endl;
    std::cout << "Method of Trapezoids: " << result_trapezoidal << std::endl;
    std::cout << "Simpson's Method: " << result_simpson << std::endl;

    return 0;
}
