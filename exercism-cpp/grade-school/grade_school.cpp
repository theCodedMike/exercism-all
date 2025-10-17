#include "grade_school.h"
#include <algorithm>

namespace grade_school {
    const school::roster_type &school::roster() const {
        return _roster;
    }

    void school::add(std::string&& name, const int grade) {
        if (_roster[grade].empty()) {
            _roster[grade].push_back(std::move(name));
            return;
        }

        if (std::binary_search(_roster[grade].cbegin(), _roster[grade].cend(), name))
            return;

        const auto pos = std::lower_bound(_roster[grade].cbegin(), _roster[grade].cend(), name);
        _roster[grade].insert(pos, std::move(name));
    }

    school::grade_type school::grade(const int grade) const {
        return _roster.find(grade) != _roster.end() ? _roster.at(grade) : grade_type{};
    }

}  // namespace grade_school
