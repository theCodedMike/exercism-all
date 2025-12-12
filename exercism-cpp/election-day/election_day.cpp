#include <string>
#include <vector>

namespace election {
    // The election result struct is already created for you:

    struct ElectionResult {
        // Name of the candidate
        std::string name{};
        // Number of votes the candidate has
        int votes{};
    };

    // Task 1
    // vote_count takes a reference to an `ElectionResult` as an argument and will
    // return the number of votes in the `ElectionResult.
    int vote_count(const ElectionResult &election_result) {
        return election_result.votes;
    }

    // Task 2
    // increment_vote_count takes a reference to an `ElectionResult` as an argument
    // and a number of votes (int), and will increment the `ElectionResult` by that
    // number of votes.
    void increment_vote_count(ElectionResult &election_result, const int votes) {
        election_result.votes += votes;
    }

    // Task 3
    // determine_result receives the reference to a final_count and returns a
    // reference to the `ElectionResult` of the new president. It also changes the
    // name of the winner by prefixing it with "President". The final count is given
    // in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
    // `ElectionResults` of all the participating candidates.
    ElectionResult &determine_result(std::vector<ElectionResult> &election_results) {
        std::size_t idx = 0;
        for (std::size_t i = 1; i < election_results.size(); ++i)
            if (election_results[i].votes > election_results[idx].votes)
                idx = i;

        election_results[idx].name.insert(0, "President ");
        return election_results[idx];
    }
} // namespace election
