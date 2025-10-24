#pragma once
#include <string>
#include <unordered_set>

namespace robot_name {

    class robot {
    public:
        robot();

        [[nodiscard]]
        std::string name() const;

        void reset();

    private:
        std::string _name; // 机器人的名字
        inline static std::unordered_set<std::string> _used_names; // 已使用的所有名字

        void gen_name();
    };

}  // namespace robot_name
