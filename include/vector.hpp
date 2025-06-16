#ifndef MINIQUANTLIB_VECTOR_HPP
#define MINIQUANTLIB_VECTOR_HPP

#include <vector>
#include <cmath>
#include <cassert>
#include <initializer_list>
#include <iostream>

namespace mql {

template<typename T>
class Vector {
private:
    std::vector<T> data_;

public:
    // Constructors
    Vector() = default;

    explicit Vector(size_t size, T init = T()) : data_(size, init) {}

    Vector(std::initializer_list<T> init) : data_(init) {}

    // Access
    size_t size() const { return data_.size(); }

    T& operator[](size_t i) {
        assert(i < data_.size());
        return data_[i];
    }

    const T& operator[](size_t i) const {
        assert(i < data_.size());
        return data_[i];
    }

    // Arithmetic operations
    Vector<T> operator+(const Vector<T>& other) const {
        assert(size() == other.size());
        Vector<T> result(size());
        for (size_t i = 0; i < size(); ++i)
            result[i] = data_[i] + other[i];
        return result;
    }

    Vector<T> operator-(const Vector<T>& other) const {
        assert(size() == other.size());
        Vector<T> result(size());
        for (size_t i = 0; i < size(); ++i)
            result[i] = data_[i] - other[i];
        return result;
    }

    Vector<T> operator*(T scalar) const {
        Vector<T> result(size());
        for (size_t i = 0; i < size(); ++i)
            result[i] = data_[i] * scalar;
        return result;
    }

    // Dot product
    T dot(const Vector<T>& other) const {
        assert(size() == other.size());
        T result = T();
        for (size_t i = 0; i < size(); ++i)
            result += data_[i] * other[i];
        return result;
    }

    // Norm
    T norm() const {
        return std::sqrt(this->dot(*this));
    }

    // Sum
    T sum() const {
        T total = T();
        for (const auto& val : data_)
            total += val;
        return total;
    }

    // Output
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
        os << "[";
        for (size_t i = 0; i < v.size(); ++i) {
            os << v[i];
            if (i < v.size() - 1) os << ", ";
        }
        os << "]";
        return os;
    }
};

} // namespace mql

#endif // MINIQUANTLIB_VECTOR_HPP