#include <iostream>
#include <vector>

using namespace std;

// Решение СЛАУ методом прогонки
vector<double> thomas_algorithm(vector<vector<double>>& A, vector<double>& B) {
    int n = B.size();

    // Прямой ход
    for (int i = 1; i < n; ++i) {
        double m = A[i][i-1] / A[i-1][i-1];
        A[i][i] -= m * A[i-1][i];
        B[i] -= m * B[i-1];
    }

    // Обратный ход
    vector<double> X(n);
    X[n-1] = B[n-1] / A[n-1][n-1];
    for (int i = n-2; i >= 0; --i) {
        X[i] = (B[i] - A[i][i+1] * X[i+1]) / A[i][i];
    }

    return X;
}

int main() {
    vector<vector<double>> A = {{-8, 4, 0, 0, 0},
                                 {-5, 22, -8, 0, 0},
                                 {0, -5, -11, 1, 0},
                                 {0, 0, -9, -15, 1},
                                 {0, 0, 0, 1, 7}};
    vector<double> B = {48, 125, -43, 18, -23};

    vector<double> X = thomas_algorithm(A, B);

    cout << "Решение методом прогонки:" << endl;
    for (int i = 0; i < X.size(); ++i) {
        cout << "x_" << i+1 << " = " << X[i] << endl;
    }

    return 0;
}
