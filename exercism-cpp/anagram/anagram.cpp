#include "anagram.h"
#include <algorithm>
#include <iostream>

namespace anagram {
    std::pair<std::string, std::string> convert(const std::string &word) {
        std::string lower = word;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

        std::string ordered = lower;
        std::sort(ordered.begin(), ordered.end());

        return std::make_pair(lower, ordered);
    }

    anagram::anagram(const std::string &word) {
        auto [result_lower, result_ordered] = convert(word);
        this->lower_word = std::move(result_lower);
        this->ordered_word = std::move(result_ordered);
    }

    std::vector<std::string> anagram::matches(std::vector<std::string> candidates) const {
        const auto remove_iter
                = std::remove_if(candidates.begin(), candidates.end(), [this](const std::string &candidate) {
                    auto [lower, ordered] = convert(candidate);
                    if (lower == lower_word)
                        return true;
                    return ordered_word != ordered;
                });
        candidates.erase(remove_iter, candidates.end());

        return candidates;
    }
} // namespace anagram
