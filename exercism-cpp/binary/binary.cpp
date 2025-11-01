#include "binary.h"

namespace binary {
    int convert(const std::string & b_str) {
        int result = 0;
        auto bit_value = 1;

        for (auto i = static_cast<int>(b_str.size()) - 1; i >= 0; --i) {
            if (b_str[i] == '1')
                result += bit_value;
            else if (b_str[i] == '0') {
                // do nothing
            } else
                return 0;

            bit_value <<= 1;
        }

        return result;
    }
}  // namespace binary
