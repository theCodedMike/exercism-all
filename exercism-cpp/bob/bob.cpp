#include "bob.h"

namespace bob {

    std::string hey(std::string_view input) {
        const int size = static_cast<int>(input.size());
        bool all_upper = true;
        int char_count = 0;
        int nonspace_count = 0;
        int question_mark_idx = -1;
        bool whitespace_after_question_mark = true;

        for (auto i = 0; i < size; ++i) {
            if (isalpha(input[i])) {
                ++char_count;
                if (islower(input[i]))
                    all_upper = false;
            }
            if (!isspace(input[i]))
                ++nonspace_count;
            if (question_mark_idx != -1 && !isspace(input[i]))
                whitespace_after_question_mark = false;
            if (input[i] == '?')
                question_mark_idx = i;
        }

        if (nonspace_count == 0)
            return "Fine. Be that way!";
        if (question_mark_idx != -1 && whitespace_after_question_mark) {
            if (char_count != 0 && all_upper)
                return "Calm down, I know what I'm doing!";

            return "Sure.";
        }
        if (all_upper && char_count != 0)
            return "Whoa, chill out!";
        return "Whatever.";
    }

}  // namespace bob
