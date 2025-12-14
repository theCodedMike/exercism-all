#pragma once
#include <string>
#include <vector>

namespace speedywagon {
    struct pillar_men_sensor {
        int activity{};
        std::string location{};
        std::vector<int> data{};
    };

    int uv_light_heuristic(std::vector<int> *data_array);

    bool connection_check(const pillar_men_sensor *);

    int activity_counter(const pillar_men_sensor *, int);

    bool alarm_control(const pillar_men_sensor *);

    bool uv_alarm(const pillar_men_sensor *);
} // namespace speedywagon
