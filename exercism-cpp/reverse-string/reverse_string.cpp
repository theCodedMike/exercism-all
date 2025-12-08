#include "reverse_string.h"

namespace reverse_string {

    std::string reverse_string(std::string str) {
        auto [i, j] =
            std::make_pair(0, static_cast<int>(str.size()) - 1);

        while (i < j) {
            std::swap(str[i], str[j]);
            i++;
            j--;
        }

        return str;
    }

}  // namespace reverse_string
