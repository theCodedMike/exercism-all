#include "sublist.h"

namespace sublist {

    List_comparison sublist(std::vector<int> &&fst, std::vector<int> &&snd) {
        auto compare = [](auto && shorter, auto &&larger) {
            auto diff_size = larger.size() - shorter.size();
            for (std::size_t i = 0; i <= diff_size; ++i)
                if (std::equal(shorter.begin(), shorter.end(), larger.begin() + i))
                    return true;

            return false;
        };

        if (fst.size() < snd.size())
            return compare(fst, snd) ? List_comparison::sublist : List_comparison::unequal;
        if (fst.size() > snd.size())
            return compare(snd, fst) ? List_comparison::superlist : List_comparison::unequal;
        return fst == snd ? List_comparison::equal : List_comparison::unequal;
    }

}  // namespace sublist
