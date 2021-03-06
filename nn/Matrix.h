#pragma once

#include <functional>
#include "Global.h"

class Matrix {

    // Capsules
private:
    vMatrix vActualMatrix;

public:
    explicit Matrix(Long x, Long y);

    explicit Matrix(vMatrix * matrix);

    Matrix(): vActualMatrix(0) {}

    // Basic matric methods
public:
    vMatrix getMatrix();

    Long xLength();

    Long yLength();

    Long yLength(Long index);

    void set(Long x, Long y, double value);

    // Operators
public:

    Matrix operator*(Matrix other);

    Matrix operator-(Matrix other);

    Matrix operator+(Matrix other);

    Matrix integrate(Matrix other);

    Matrix transpose();

    Matrix apply(std::function<double(double)> fn);

};