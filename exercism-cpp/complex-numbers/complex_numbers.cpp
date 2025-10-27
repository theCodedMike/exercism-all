#include "complex_numbers.h"
#include <cmath>

namespace complex_numbers {
    Complex::Complex(const double real, const double imag)
        : real_part{real}, imag_part {imag} {}

    double Complex::real() const {
        return real_part;
    }
    double Complex::imag() const {
        return imag_part;
    }

    // z1 = a + b * i
    // z2 = c + d * i
    // (+) z1 + z2 = (a + c) + (b + d) * i
    Complex Complex::operator+(const Complex & rhs) const {
        return Complex{real_part + rhs.real_part, imag_part + rhs.imag_part};
    }
    Complex Complex::operator+(const double const_num) const {
        return Complex{real_part + const_num, imag_part};
    }
    // (-) z1 - z2 = (a - c) + (b - d) * i
    Complex Complex::operator-(const Complex & rhs) const {
        return Complex{real_part - rhs.real_part, imag_part - rhs.imag_part};
    }
    Complex Complex::operator-(const double const_num) const {
        return Complex{real_part - const_num, imag_part};
    }
    // (*) z1 * z2 = (a * c - b * d) + (a * d + b * c) * i
    Complex Complex::operator*(const Complex & rhs) const {
        return Complex {
            real_part * rhs.real_part - imag_part * rhs.imag_part,
            real_part * rhs.imag_part + imag_part * rhs.real_part
        };
    }
    Complex Complex::operator*(const double const_num) const {
        return Complex{real_part * const_num, imag_part * const_num};
    }
    //               a * c + b * d     b * c - a * d
    // (/) z1 / z2 = -------------  +  ------------- * i
    //               c * c + d * d     c * c + d * d
    Complex Complex::operator/(const Complex & rhs) const {
        double base = rhs.real_part * rhs.real_part + rhs.imag_part * rhs.imag_part;
        return Complex {
            (real_part * rhs.real_part + imag_part * rhs.imag_part) / base,
            (imag_part * rhs.real_part - real_part * rhs.imag_part) / base
        };
    }
    Complex Complex::operator/(const double const_num) const {
        return Complex{real_part / const_num, imag_part / const_num};
    }
    // conj z1c = a - b * i
    Complex Complex::conj() const {
        return Complex {real_part, -imag_part};
    }
    // abs |z1| = sqrt(a^2 + b^2)
    double Complex::abs() const {
        return std::sqrt(real_part * real_part + imag_part * imag_part);
    }
    // exp e^z1 = e^a * (cos(b) + sin(b) * i)
    Complex Complex::exp() const {
        return Complex {
            std::exp(real_part) * std::cos(imag_part),
            std::exp(real_part) * std::sin(imag_part)
        };
    }

    // +
    Complex operator+(const double const_num, const Complex & rhs) {
        return rhs + const_num;
    }
    // -
    Complex operator-(const double const_num, const Complex & rhs) {
        return Complex{const_num - rhs.real(), -rhs.imag()};
    }
    // -
    Complex operator*(const double const_num, const Complex & rhs) {
        return rhs * const_num;
    }
    // /
    Complex operator/(const double const_num, const Complex & rhs) {
        double base = rhs.real() * rhs.real() + rhs.imag() * rhs.imag();
        return Complex {
            const_num * rhs.real() / base,
            -const_num * rhs.imag() / base
        };
    }

}  // namespace complex_numbers
