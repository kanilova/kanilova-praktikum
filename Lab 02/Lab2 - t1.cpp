#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Vector2D {
    double x, y;

    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    double length() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    double dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    bool is_parallel(const Vector2D& other) const {
        return (x * other.y == y * other.x);
    }

    double angle_with(const Vector2D& other) const {
        double dot_product = dot(other);
        double lengths_mult = length() * other.length();
        return std::acos(dot_product / lengths_mult);
    }
};

void generate_random_vectors(Vector2D& v1, Vector2D& v2, Vector2D& v3) {
    std::srand(std::time(nullptr));
    v1 = Vector2D(std::rand() % 100 - 50, std::rand() % 100 - 50);
    v2 = Vector2D(std::rand() % 100 - 50, std::rand() % 100 - 50);
    v3 = Vector2D(std::rand() % 100 - 50, std::rand() % 100 - 50);
}

int main() {
    Vector2D v1, v2, v3;
    generate_random_vectors(v1, v2, v3);

    std::cout << "Vector v1: (" << v1.x << ", " << v1.y << ")\n";
    std::cout << "Vector v2: (" << v2.x << ", " << v2.y << ")\n";
    std::cout << "Vector v3: (" << v3.x << ", " << v3.y << ")\n";

    std::cout << "Lengths:\n";
    std::cout << "v1: " << v1.length() << "\n";
    std::cout << "v2: " << v2.length() << "\n";
    std::cout << "v3: " << v3.length() << "\n";

    std::cout << "Angles between vectors (in radians):\n";
    std::cout << "v1 and v2: " << v1.angle_with(v2) << "\n";
    std::cout << "v1 and v3: " << v1.angle_with(v3) << "\n";
    std::cout << "v2 and v3: " << v2.angle_with(v3) << "\n";

    std::cout << "Sum and difference of vectors:\n";
    Vector2D sum_v1_v2 = v1 + v2;
    Vector2D diff_v1_v2 = v1 - v2;
    std::cout << "v1 + v2: (" << sum_v1_v2.x << ", " << sum_v1_v2.y << ")\n";
    std::cout << "v1 - v2: (" << diff_v1_v2.x << ", " << diff_v1_v2.y << ")\n";

    Vector2D sum_v1_v3 = v1 + v3;
    Vector2D diff_v1_v3 = v1 - v3;
    std::cout << "v1 + v3: (" << sum_v1_v3.x << ", " << sum_v1_v3.y << ")\n";
    std::cout << "v1 - v3: (" << diff_v1_v3.x << ", " << diff_v1_v3.y << ")\n";

    Vector2D sum_v2_v3 = v2 + v3;
    Vector2D diff_v2_v3 = v2 - v3;
    std::cout << "v2 + v3: (" << sum_v2_v3.x << ", " << sum_v2_v3.y << ")\n";
    std::cout << "v2 - v3: (" << diff_v2_v3.x << ", " << diff_v2_v3.y << ")\n";

    std::cout << "Parallel check:\n";
    std::cout << "v1 and v2: " << (v1.is_parallel(v2) ? "Parallel" : "Not Parallel") << "\n";
    std::cout << "v1 and v3: " << (v1.is_parallel(v3) ? "Parallel" : "Not Parallel") << "\n";
    std::cout << "v2 and v3: " << (v2.is_parallel(v3) ? "Parallel" : "Not Parallel") << "\n";

    return 0;
}
