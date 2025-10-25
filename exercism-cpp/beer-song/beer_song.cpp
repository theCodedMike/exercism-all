#include "beer_song.h"
#include <string>

namespace beer_song {
    std::string verse(const int count) {
        if (count == 0) {
            return "No more bottles of beer on the wall, no more bottles of beer.\n"
                      "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        }

        if (count == 1) {
            return "1 bottle of beer on the wall, 1 bottle of beer.\n"
                      "Take it down and pass it around, no more bottles of beer on the wall.\n";
        }

        return std::to_string(count) + " bottles of beer on the wall, "
            + std::to_string(count) + " bottles of beer.\n"
            + "Take one down and pass it around, "
            + std::to_string(count - 1) + " " + (count > 2 ? "bottles" : "bottle") + " of beer on the wall.\n";
    }

    std::string sing(const int up, const int down) {
        std::string res;

        for (auto i = up; i >= down; --i) {
            res += verse(i);
            if (i != down)
                res += "\n";
        }

        return res;
    }
}  // namespace beer_song
