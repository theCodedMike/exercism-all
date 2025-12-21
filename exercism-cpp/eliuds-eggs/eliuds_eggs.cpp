#include "eliuds_eggs.h"

namespace chicken_coop {

    int positions_to_quantity(int num) {
        int count = 0;

        while (num != 0) {
            count += num & 1;
            num >>= 1;
        }

        return count;
    }

}  // namespace chicken_coop
