#include "yacht.h"
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <map>
#include <set>

namespace yacht {
    long long score(const std::vector<int> &dice, std::string_view category) {
        if (category == "ones")
            return std::count_if(dice.cbegin(), dice.cend(), [](const int i) { return i == 1; }) * 1;
        if (category == "twos")
            return std::count_if(dice.cbegin(), dice.cend(), [](const int i) { return i == 2; }) * 2;
        if (category == "threes")
            return std::count_if(dice.cbegin(), dice.cend(), [](const int i) { return i == 3; }) * 3;
        if (category == "fours")
            return std::count_if(dice.cbegin(), dice.cend(), [](const int i) { return i == 4; }) * 4;
        if (category == "fives")
            return std::count_if(dice.cbegin(), dice.cend(), [](const int i) { return i == 5; }) * 5;
        if (category == "sixes")
            return std::count_if(dice.cbegin(), dice.cend(), [](const int i) { return i == 6; }) * 6;
        if (category == "full house") {
            const auto helper = std::accumulate(dice.cbegin(), dice.cend(), std::map<int, int>(),
                                                [](auto acc, const int i) {
                                                    ++acc[i];
                                                    return acc;
                                                });
            if (helper.size() != 2)
                return 0;
            auto [f_key, f_val] = std::make_pair(helper.cbegin()->first, helper.cbegin()->second);
            auto [s_key, s_val] = std::make_pair(helper.rbegin()->first, helper.rbegin()->second);
            if ((f_val == 2 && s_val == 3) || (f_val == 3 && s_val == 2))
                return f_key * f_val + s_key * s_val;
            return 0;
        }
        if (category == "four of a kind") {
            const auto helper = std::accumulate(dice.cbegin(), dice.cend(), std::map<int, int>(),
                                                [](auto acc, const int i) {
                                                    ++acc[i];
                                                    return acc;
                                                });
            if (helper.size() == 1)
                return helper.cbegin()->first * 4;
            if (helper.size() == 2) {
                if (auto [f_key, f_val] = std::make_pair(helper.cbegin()->first, helper.cbegin()->second); f_val == 4)
                    return f_key * 4;
                if (auto [s_key, s_val] = std::make_pair(helper.rbegin()->first, helper.rbegin()->second); s_val == 4)
                    return s_key * 4;
                return 0;
            }
            return 0;
        }
        if (category == "little straight") {
            const auto helper = std::accumulate(dice.cbegin(), dice.cend(), std::set<int>(),
                                                [](auto acc, const int i) {
                                                    acc.insert(i);
                                                    return acc;
                                                });
            return helper.size() == 5 && std::all_of(dice.cbegin(), dice.cend(), [](const int i) {
                return i >= 1 && i <= 5;
            }) ? 30 : 0;
        }
        if (category == "big straight") {
            const auto helper = std::accumulate(dice.cbegin(), dice.cend(), std::set<int>(),
                                                [](auto acc, const int i) {
                                                    acc.insert(i);
                                                    return acc;
                                                });
            return helper.size() == 5 && std::all_of(dice.cbegin(), dice.cend(), [](const int i) {
                return i >= 2 && i <= 6;
            }) ? 30 : 0;
        }
        if (category == "choice")
            return std::accumulate(dice.cbegin(), dice.cend(), 0, [](long long sum, const int i) {
                sum += i;
                return sum;
            });
        if (category == "yacht")
            return std::all_of(dice.cbegin() + 1, dice.cend(), [&](const int i) {
                return dice[0] == i;
            }) ? 50 : 0;

        throw std::invalid_argument("Invalid category");
    }
} // namespace yacht
