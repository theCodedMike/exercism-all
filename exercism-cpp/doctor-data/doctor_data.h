#pragma once
#include <string>

namespace star_map {
    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven {
    class Vessel {
    public:
        Vessel(std::string name, int generation, star_map::System system = star_map::System::Sol);

        Vessel replicate(std::string) const;
        void make_buster();
        bool shoot_buster();

        std::string name;
        int generation;
        star_map::System current_system;
        int busters = 0;
    };


    const std::string &get_older_bob(const Vessel &, const Vessel &);
    bool in_the_same_system(const Vessel &, const Vessel &);

}