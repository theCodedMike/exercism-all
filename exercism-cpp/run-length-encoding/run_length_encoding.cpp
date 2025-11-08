#include "run_length_encoding.h"

namespace run_length_encoding {

    std::string encode(const std::string_view input) {
        std::string result;
        int count = 1;

        for (std::size_t i = 1, size = input.size(); i <= size; ++i) {
            if (i == size || input[i] != input[i - 1]) {
                if (count > 1)
                    result += std::to_string(count);
                result.push_back(input[i - 1]);
                count = 1;
            } else
                ++count;
        }

        return result;
    }

    std::string decode(const std::string &input) {
        std::string result;
        int count = 0;

        for (std::size_t i = 0; i < input.size(); ++i) {
            if (isdigit(input[i]))
                ++count;
            else {
                const int num = count == 0 ? 1 : std::stoi(input.substr(i - count, count));
                result.append(num, input[i]);
                count = 0;
            }
        }

        return result;
    }

}  // namespace run_length_encoding
