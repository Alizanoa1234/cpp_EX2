//alizalazar9@gmail.com

#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>
#include <stdexcept>

namespace MatrixNS {

class SquareMat {
private:
    int size;           // Size of the square matrix (N x N)
    double** data;      // Pointer to a 2D array of doubles

    void allocateMatrix(int n);        // Helper for memory allocation
    void deallocateMatrix();           // Helper for memory cleanup
    void copyFrom(const SquareMat&);   // Helper for deep copy
    double computeDeterminant(double** mat, int n) const;
    double sum() const;

public:
    // Constructors and destructor
    SquareMat();                     // Default constructor
    SquareMat(int n);                // Construct empty NxN matrix
    SquareMat(const SquareMat&);     // Copy constructor
    ~SquareMat();                    // Destructor

    // Assignment
    SquareMat& operator=(const SquareMat&);

    // Accessors
    int getSize() const;

    // (More operators to come next steps)

    // Element access (read/write)
    double* operator[](int row);
    const double* operator[](int row) const;

    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-() const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator*(double scalar) const;
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator%(int scalar) const;
    SquareMat operator/(double scalar) const;
    SquareMat operator^(int power) const;
    SquareMat& operator++();    // ++mat
    SquareMat& operator--();    // --mat
    SquareMat operator++(int);  // mat++
    SquareMat operator--(int);  // mat--
    SquareMat operator~() const;
    double operator!() const;  // Determinant
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other); // element-wise
    SquareMat& operator*=(double scalar);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(const SquareMat& other); // element-wise
    SquareMat& operator%=(int scalar);             // scalar modulo

};

std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
SquareMat operator*(double scalar, const SquareMat& mat);


} // namespace MatrixNS

#endif // SQUAREMAT_HPP
