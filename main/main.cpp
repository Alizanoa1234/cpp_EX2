#include <iostream>
#include "../include/SquareMat.hpp"

using namespace MatrixNS;

int main() {
    try {
        SquareMat mat1(3);  // ← THIS LINE IS REQUIRED
        mat1[0][0] = 7.5;
        mat1[1][1] = -2.3;
        mat1[2][2] = 9.9;

        std::cout << "Matrix mat1:\n" << mat1;  // ← You're trying to print mat1 here

        SquareMat mat2(3);
        mat2[0][0] = 1.0;
        mat2[1][1] = 2.0;
        mat2[2][2] = 3.0;

        SquareMat sum = mat1 + mat2;
        std::cout << "Sum of mat1 + mat2:\n" << sum;

        SquareMat negated = -mat1;
        std::cout << "Negated mat1:\n" << negated;

        SquareMat diff = mat1 - mat2;
        std::cout << "Difference mat1 - mat2:\n" << diff;

        SquareMat scaled1 = mat1 * 2.0;
        SquareMat scaled2 = 2.0 * mat1;

        std::cout << "mat1 * 2.0:\n" << scaled1;
        std::cout << "2.0 * mat1:\n" << scaled2;

        SquareMat mat3 = mat1 * mat2;
        std::cout << "Product of mat1 * mat2:\n" << mat3;

        SquareMat elemwise = mat1 % mat2;
        std::cout << "Element-wise multiplication mat1 % mat2:\n" << elemwise;

        SquareMat modded = mat1 % 3;
        std::cout << "mat1 % 3:\n" << modded;

        SquareMat divided = mat1 / 2.0;
        std::cout << "mat1 / 2.0:\n" << divided;

        SquareMat exp = mat1 ^ 2;
        std::cout << "mat1 ^ 2:\n" << exp;

        std::cout << "Before ++mat1:\n" << mat1;
        ++mat1;
        std::cout << "After ++mat1:\n" << mat1;

        mat1--;
        std::cout << "After mat1--:\n" << mat1;

        SquareMat transposed = ~mat1;
        std::cout << "Transposed mat1:\n" << transposed;

        double det = !mat1;
        std::cout << "Determinant of mat1: " << det << std::endl;

        std::cout << "mat1 == mat2: " << (mat1 == mat2) << std::endl;
        std::cout << "mat1 != mat2: " << (mat1 != mat2) << std::endl;
        std::cout << "mat1 > mat2: " << (mat1 > mat2) << std::endl;

        mat1 += mat2;
        std::cout << "mat1 after += mat2:\n" << mat1;

        mat1 *= 2.0;
        std::cout << "mat1 after *= 2.0:\n" << mat1;

        mat1 %= 3;
        std::cout << "mat1 after %= 3:\n" << mat1;



    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    
    return 0;
}
