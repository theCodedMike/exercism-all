#include "lasagna_master.h"
#include <numeric>

namespace lasagna_master {
    int preparationTime(const std::vector<std::string> &layers, int time) {
        return static_cast<int>(layers.size()) * time;
    }

    amount quantities(const std::vector<std::string> &layers) {
        return std::accumulate(
            layers.cbegin(), layers.cend(), amount{0, 0}, [](amount amt, const std::string &layer) {
                if (layer == "noodles")
                    amt.noodles += 50;
                if (layer == "sauce")
                    amt.sauce += 0.2;
                return amt;
            });
    }

    void addSecretIngredient(std::vector<std::string> &my_list, const std::vector<std::string> &friend_list) {
        my_list[my_list.size() - 1] = friend_list[friend_list.size() - 1];
    }

    std::vector<double> scaleRecipe(const std::vector<double> &input, const int portions) {
        return std::accumulate(
            input.cbegin(), input.cend(), std::vector<double>(),
            [&](std::vector<double> &res, const double val) {
                res.push_back(val * portions / 2);
                return res;
            });
    }

    void addSecretIngredient(std::vector<std::string> &layers, const std::string &aunties_secret) {
        layers[layers.size() - 1] = aunties_secret;
    }
} // namespace lasagna_master
