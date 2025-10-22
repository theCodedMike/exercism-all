#include "gigasecond.h"
#include <boost/date_time/posix_time/posix_time_duration.hpp>

namespace gigasecond {

    ptime advance(const ptime time) {
        return time + seconds(1000000000);
    }

}  // namespace gigasecond
