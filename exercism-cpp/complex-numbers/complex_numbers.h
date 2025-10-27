#pragma once

namespace complex_numbers {
    class Complex {
    public:
        explicit Complex(double = 0, double = 0);

        [[nodiscard]]
        double real() const;
        [[nodiscard]]
        double imag() const;

        // +
        Complex operator+(const Complex &) const;
        // +
        Complex operator+(double) const;
        // -
        Complex operator-(const Complex &) const;
        // -
        Complex operator-(double) const;
        // *
        Complex operator*(const Complex &) const;
        // *
        Complex operator*(double) const;
        // /
        Complex operator/(const Complex &) const;
        // /
        Complex operator/(double) const;
        // conj
        [[nodiscard]] Complex conj() const;
        // abs
        [[nodiscard]] double abs() const;
        // exp
        [[nodiscard]] Complex exp() const;

    private:
        double real_part;
        double imag_part;
    };

    // +
    Complex operator+(double, const Complex &);
    // -
    Complex operator-(double, const Complex &);
    // -
    Complex operator*(double, const Complex &);
    // /
    Complex operator/(double, const Complex &);
}  // namespace complex_numbers

