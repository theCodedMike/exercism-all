#include "phone_number.h"
#include <stdexcept>

namespace phone_number {
    phone_number::phone_number(const std::string & input) {
        valid_number = "";
        for (const char ch: input) {
            switch (ch) {
                case ' ':
                case '(':
                case ')':
                case '-':
                case '.':
                case '+': continue;
                default: {
                    if (!isdigit(ch))
                        throw std::domain_error("");
                    valid_number.push_back(ch);
                }
            }
        }

        const auto size = valid_number.size();
        if (size != 10 && size != 11)
            throw std::domain_error("");
        if (size == 11) {
            if (valid_number[0] != '1')
                throw std::domain_error("");
            else
                valid_number.erase(0, 1);
        }
        if (valid_number[0] < '2' || valid_number[3] < '2')
            throw std::domain_error("");
    }

    const std::string &phone_number::number() const {
        return valid_number;
    }
}  // namespace phone_number
