#ifndef MINIQUANTLIB_UTILS_HPP
#define MINIQUANTLIB_UTILS_HPP

#include <random>

namespace mql {

    // Generate random floating-point number in [low, high)
    inline double random_double(double low = 0.0, double high = 1.0) {
        static std::mt19937 rng(std::random_device{}());
        std::uniform_real_distribution<double> dist(low, high);
        return dist(rng);
    }

} // namespace mql

#endif // MINIQUANTLIB_UTILS_HPP