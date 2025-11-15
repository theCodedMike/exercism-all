#include "two_bucket.h"
#include <algorithm>
#include <queue>
#include <set>
#include <stdexcept>

namespace two_bucket {

    measure_result measure(const int bucket1_capacity, const int bucket2_capacity,
                           const int target_volume, const bucket_id start_bucket) {
        // 检查target是否合理
        if (target_volume > std::max(bucket1_capacity, bucket2_capacity))
            throw std::domain_error("Target volume is larger than both buckets");
        // BFS队列
        std::queue<std::pair<int, int>> states;
        std::set<std::pair<int, int>> visited;
        // 初始化状态
        if (start_bucket == bucket_id::one)
            states.emplace(bucket1_capacity, 0);
        else
            states.emplace(0, bucket2_capacity);
        visited.emplace(states.front().first, states.front().second);

        int steps = 1;
        while (!states.empty()) {
            int level_size = states.size();

            for (auto i = 0; i < level_size; ++i) {
                auto[b1, b2] = states.front();
                states.pop();
                // 检查是否实现目标
                if (b1 == target_volume)
                    return {steps, bucket_id::one, b2};
                if (b2 == target_volume)
                    return {steps, bucket_id::two, b1};
                // 生成所有可能的状态
                std::vector<std::pair<int, int>> next_states;
                next_states.emplace_back(bucket1_capacity, b2); // 填充桶1
                next_states.emplace_back(b1, bucket2_capacity); // 填充桶2
                next_states.emplace_back(0, b2); // 清空桶1
                next_states.emplace_back(b1, 0); // 清空桶2
                int pour_amount = std::min(b1, bucket2_capacity - b2); //从桶1倒水到桶2
                next_states.emplace_back(b1 - pour_amount, b2 + pour_amount);
                pour_amount = std::min(b2, bucket1_capacity - b1); // 从桶2倒水到桶1
                next_states.emplace_back(b1 + pour_amount, b2 - pour_amount);
                // 依次处理
                for (auto state: next_states) {
                    bool forbidden_state = false;
                    if (start_bucket == bucket_id::one) {
                        if (state.first == 0 && state.second == bucket2_capacity)
                            forbidden_state = true;
                    } else {
                        if (state.second == 0 && state.first == bucket1_capacity)
                            forbidden_state = true;
                    }

                    if (!forbidden_state && visited.find(state) == visited.end()) {
                        visited.insert(state);
                        states.push(state);
                    }
                }
            }
            ++steps;
        }

        throw std::domain_error("No solution exists");
    }
}  // namespace two_bucket