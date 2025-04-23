//alizalazar9@gmail.com

#include "SquareMat.hpp"
#include <cmath> // for std::fmod


namespace MatrixNS {

// Default constructor
SquareMat::SquareMat() : size(0), data(nullptr) {}

// Constructor with size
SquareMat::SquareMat(int n) : size(n) {
    if (n <= 0) {
        throw std::invalid_argument("Matrix size must be positive.");
    }
    allocateMatrix(n);
}

// Copy constructor
SquareMat::SquareMat(const SquareMat& other) {
    copyFrom(other);
}

// Destructor
SquareMat::~SquareMat() {
    deallocateMatrix();
}

// Assignment operator
SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this == &other) {
        return *this;
    }
    deallocateMatrix();
    copyFrom(other);
    return *this;
}

// Accessor
int SquareMat::getSize() const {
    return size;
}

// Allocate memory for NxN matrix
void SquareMat::allocateMatrix(int n) {
    data = new double*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            data[i][j] = 0.0; // Initialize to zero
        }
    }
}

// Free memory
void SquareMat::deallocateMatrix() {
    if (data != nullptr) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
    size = 0;
}

// Deep copy
void SquareMat::copyFrom(const SquareMat& other) {
    size = other.size;
    allocateMatrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Access operator (non-const)
double* SquareMat::operator[](int row) {
    if (row < 0 || row >= size) {
        throw std::out_of_range("Row index out of bounds");
    }
    return data[row];
}

// Access operator (const version)
const double* SquareMat::operator[](int row) const {
    if (row < 0 || row >= size) {
        throw std::out_of_range("Row index out of bounds");
    }
    return data[row];
}

std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.getSize(); ++i) {
        os << "[ ";
        for (int j = 0; j < mat.getSize(); ++j) {
            os << mat[i][j] << " ";
        }
        os << "]" << std::endl;
    }
    return os;
}

SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrix sizes do not match for addition.");
    }

    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double val = data[i][j];
            result[i][j] = (val == 0.0) ? 0.0 : -val;
        }
    }
    return result;
}

SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrix sizes do not match for subtraction.");
    }

    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;
}

SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrix sizes must match for multiplication.");
    }

    SquareMat result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0.0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrix sizes must match for element-wise multiplication.");
    }

    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] * other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Modulo by zero is not allowed.");
    }

    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = std::fmod(data[i][j], static_cast<double>(scalar));
        }
    }
    return result;
}

SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0.0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

SquareMat SquareMat::operator^(int power) const {
    if (power < 0) {
        throw std::invalid_argument("Negative powers not supported.");
    }

    SquareMat result(size);
    SquareMat base(*this); // make a copy of current matrix

    // Create identity matrix
    for (int i = 0; i < size; ++i) {
        result[i][i] = 1.0;
    }

    for (int p = 0; p < power; ++p) {
        result = result * base;
    }

    return result;
}

// Prefix ++
SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] += 1.0;
    return *this;
}

// Prefix --
SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] -= 1.0;
    return *this;
}

// Postfix ++
SquareMat SquareMat::operator++(int) {
    SquareMat temp = *this;
    ++(*this);
    return temp;
}

// Postfix --
SquareMat SquareMat::operator--(int) {
    SquareMat temp = *this;
    --(*this);
    return temp;
}
SquareMat SquareMat::operator~() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[j][i];
    return result;
}
double SquareMat::operator!() const {
    return computeDeterminant(data, size);
}

double SquareMat::computeDeterminant(double** mat, int n) const {
    if (n == 1) return mat[0][0];
    if (n == 2) return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];

    double det = 0.0;
    double** temp = new double*[n];
    for (int i = 0; i < n; ++i) temp[i] = new double[n];

    for (int p = 0; p < n; ++p) {
        int subi = 0;
        for (int i = 1; i < n; ++i) {
            int subj = 0;
            for (int j = 0; j < n; ++j) {
                if (j == p) continue;
                temp[subi][subj++] = mat[i][j];
            }
            subi++;
        }
        double sign = (p % 2 == 0) ? 1.0 : -1.0;
        det += sign * mat[0][p] * computeDeterminant(temp, n - 1);
    }

    for (int i = 0; i < n; ++i) delete[] temp[i];
    delete[] temp;

    return det;
}

double SquareMat::sum() const {
    double total = 0.0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            total += data[i][j];
    return total;
}
bool SquareMat::operator==(const SquareMat& other) const {
    return sum() == other.sum();
}

bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

bool SquareMat::operator<(const SquareMat& other) const {
    return sum() < other.sum();
}

bool SquareMat::operator>(const SquareMat& other) const {
    return sum() > other.sum();
}

bool SquareMat::operator<=(const SquareMat& other) const {
    return sum() <= other.sum();
}

bool SquareMat::operator>=(const SquareMat& other) const {
    return sum() >= other.sum();
}
// +=
SquareMat& SquareMat::operator+=(const SquareMat& other) {
    *this = *this + other;
    return *this;
}

// -=
SquareMat& SquareMat::operator-=(const SquareMat& other) {
    *this = *this - other;
    return *this;
}

// *= (element-wise)
SquareMat& SquareMat::operator*=(const SquareMat& other) {
    *this = *this % other;
    return *this;
}

// *= (scalar)
SquareMat& SquareMat::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}

// /=
SquareMat& SquareMat::operator/=(double scalar) {
    *this = *this / scalar;
    return *this;
}

// %= (element-wise)
SquareMat& SquareMat::operator%=(const SquareMat& other) {
    *this = *this % other;
    return *this;
}

// %= (scalar)
SquareMat& SquareMat::operator%=(int scalar) {
    *this = *this % scalar;
    return *this;
}


} // namespace MatrixNS
