#include "acronym.h"

namespace acronym {

    std::string acronym(const std::string & input) {
        std::string output;

        for (std::size_t i = 0; i < input.size(); ++i) {
            if (i == 0)
                output.push_back(toupper(input[i]));
            else if (isalpha(input[i]) && (input[i - 1] == ' ' || input[i - 1] == '-' || input[i - 1] == '_'))
                output.push_back(toupper(input[i]));
        }

        return output;
    }

}  // namespace acronym
