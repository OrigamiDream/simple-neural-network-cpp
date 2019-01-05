#include <iostream>
#include "Matrix.h"

Matrix::Matrix(Long x, Long y) {
    vActualMatrix = vMatrix(x);
    for(Long i = 0; i < x; i++) {
        vRow row(y);
        for(Long j = 0; j < y; j++) {
            row[j] = 0;
        }
        vActualMatrix[i] = row;
    }
}

Matrix::Matrix(vMatrix * matrix) {
    vActualMatrix = *matrix;
}

vMatrix Matrix::getMatrix() {
    return vActualMatrix;
}

Long Matrix::xLength() {
    return getMatrix().size();
}

Long Matrix::yLength() {
    return Matrix::yLength(0);
}

Long Matrix::yLength(Long index) {
    return getMatrix()[index].size();
}

void Matrix::set(Long x, Long y, double value) {
    vActualMatrix[x][y] = value;
}

Matrix Matrix::operator*(Matrix other) {
    if(this->xLength() == 0 || other.xLength() == 0 || yLength() != other.xLength()) {
        throw std::runtime_error("Requires same matrix");
    }

    Matrix result {xLength(), other.yLength()};
    for(Long i = 0; i < xLength(); i++) {
        for(Long j = 0; j < other.yLength(); j++) {
            double value = 0;
            for(Long h = 0; h < yLength(); h++) {
                value += getMatrix()[i][h] * other.getMatrix()[h][j];
            }
            result.set(i, j, value);
        }
    }
    return result;
}

Matrix Matrix::operator-(Matrix other) {
    if(xLength() == 0 || other.xLength() == 0 || xLength() != other.xLength() || yLength() != other.yLength()) {
        throw std::runtime_error("Requires same matrix");
    }

    Matrix result {xLength(), yLength()};
    for(Long i = 0; i < xLength(); i++) {
        for(Long j = 0; j < yLength(i); j++) {
            result.set(i, j, getMatrix()[i][j] - other.getMatrix()[i][j]);
        }
    }
    return result;
}

Matrix Matrix::operator+(Matrix other) {
    if(xLength() == 0 || other.xLength() == 0 || xLength() != other.xLength() || yLength() != other.yLength()) {
        throw std::runtime_error("Requires same matrix");
    }
    Matrix result {xLength(), yLength()};
    for(Long i = 0; i < xLength(); i++) {
        for(Long j = 0; j < yLength(); j++) {
            result.set(i, j, getMatrix()[i][j] + other.getMatrix()[i][j]);
        }
    }
    return result;
}

Matrix Matrix::transpose() {
    Matrix result {yLength(), xLength()};
    for(Long i = 0; i < xLength(); i++) {
        for(Long j = 0; j < yLength(i); j++) {
            result.set(j, i, getMatrix()[i][j]);
        }
    }
    return result;
}

Matrix Matrix::scalar(Matrix other) {
    if(xLength() != other.xLength()) {
        throw std::runtime_error("Requires same scalar vectors");
    }

    Matrix result {xLength(), yLength()};
    for(Long i = 0; i < xLength(); i++) {
        for(Long j = 0; j < yLength(i); j++) {
            result.set(i, j, getMatrix()[i][j] * other.getMatrix()[i][j]);
        }
    }
    return result;
}

Matrix Matrix::apply(std::function<double(double)> fn) {
    if(xLength() == 0 || yLength() == 0) {
        throw std::runtime_error("Invalid matrix");
    }

    Matrix result {xLength(), yLength()};
    for(Long i = 0; i < xLength(); i++) {
        for(Long j = 0; j < yLength(); j++) {
            result.set(i, j, fn(getMatrix()[i][j]));
        }
    }
    return result;
}
