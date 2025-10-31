#pragma once
#include <string>
#include <vector>

namespace anagram {
    class anagram {
    public:
        explicit anagram(const std::string &);

        [[nodiscard]]
        std::vector<std::string> matches(std::vector<std::string>) const;

    private:
        std::string lower_word;
        std::string ordered_word;
    };
}  // namespace anagram
