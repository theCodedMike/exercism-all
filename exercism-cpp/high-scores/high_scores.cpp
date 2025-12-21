#include "high_scores.h"
#include <algorithm>

namespace arcade {
    const std::vector<int> &HighScores::list_scores() const {
        return scores;
    }

    int HighScores::latest_score() const {
        return scores.back();
    }

    int HighScores::personal_best() const {
        return *std::max_element(scores.cbegin(), scores.cend());
    }

    std::vector<int> HighScores::top_three() const {
        std::vector<int> result(scores.size() < 3 ? scores.size() : 3);

        std::partial_sort_copy(scores.cbegin(), scores.cend(),
                               result.begin(), result.end(),
                               std::greater<>());

        return result;
    }
} // namespace arcade
