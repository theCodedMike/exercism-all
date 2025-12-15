#include "allergies.h"

#include <vector>

namespace allergies {
    allergy_result::allergy_result(std::unordered_set<std::string> allergies)
        : allergies(std::move(allergies)) {
    }

    bool allergy_result::is_allergic_to(const std::string &allergy) const {
        return allergies.count(allergy) == 1;
    }

    const std::unordered_set<std::string> &allergy_result::get_allergies() const {
        return allergies;
    }

    std::vector<std::pair<unsigned, std::string> > allergy_list = {
        {1, "eggs"},
        {2, "peanuts"},
        {4, "shellfish"},
        {8, "strawberries"},
        {16, "tomatoes"},
        {32, "chocolate"},
        {64, "pollen"},
        {128, "cats"}
    };

    allergy_result allergy_test(const unsigned score) {
        std::unordered_set<std::string> allergies;

        for (const auto& [item_score, item_allergy]: allergy_list) {
            if ((score & item_score) == item_score)
                allergies.insert(item_allergy);
        }

        return allergy_result{allergies};
    }
} // namespace allergies
