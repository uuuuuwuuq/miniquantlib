#include <iostream>
#include "vector.hpp"
#include "matrix.hpp"
#include "utils.hpp"

int main() {
    using namespace mql;

    Vector<double> v1 = {1.0, 2.0, 3.0};
    Vector<double> v2 = {4.0, 5.0, 6.0};

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";
    std::cout << "v1 + v2 = " << (v1 + v2) << "\n";
    std::cout << "Dot product = " << v1.dot(v2) << "\n";
    std::cout << "Norm of v1 = " << v1.norm() << "\n";

    Matrix<double> A(2, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;

    std::cout << "Matrix A:\n" << A;

    Vector<double> x = {1.0, 0.0, -1.0};
    std::cout << "A * x = " << (A * x) << "\n";

    std::cout << "Transpose of A:\n" << A.transpose();

    std::cout << "Random double: " << random_double(10.0, 20.0) << "\n";

    return 0;
}
