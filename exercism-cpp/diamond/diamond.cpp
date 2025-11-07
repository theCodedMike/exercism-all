#include "diamond.h"
#include <stdexcept>

namespace diamond {
    std::vector<std::string> rows(char letter) {
        if (!isalpha(letter))
            throw std::invalid_argument("Invalid letter(A~Z)");
        letter = toupper(letter);

        std::vector<std::string> result;
        const auto size = (letter - 'A') * 2 + 1;
        for (auto i = 'A'; i <= letter; ++i) {
            std::string row(size, ' ');
            row[size / 2 + (i - 'A')] = i;
            row[size / 2 - (i - 'A')] = i;
            result.push_back(row);
        }
        for (auto i = size / 2 - 1; i >= 0; --i) {
            result.push_back(result[i]);
        }

        return result;
    }
}  // namespace diamond
