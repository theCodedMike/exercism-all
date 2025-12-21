#pragma once

#include <vector>

namespace arcade {
    class HighScores {
    public:
        explicit HighScores(const std::vector<int> &scores)
            : scores(scores) {
        }

        [[nodiscard]]
        const std::vector<int> &list_scores() const;

        [[nodiscard]]
        int latest_score() const;

        int personal_best() const; // NOLINT(*-use-nodiscard)

        std::vector<int> top_three() const; // NOLINT(*-use-nodiscard)

    private:
        std::vector<int> scores;
    };
} // namespace arcade
