#include "say.h"
#include <array>
#include <stdexcept>

namespace say {
    std::string special_treat(const std::int64_t num) {
        switch (num)
        {
            case  1: return "one";
            case  2: return "two";
            case  3: return "three";
            case  4: return "four";
            case  5: return "five";
            case  6: return "six";
            case  7: return "seven";
            case  8: return "eight";
            case  9: return "nine";
            case 10: return "ten";
            case 11: return "eleven";
            case 12: return "twelve";
            case 13: return "thirteen";
            case 14: return "fourteen";
            case 15: return "fifteen";
            case 16: return "sixteen";
            case 17: return "seventeen";
            case 18: return "eighteen";
            case 19: return "nineteen";
            case 20: return "twenty";
            case 30: return "thirty";
            case 40: return "forty";
            case 50: return "fifty";
            case 60: return "sixty";
            case 70: return "seventy";
            case 80: return "eighty";
            case 90: return "ninety";
            case 100: return "hundred";
            default: return "";
        }
    }

    std::string in_english_1_to_999(std::int64_t num) {
        if (num <= 0 || num > 999)
            throw std::domain_error("Number out of range");

        std::string res;
        if (num >= 100) {
            res = special_treat(num / 100) + " hundred ";
            num %= 100;
        }
        if (num > 20) {
            res += special_treat(num - num % 10);
            num %= 10;
            res += num != 0 ? '-' : ' ';
        }
        if (num > 0)
            res += special_treat(num) + ' ';

        return res;
    }

    std::string in_english(std::int64_t num) {
        if (num < 0 || num > 999999999999)
            throw std::domain_error("Number out of range");

        if (num == 0)
            return "zero";

        constexpr std::array<std::pair<std::int64_t, const char *>, 4> number_sections = {{
                {1'000'000'000, "billion "},
                {1'000'000, "million "},
                {1'000, "thousand "},
                {1, ""}

        }};
        std::string res;

        for (const auto &[base, base_english]: number_sections) {
            if (num >= base) {
                res += in_english_1_to_999(num / base);
                res += base_english;
                num %= base;
            }
        }

        res.pop_back();
        return res;
    }
} // namespace say
