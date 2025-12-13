#include "doctor_data.h"

namespace heaven {
    Vessel::Vessel(std::string name, const int generation, const star_map::System system)
        : name(std::move(name)), generation(generation), current_system(system) {

    }

    Vessel Vessel::replicate(std::string new_name) const {
        return {std::move(new_name), generation + 1, current_system};
    }

    void Vessel::make_buster() {
        ++busters;
    }

    bool Vessel::shoot_buster() {
        if (busters == 0)
            return false;
        --busters;
        return true;
    }


    const std::string &get_older_bob(const Vessel &bob1, const Vessel &bob2) {
        return bob1.generation < bob2.generation ? bob1.name : bob2.name;
    }

    bool in_the_same_system(const Vessel &bob1, const Vessel &bob2) {
        return bob1.current_system == bob2.current_system;
    }
}
