#pragma once
#include <string>

namespace phone_number {
    class phone_number {
    public:
        explicit phone_number(const std::string &);

        [[nodiscard]]
        const std::string & number() const;

    private:
        std::string valid_number;
    };
}  // namespace phone_number
