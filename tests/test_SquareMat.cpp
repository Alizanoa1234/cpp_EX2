//alizalazar9@gmail
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/SquareMat.hpp"

using namespace MatrixNS;

TEST_CASE("Matrix construction and indexing") {
    SquareMat m(2);
    m[0][0] = 1.5;
    m[1][1] = 2.5;
    CHECK(m.getSize() == 2);
    CHECK(m[0][0] == 1.5);
    CHECK(m[1][1] == 2.5);
}

TEST_CASE("Copy constructor and assignment") {
    SquareMat m1(2);
    m1[0][1] = 4.0;
    SquareMat m2 = m1;
    CHECK(m2[0][1] == 4.0);

    SquareMat m3;
    m3 = m1;
    CHECK(m3[0][1] == 4.0);
}

TEST_CASE("Matrix addition and subtraction") {
    SquareMat a(2), b(2);
    a[0][0] = 1; b[0][0] = 2;
    SquareMat sum = a + b;
    CHECK(sum[0][0] == 3);

    SquareMat diff = b - a;
    CHECK(diff[0][0] == 1);
}

TEST_CASE("Matrix scalar operations") {
    SquareMat a(2);
    a[0][0] = 3;
    SquareMat scaled = a * 2.0;
    CHECK(scaled[0][0] == 6.0);

    scaled = a / 3.0;
    CHECK(scaled[0][0] == 1.0);

    scaled = a % 2;
    CHECK(scaled[0][0] == 1.0);
}

TEST_CASE("Unary operators: transpose, negate, determinant") {
    SquareMat a(2);
    a[0][1] = 7;
    SquareMat t = ~a;
    CHECK(t[1][0] == 7);

    SquareMat neg = -a;
    CHECK(neg[0][1] == -7);

    SquareMat id(2);
    id[0][0] = 1; id[1][1] = 1;
    CHECK(!id == doctest::Approx(1.0));
}

TEST_CASE("Increment and decrement operators") {
    SquareMat a(2);
    ++a;
    CHECK(a[0][0] == 1);

    a--;
    CHECK(a[0][0] == 0);
}

TEST_CASE("Comparison operators") {
    SquareMat a(2), b(2);
    a[0][0] = 1;
    b[0][0] = 2;
    CHECK(a != b);
    CHECK(b > a);
}

TEST_CASE("Exception cases") {
    CHECK_THROWS(SquareMat(-3));
    SquareMat a(2), b(3);
    CHECK_THROWS(a + b);
    CHECK_THROWS(a % 0);
    CHECK_THROWS(a / 0.0);
}
