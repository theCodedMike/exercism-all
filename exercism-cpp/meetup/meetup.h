#pragma once
#include <boost/date_time/date_defs.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <vector>

namespace meetup {

    class scheduler {
        using month_type = boost::date_time::months_of_year;
        using date_type = boost::gregorian::date;
        using weekday_type = boost::date_time::weekdays;

    public:
        scheduler(const month_type month, const int year): _year(year), _month(month){}

        [[nodiscard]] date_type monteenth() const;
        [[nodiscard]] date_type tuesteenth() const;
        [[nodiscard]] date_type wednesteenth() const;
        [[nodiscard]] date_type thursteenth() const;
        [[nodiscard]] date_type friteenth() const;
        [[nodiscard]] date_type saturteenth() const;
        [[nodiscard]] date_type sunteenth() const;

        [[nodiscard]] date_type first_monday() const;
        [[nodiscard]] date_type first_tuesday() const;
        [[nodiscard]] date_type first_wednesday() const;
        [[nodiscard]] date_type first_thursday() const;
        [[nodiscard]] date_type first_friday() const;
        [[nodiscard]] date_type first_saturday() const;
        [[nodiscard]] date_type first_sunday() const;

        [[nodiscard]] date_type second_monday() const;
        [[nodiscard]] date_type second_tuesday() const;
        [[nodiscard]] date_type second_wednesday() const;
        [[nodiscard]] date_type second_thursday() const;
        [[nodiscard]] date_type second_friday() const;
        [[nodiscard]] date_type second_saturday() const;
        [[nodiscard]] date_type second_sunday() const;

        [[nodiscard]] date_type third_monday() const;
        [[nodiscard]] date_type third_tuesday() const;
        [[nodiscard]] date_type third_wednesday() const;
        [[nodiscard]] date_type third_thursday() const;
        [[nodiscard]] date_type third_friday() const;
        [[nodiscard]] date_type third_saturday() const;
        [[nodiscard]] date_type third_sunday() const;

        [[nodiscard]] date_type fourth_monday() const;
        [[nodiscard]] date_type fourth_tuesday() const;
        [[nodiscard]] date_type fourth_wednesday() const;
        [[nodiscard]] date_type fourth_thursday() const;
        [[nodiscard]] date_type fourth_friday() const;
        [[nodiscard]] date_type fourth_saturday() const;
        [[nodiscard]] date_type fourth_sunday() const;

        [[nodiscard]] date_type last_monday() const;
        [[nodiscard]] date_type last_tuesday() const;
        [[nodiscard]] date_type last_wednesday() const;
        [[nodiscard]] date_type last_thursday() const;
        [[nodiscard]] date_type last_friday() const;
        [[nodiscard]] date_type last_saturday() const;
        [[nodiscard]] date_type last_sunday() const;

    private:
        int _year;
        month_type _month;

        inline static std::vector<int> teenth_days = {
            13, 14, 15, 16, 17, 18, 19
        };
        inline static std::vector<int> days = {
            1, 2, 3, 4, 5, 6, 7,
            8, 9, 10, 11, 12, 13, 14,
            15, 16, 17, 18, 19, 20, 21,
            22, 23, 24, 25, 26, 27, 28,
            29, 30, 31
        };
        [[nodiscard]]
        date_type process(const std::vector<int> &, int, int, weekday_type) const;
        [[nodiscard]]
        int days_of_month() const {
            return boost::gregorian::gregorian_calendar::end_of_month_day(_year, _month);
        }
    };
}  // namespace meetup
