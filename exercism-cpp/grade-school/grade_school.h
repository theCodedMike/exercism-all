#pragma once
#include <map>
#include <vector>
#include <string>

namespace grade_school {

    class school {
        using grade_type = std::vector<std::string>;
        using roster_type = std::map<int, grade_type>;

    public:
        // 返回花名册
        [[nodiscard]]
        const roster_type& roster() const;
        // 添加学生
        void add(std::string&&, int);
        // 获取某个年级的所有学生
        grade_type grade(int) const;

    private:
        roster_type _roster;
    };

}  // namespace grade_school
