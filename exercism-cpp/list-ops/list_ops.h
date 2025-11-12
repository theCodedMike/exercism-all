#pragma once
#include <functional>
#include <vector>

namespace list_ops {
    template<typename T>
    void append(std::vector<T> &lhs, const std::vector<T> &rhs) {
        for (auto elem: rhs) {
            lhs.push_back(elem);
        }
    }

    template<typename T>
    std::vector<T> concat(const std::vector<std::vector<T>> &lists) {
        std::vector<T> result;

        for (auto row: lists) {
            for (auto elem: row) {
                result.push_back(elem);
            }
        }

        return result;
    }

    template<typename T, typename Func>
    std::vector<T> filter(const std::vector<T> &list, Func predicate) {
        std::vector<T> result;

        for (auto elem: list) {
            if (predicate(elem))
                result.push_back(elem);
        }

        return result;
    }

    template<typename T>
    std::size_t length(const std::vector<T> &list) {
        return list.size();
    }

    template<typename T, typename Func>
    std::vector<T> map(const std::vector<T> &list, Func mapper) {
        std::vector<T> result;

        for (auto elem: list) {
            result.emplace_back(mapper(elem));
        }

        return result;
    }

    template<typename T, typename Func>
    T foldl(const std::vector<T> &list, T initial, Func folder) {
        for (auto elem: list)
            initial = folder(initial, elem);

        return initial;
    }

    template<typename T, typename Func>
    T foldr(const std::vector<T> &list, T initial, Func folder) {
        for (auto iter = list.rbegin(); iter != list.rend(); ++iter)
            initial = folder(initial, *iter);

        return initial;
    }

    template<typename T>
    std::vector<T> reverse(const std::vector<T> &list) {
        std::vector<T> result;

        for (auto iter = list.rbegin(); iter != list.rend(); ++iter) {
            result.push_back(*iter);
        }

        return result;
    }
} // namespace list_ops
