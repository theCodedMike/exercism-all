#include "largest_series_product.h"
#include <stdexcept>

namespace largest_series_product {
    int to_digit(const char ch) {
        return ch - '0';
    }

    int span_product(const std::string &series, const int from, const int to) {
        int span_product = 1;
        for (auto i = from; i <= to; ++i)
            span_product *= to_digit(series[i]);
        return span_product;
    }

    int largest_product(const std::string &series, const int span) {
        const int size = static_cast<int>(series.size());
        if (span < 1 || size == 0 || span > size)
            throw std::domain_error("");

        int product = span_product(series, 0, span - 1);
        int largest_product = product;
        for (auto i = span; i < size; ++i) {
            if (!isdigit(series[i]))
                throw std::domain_error("");

            const int span_leftmost = to_digit(series[i - span]);
            product = (
                span_leftmost == 0
                ? span_product(series, i - span + 1, i - 1)
                : product / span_leftmost
                ) * to_digit(series[i]);

            largest_product = std::max(product, largest_product);
        }

        return largest_product;
    }

}  // namespace largest_series_product
