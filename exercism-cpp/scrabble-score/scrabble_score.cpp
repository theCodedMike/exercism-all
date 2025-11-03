#include "scrabble_score.h"
#include <numeric>
#include <unordered_map>

namespace scrabble_score {
    int score(const std::string &letters) {
        std::unordered_map<char, int> letter_score = {
            {'A', 1},{'E', 1},{'I', 1},{'O', 1},
            {'U', 1},{'L', 1},{'N', 1},{'R', 1},
            {'S', 1},{'T', 1},
            {'D', 2},{'G', 2},
            {'B', 3},{'C', 3},{'M', 3},{'P', 3},
            {'F', 4},{'H', 4},{'V', 4},{'W', 4},
            {'Y', 4},
            {'K', 5},
            {'J', 8},{'X', 8},
            {'Q', 10},{'Z', 10},
        };

        return std::accumulate(letters.cbegin(), letters.cend(), 0, [&letter_score](int score, char letter) {
            score += letter_score[toupper(letter)];

            return score;
        });
    }
} // namespace scrabble_score
