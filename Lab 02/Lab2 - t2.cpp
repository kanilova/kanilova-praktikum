#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Vector3D {
    double x, y, z;

    Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    double dot(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3D cross(const Vector3D& other) const {
        return Vector3D(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    double mixed_product(const Vector3D& v2, const Vector3D& v3) const {
        return dot(v2.cross(v3));
    }

    bool is_parallel(const Vector3D& other) const {
        Vector3D cross_product = cross(other);
        return (cross_product.x == 0 && cross_product.y == 0 && cross_product.z == 0);
    }

    double angle_with(const Vector3D& other) const {
        double dot_product = dot(other);
        double lengths_mult = length() * other.length();
        return std::acos(dot_product / lengths_mult);
    }
};

void generate_random_vectors(Vector3D& v1, Vector3D& v2, Vector3D& v3) {
    std::srand(std::time(nullptr));
    v1 = Vector3D(std::rand() % 100 - 50, std::rand() % 100 - 50, std::rand() % 100 - 50);
    v2 = Vector3D(std::rand() % 100 - 50, std::rand() % 100 - 50, std::rand() % 100 - 50);
    v3 = Vector3D(std::rand() % 100 - 50, std::rand() % 100 - 50, std::rand() % 100 - 50);
}

bool are_coplanar(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3) {
    return v1.mixed_product(v2, v3) == 0;
}

int main() {
    Vector3D v1, v2, v3;
    generate_random_vectors(v1, v2, v3);

    std::cout << "Vector v1: (" << v1.x << ", " << v1.y << ", " << v1.z << ")\n";
    std::cout << "Vector v2: (" << v2.x << ", " << v2.y << ", " << v2.z << ")\n";
    std::cout << "Vector v3: (" << v3.x << ", " << v3.y << ", " << v3.z << ")\n";

    std::cout << "Lengths:\n";
    std::cout << "v1: " << v1.length() << "\n";
    std::cout << "v2: " << v2.length() << "\n";
    std::cout << "v3: " << v3.length() << "\n";

    std::cout << "Angles between vectors (in radians):\n";
    std::cout << "v1 and v2: " << v1.angle_with(v2) << "\n";
    std::cout << "v1 and v3: " << v1.angle_with(v3) << "\n";
    std::cout << "v2 and v3: " << v2.angle_with(v3) << "\n";

    std::cout << "Sum and difference of vectors:\n";
    Vector3D sum_v1_v2 = v1 + v2;
    Vector3D diff_v1_v2 = v1 - v2;
    std::cout << "v1 + v2: (" << sum_v1_v2.x << ", " << sum_v1_v2.y << ", " << sum_v1_v2.z << ")\n";
    std::cout << "v1 - v2: (" << diff_v1_v2.x << ", " << diff_v1_v2.y << ", " << diff_v1_v2.z << ")\n";

    Vector3D sum_v1_v3 = v1 + v3;
    Vector3D diff_v1_v3 = v1 - v3;
    std::cout << "v1 + v3: (" << sum_v1_v3.x << ", " << sum_v1_v3.y << ", " << sum_v1_v3.z << ")\n";
    std::cout << "v1 - v3: (" << diff_v1_v3.x << ", " << diff_v1_v3.y << ", " << diff_v1_v3.z << ")\n";

    Vector3D sum_v2_v3 = v2 + v3;
    Vector3D diff_v2_v3 = v2 - v3;
    std::cout << "v2 + v3: (" << sum_v2_v3.x << ", " << sum_v2_v3.y << ", " << sum_v2_v3.z << ")\n";
    std::cout << "v2 - v3: (" << diff_v2_v3.x << ", " << diff_v2_v3.y << ", " << diff_v2_v3.z << ")\n";

    std::cout << "Parallel check:\n";
    std::cout << "v1 and v2: " << (v1.is_parallel(v2) ? "Parallel" : "Not Parallel") << "\n";
    std::cout << "v1 and v3: " << (v1.is_parallel(v3) ? "Parallel" : "Not Parallel") << "\n";
    std::cout << "v2 and v3: " << (v2.is_parallel(v3) ? "Parallel" : "Not Parallel") << "\n";

    std::cout << "Coplanar check:\n";
    std::cout << "v1, v2, and v3: " << (are_coplanar(v1, v2, v3) ? "Coplanar" : "Not Coplanar") << "\n";

    std::cout << "Mixed product of v1, v2, and v3: " << v1.mixed_product(v2, v3) << "\n";

    return 0;
}
