#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(const std::vector<double> &student_scores) {
    return std::accumulate(
        student_scores.cbegin(), student_scores.cend(), std::vector<int>(),
        [](std::vector<int> result, const double score) {
            result.push_back(static_cast<int>(score));
            return result;
        });
}

// Count the number of failing students out of the group provided.
int count_failed_students(const std::vector<int> &student_scores) {
    return static_cast<int>(std::count_if(
        student_scores.cbegin(), student_scores.cend(), [](const int score) {
            return score <= 40;
        }));
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(const int highest_score) {
    const int diff = (highest_score - 40) / 4;
    std::array<int, 4> result = {41, 41, 41, 41};

    for (auto i = 1; i < 4; ++i)
        result[i] = result[i - 1] + diff;

    return result;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    const std::vector<int> &student_scores, const std::vector<std::string> &student_names) {
    std::vector<std::string> result(student_scores.size());

    for (std::size_t i = 0; i < student_scores.size(); ++i)
        result[i] = std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]);

    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(
    const std::vector<int> &student_scores, const std::vector<std::string> &student_names) {
    for (std::size_t i = 0; i < student_scores.size(); ++i)
        if (student_scores[i] == 100)
            return student_names[i];

    return "";
}
