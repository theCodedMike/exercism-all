#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {
    std::vector<std::string> commands(const unsigned num) {
        std::vector<std::string> res;

        if (num & 0b00001)
            res.emplace_back("wink");
        if (num & 0b00010)
            res.emplace_back("double blink");
        if (num & 0b00100)
            res.emplace_back("close your eyes");
        if (num & 0b01000)
            res.emplace_back("jump");
        if (num & 0b10000)
            std::reverse(res.begin(), res.end());

        return res;
    }
}  // namespace secret_handshake
