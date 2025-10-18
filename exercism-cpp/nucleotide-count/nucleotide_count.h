#pragma once
#include <string>
#include <map>

namespace nucleotide_count {
    using counter_map = std::map<char, int>;

    counter_map count(std::string_view);

}  // namespace nucleotide_count
