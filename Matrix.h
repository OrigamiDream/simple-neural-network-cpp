//
// Created by OrigamiDream on 2019-01-03.
//

#pragma once

#include <functional>
#include "Global.h"

class Matrix {

    // Capsules
private:
    vMatrix d_matrix;

public:
    explicit Matrix(Long x, Long y);

    explicit Matrix(vMatrix matrix);

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

    Matrix transpose();

    Matrix scalar(Matrix other);

    Matrix apply(std::function<double(double)> fn);

};