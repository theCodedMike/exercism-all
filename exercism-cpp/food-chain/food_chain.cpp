#include "food_chain.h"

#include <vector>

namespace food_chain {
    std::string start_intro = "I know an old lady who swallowed a ";
    std::vector<std::string> animals = {
        "fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"
    };
    std::vector<std::string> intros = {
        "",
        "It wriggled and jiggled and tickled inside her.\n",
        "How absurd to swallow a bird!\n",
        "Imagine that, to swallow a cat!\n",
        "What a hog, to swallow a dog!\n",
        "Just opened her throat and swallowed a goat!\n",
        "I don't know how she swallowed a cow!\n",
        "She's dead, of course!\n"
    };
    std::vector<std::string> endings = {
        "I don't know why she swallowed the fly. Perhaps she'll die.\n",
        ".\n",
        " that wriggled and jiggled and tickled inside her.\n",
        ".\n",
        ".\n",
        ".\n",
        ".\n"
    };

    std::string verse(std::size_t num) {
        --num;
        std::string res = start_intro + animals[num] + ".\n" + intros[num];
        if (num >= endings.size())
            return res;

        for (auto i = num; i > 0; --i)
            res += "She swallowed the " + animals[i] + " to catch the " + animals[i - 1] + endings[i];
        res += endings[0];

        return res;
    }

    std::string verses(const std::size_t num1, const std::size_t num2) {
        std::string res;
        for (auto i = num1; i <= num2; ++i)
            res += verse(i) + "\n";
        return res;
    }

    std::string sing() {
        return verses(1, 8);
    }
} // namespace food_chain
