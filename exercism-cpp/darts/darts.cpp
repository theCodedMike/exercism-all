#include "darts.h"

namespace darts {

    int score(const float x, const float y) {
        const float distance_square = x * x + y * y;
        if (distance_square <= 1)
            return 10;
        if (distance_square <= 25)
            return 5;
        if (distance_square <= 100)
            return 1;
        return 0;
    }

}  // namespace darts
