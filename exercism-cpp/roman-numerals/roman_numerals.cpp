#include "roman_numerals.h"
#include <vector>

namespace roman_numerals {
    std::vector<std::pair<int, char> > numerals = {
        {1000, 'M'},
        {500, 'D'},
        {100, 'C'},
        {50, 'L'},
        {10, 'X'},
        {5, 'V'},
        {1, 'I'}
    };

    std::string convert(int num) {
        std::string result;

        for (size_t i = 0; i < numerals.size(); i += 2) {
            auto [base, symbol] = numerals[i];
            if (num >= base) {
                switch (int quo = num / base) {
                    case 0:
                    case 1:
                    case 2:
                    case 3: result.append(std::string(quo, symbol));
                        break;
                    case 4: result.push_back(symbol);
                        result.push_back(numerals[i - 1].second);
                        break;
                    case 9: result.push_back(symbol);
                        result.push_back(numerals[i - 2].second);
                        break;
                    case 5: result.push_back(numerals[i - 1].second);
                        break;
                    default: // 6 7 8
                        result.push_back(numerals[i - 1].second);
                        result.append(std::string(quo - 5, symbol));
                }
                num %= base;
            }
        }

        return result;
    }
} // namespace roman_numerals
