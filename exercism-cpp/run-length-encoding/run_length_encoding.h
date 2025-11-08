#pragma once
#include <string>

namespace run_length_encoding {

    std::string encode(std::string_view);

    std::string decode(const std::string &);

}  // namespace run_length_encoding
