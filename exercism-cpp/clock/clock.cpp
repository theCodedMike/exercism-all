#include "clock.h"
#include <iomanip>
#include <sstream>

namespace date_independent {
    std::pair<int, int> to_normal(const int time, const int base) {
        int quo = time / base;
        int rem = time % base;
        if (rem != 0 && time < 0) {
            --quo;
            rem += base;
        }
        return std::make_pair(quo, rem);
    }

    clock clock::at(int hour, int minute) {
        auto[m_quo, m_rem] = to_normal(minute, 60);
        hour += m_quo;
        auto [h_quo, h_rem] = to_normal(hour, 24);

        return clock{h_rem, m_rem};
    }

    clock::operator std::string() const {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << _hour
            << ":"
            << std::setfill('0') << std::setw(2) << _minute;
        return oss.str();
    }

    clock clock::plus(const int minute) const {
        return at(_hour, _minute + minute);
    }

    bool clock::operator==(const clock & rhs) const {
        return _hour == rhs._hour && _minute == rhs._minute;
    }

    bool clock::operator!=(const clock & rhs) const {
        return !(*this == rhs);
    }

}  // namespace date_independent
