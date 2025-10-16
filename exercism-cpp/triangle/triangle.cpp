#include "triangle.h"

#include <limits>
#include <stdexcept>

namespace triangle {
    // ==
    bool is_equal(const double lhs, const double rhs, const double epsilon = 1e-6) {
        const double diff = std::abs(lhs - rhs);
        const double max_abs = std::max(std::abs(lhs), std::abs(rhs));
        return diff <= epsilon * max_abs || diff < std::numeric_limits<double>::min();
    }

    // !=
    bool not_equal(const double lhs, const double rhs, const double epsilon = 1e-6) {
        return !is_equal(lhs, rhs, epsilon);
    }

    // <=
    bool is_less_or_equal(const double lhs, const double rhs, const double epsilon = 1e-6) {
        return lhs < rhs || is_equal(lhs, rhs, epsilon);
    }

    flavor kind(double a, double b, double c) {
        if (is_less_or_equal(a, 0) || is_less_or_equal(b, 0) || is_less_or_equal(b, 0))
            throw std::domain_error("illegal side length");
        if (is_less_or_equal(a + b, c) || is_less_or_equal(a + c, b) || is_less_or_equal(b + c, a))
            throw std::domain_error("illegal triangle");

        if (is_equal(a,b) && is_equal(b, c))
            return flavor::equilateral;

        if (not_equal(a, b) && not_equal(a, c) && not_equal(b, c))
            return flavor::scalene;

        return flavor::isosceles;
    }
}  // namespace triangle
