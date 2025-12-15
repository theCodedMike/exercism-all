#include "power_of_troy.h"

namespace troy {
    void give_new_artifact(human &man, const std::string &possession) {
        man.possession = std::make_unique<artifact>(possession);
    }

    void exchange_artifacts(std::unique_ptr<artifact> &lhs, std::unique_ptr<artifact> &rhs) {
        std::swap(lhs, rhs);
    }

    void manifest_power(human &man, const std::string &own_power) {
        man.own_power = std::make_shared<power>(own_power);
    }

    void use_power(human &lhs, human &rhs) {
        rhs.influenced_by = lhs.own_power;
    }

    long power_intensity(const human &man) {
        return man.own_power.use_count();
    }
} // namespace troy
