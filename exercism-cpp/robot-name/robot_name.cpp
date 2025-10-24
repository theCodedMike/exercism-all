#include "robot_name.h"
#include <iomanip>
#include <random>
#include <sstream>

namespace robot_name {

    robot::robot() {
        gen_name();
    }

    std::string robot::name() const {
        return _name;
    }


    void robot::reset() {
        gen_name();
    }

    void robot::gen_name() {
        static std::random_device rd;
        static std::default_random_engine engine(rd());
        static std::uniform_int_distribution digit_dist(1, 999);
        static std::uniform_int_distribution char_dist('A', 'Z');

        std::string new_name;
        std::ostringstream oss;
        oss << std::setw(3) << std::setfill('0');
        while (true) {
            new_name.push_back(char_dist(engine));
            new_name.push_back(char_dist(engine));
            oss << digit_dist(engine);
            new_name += oss.str();

            if (_used_names.count(new_name) == 0) {
                _used_names.insert(new_name);
                break;
            }
            oss.str("");
        }

        _name = new_name;
    }
}  // namespace robot_name
