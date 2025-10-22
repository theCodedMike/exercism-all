#include "say.h"
#include <array>
#include <stdexcept>

namespace say {
    const std::array<std::string, 21> numbers = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
        "twenty"
    };
    const std::array<std::string, 10> tenths = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    std::string process_larger(const std::int64_t num, const int64_t base, const std::string& base_in_english) {
        auto res = in_english(num / base) + base_in_english;

        if (num % base != 0)
            res += " " + in_english(num % base);

        return res;
    }

    std::string in_english(std::int64_t num) {
        if (num < 0 || num > 999999999999)
            throw std::domain_error("Number out of range");

        std::string res;

        if (num <= 20)
            res = numbers[num];
        else if (num < 100)
            res = tenths[num / 10] + (num % 10 == 0 ? "" : "-" + numbers[num % 10]);
        else if (num < 1000)
            res = process_larger(num, 100, " hundred");
        else if (num < 1000000)
            res = process_larger(num, 1000, " thousand");
        else if (num < 1000000000)
            res = process_larger(num, 1000000, " million");
        else if (num < 1000000000000)
            res = process_larger(num, 1000000000, " billion");
        else
            throw std::domain_error("Number out of range");

        return res;
    }
} // namespace say
