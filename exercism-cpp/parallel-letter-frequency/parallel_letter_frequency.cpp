#include "parallel_letter_frequency.h"
#include <iostream>
#include <locale>
#include <thread>

namespace parallel_letter_frequency {
    std::unordered_map<char, int> frequency(const std::vector<std::string_view> &texts) {
        const size_t num_threads = std::thread::hardware_concurrency();
        std::vector<std::unordered_map<char, int>> local_maps(num_threads);
        std::vector<std::thread> threads;
        // 把texts分割
        const std::size_t texts_size = texts.size();
        const size_t chunk_size = texts_size / num_threads;
        for (size_t i = 0; i < num_threads; ++i) {
            auto start = i * chunk_size;
            auto end = (i == num_threads - 1) ? texts_size : start + chunk_size;

            threads.emplace_back([&, start, end, i]() {
                for (size_t j = start; j < end; ++j) {
                    for (const char ch: texts[j]) {
                        if (std::isalpha(ch))
                            local_maps[i][static_cast<char>(std::tolower(ch))]++;
                    }
                }
            });
        }
        // 等待所有线程完成
        for (auto& thread: threads) {
            thread.join();
        }
        // 合并结果
        std::unordered_map<char, int> result;
        for (const auto & map: local_maps) {
            for (const auto& [key, val] : map) {
                result[key] += val;
            }
        }

        return result;
    }
}
