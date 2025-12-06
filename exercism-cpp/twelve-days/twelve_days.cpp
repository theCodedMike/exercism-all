#include "twelve_days.h"
#include <vector>

namespace twelve_days {
    const std::vector<std::pair<std::string, std::string> > mapper = {
        {"", ""},
        {"first", "a Partridge in a Pear Tree"},
        {"second", "two Turtle Doves, and "},
        {"third", "three French Hens, "},
        {"fourth", "four Calling Birds, "},
        {"fifth", "five Gold Rings, "},
        {"sixth", "six Geese-a-Laying, "},
        {"seventh", "seven Swans-a-Swimming, "},
        {"eighth", "eight Maids-a-Milking, "},
        {"ninth", "nine Ladies Dancing, "},
        {"tenth", "ten Lords-a-Leaping, "},
        {"eleventh", "eleven Pipers Piping, "},
        {"twelfth", "twelve Drummers Drumming, "},
    };

    std::string handle_single(const int start) {
        if (start == 1)
            return "On the first day of Christmas my true love gave to me: a Partridge in a Pear Tree.\n";

        auto curr = handle_single(start - 1);
        // 处理序数词
        const std::size_t pos_of_num = curr.find(mapper[start-1].first);
        curr.replace(pos_of_num, mapper[start-1].first.size(), mapper[start].first);
        // 插入当前序数词对应的特征诗句
        const std::size_t pos_of_colon = curr.find(':');
        curr.insert(pos_of_colon + 2, mapper[start].second);

        return curr;
    }

    std::string recite(const int start, const int end) {
        std::string result;

        for (auto i = start; i <= end; ++i) {
            result += handle_single(i);
            if (i != end)
                result += "\n";
        }

        return result;
    }
} // namespace twelve_days
