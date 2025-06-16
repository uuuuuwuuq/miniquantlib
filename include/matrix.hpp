#ifndef MINIQUANTLIB_MATRIX_HPP
#define MINIQUANTLIB_MATRIX_HPP

#include <vector>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "vector.hpp"

namespace mql {

template<typename T>
class Matrix {
private:
    size_t rows_, cols_;
    std::vector<T> data_; // row-major order

public:
    // Constructors
    Matrix() : rows_(0), cols_(0) {}

    Matrix(size_t rows, size_t cols, T init = T())
        : rows_(rows), cols_(cols), data_(rows * cols, init) {}

    // Access
    T& operator()(size_t i, size_t j) {
        assert(i < rows_ && j < cols_);
        return data_[i * cols_ + j];
    }

    const T& operator()(size_t i, size_t j) const {
        assert(i < rows_ && j < cols_);
        return data_[i * cols_ + j];
    }

    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }

    // Matrix + Matrix
    Matrix<T> operator+(const Matrix<T>& other) const {
        assert(rows_ == other.rows_ && cols_ == other.cols_);
        Matrix<T> result(rows_, cols_);
        for (size_t i = 0; i < data_.size(); ++i)
            result.data_[i] = data_[i] + other.data_[i];
        return result;
    }

    // Scalar multiplication
    Matrix<T> operator*(T scalar) const {
        Matrix<T> result(rows_, cols_);
        for (size_t i = 0; i < data_.size(); ++i)
            result.data_[i] = data_[i] * scalar;
        return result;
    }

    // Matrix * Vector
    Vector<T> operator*(const Vector<T>& vec) const {
        assert(cols_ == vec.size());
        Vector<T> result(rows_);
        for (size_t i = 0; i < rows_; ++i) {
            T sum = T();
            for (size_t j = 0; j < cols_; ++j)
                sum += (*this)(i, j) * vec[j];
            result[i] = sum;
        }
        return result;
    }

    // Transpose
    Matrix<T> transpose() const {
        Matrix<T> result(cols_, rows_);
        for (size_t i = 0; i < rows_; ++i)
            for (size_t j = 0; j < cols_; ++j)
                result(j, i) = (*this)(i, j);
        return result;
    }

    // Output
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
        for (size_t i = 0; i < mat.rows_; ++i) {
            os << "[ ";
            for (size_t j = 0; j < mat.cols_; ++j) {
                os << std::setw(8) << mat(i, j) << " ";
            }
            os << "]\n";
        }
        return os;
    }
};

} // namespace mql

#endif // MINIQUANTLIB_MATRIX_HPP
