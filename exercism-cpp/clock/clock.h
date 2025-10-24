#pragma once
#include <string>

namespace date_independent {

    class clock {
    public:
        static clock at(int, int);

        explicit operator std::string() const;

        [[nodiscard]]
        clock plus(int) const;

        bool operator==(const clock &) const;
        bool operator!=(const clock &) const;

    private:
        int _hour = 0;
        int _minute = 0;

        clock() = default;
        clock(const int hour, const int minute) : _hour(hour), _minute(minute) {}
    };

}  // namespace date_independent
