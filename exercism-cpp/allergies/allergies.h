#pragma once
#include <unordered_set>
#include <string>

namespace allergies {
    class allergy_result {
    public:
        explicit allergy_result(std::unordered_set<std::string>);

        bool is_allergic_to(const std::string &) const;

        const std::unordered_set<std::string> &get_allergies() const;

    private:
        std::unordered_set<std::string> allergies;
    };

    allergy_result allergy_test(unsigned);
} // namespace allergies
