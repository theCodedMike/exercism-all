#include "meetup.h"

namespace meetup {
    scheduler::date_type scheduler::process(
        const std::vector<int> &date_set, // 日期集合
        const int date_set_len, // 日期集合的长度，为了通用处理，所以数据集是最全的
        const int week_idx, // 一个月的周索引
        const weekday_type weekday // 星期几
    ) const {
        int wk_i = 0;

        for (auto i = 0; i < date_set_len; ++i) {
            if (auto t_date = date_type(_year, _month, date_set[i]); t_date.day_of_week() == weekday) {
                ++wk_i;
                if (wk_i == week_idx)
                    return t_date;
                if (week_idx == -1 && date_set[i] + 7 > date_set_len) // 处理last_系列
                    return t_date;
            }
        }

        return {};
    }

    scheduler::date_type scheduler::monteenth() const {
        return process(teenth_days, 7, 1, boost::date_time::Monday);
    }
    scheduler::date_type scheduler::tuesteenth() const {
        return process(teenth_days, 7, 1,boost::date_time::Tuesday);
    }
    scheduler::date_type scheduler::wednesteenth() const {
        return process(teenth_days, 7, 1,boost::date_time::Wednesday);
    }
    scheduler::date_type scheduler::thursteenth() const {
        return process(teenth_days, 7, 1,boost::date_time::Thursday);
    }
    scheduler::date_type scheduler::friteenth() const {
        return process(teenth_days, 7, 1,boost::date_time::Friday);
    }
    scheduler::date_type scheduler::saturteenth() const {
        return process(teenth_days, 7, 1,boost::date_time::Saturday);
    }
    scheduler::date_type scheduler::sunteenth() const {
        return process(teenth_days, 7, 1,boost::date_time::Sunday);
    }

    scheduler::date_type scheduler::first_monday() const {
        return process(days, days_of_month(), 1, boost::date_time::Monday);
    }
    scheduler::date_type scheduler::first_tuesday() const {
        return process(days, days_of_month(), 1, boost::date_time::Tuesday);
    }
    scheduler::date_type scheduler::first_wednesday() const {
        return process(days, days_of_month(), 1, boost::date_time::Wednesday);
    }
    scheduler::date_type scheduler::first_thursday() const {
        return process(days, days_of_month(), 1, boost::date_time::Thursday);
    }
    scheduler::date_type scheduler::first_friday() const {
        return process(days, days_of_month(), 1, boost::date_time::Friday);
    }
    scheduler::date_type scheduler::first_saturday() const {
        return process(days, days_of_month(), 1, boost::date_time::Saturday);
    }
    scheduler::date_type scheduler::first_sunday() const {
        return process(days, days_of_month(), 1, boost::date_time::Sunday);
    }

    scheduler::date_type scheduler::second_monday() const {
        return process(days, days_of_month(), 2, boost::date_time::Monday);
    }
    scheduler::date_type scheduler::second_tuesday() const {
        return process(days, days_of_month(), 2, boost::date_time::Tuesday);
    }
    scheduler::date_type scheduler::second_wednesday() const {
        return process(days, days_of_month(), 2, boost::date_time::Wednesday);
    }
    scheduler::date_type scheduler::second_thursday() const {
        return process(days, days_of_month(), 2, boost::date_time::Thursday);
    }
    scheduler::date_type scheduler::second_friday() const {
        return process(days, days_of_month(), 2, boost::date_time::Friday);
    }
    scheduler::date_type scheduler::second_saturday() const {
        return process(days, days_of_month(), 2, boost::date_time::Saturday);
    }
    scheduler::date_type scheduler::second_sunday() const {
        return process(days, days_of_month(), 2, boost::date_time::Sunday);
    }

    scheduler::date_type scheduler::third_monday() const {
        return process(days, days_of_month(), 3, boost::date_time::Monday);
    }
    scheduler::date_type scheduler::third_tuesday() const {
        return process(days, days_of_month(), 3, boost::date_time::Tuesday);
    }
    scheduler::date_type scheduler::third_wednesday() const {
        return process(days, days_of_month(), 3, boost::date_time::Wednesday);
    }
    scheduler::date_type scheduler::third_thursday() const {
        return process(days, days_of_month(), 3, boost::date_time::Thursday);
    }
    scheduler::date_type scheduler::third_friday() const {
        return process(days, days_of_month(), 3, boost::date_time::Friday);
    }
    scheduler::date_type scheduler::third_saturday() const {
        return process(days, days_of_month(), 3, boost::date_time::Saturday);
    }
    scheduler::date_type scheduler::third_sunday() const {
        return process(days, days_of_month(), 3, boost::date_time::Sunday);
    }

    scheduler::date_type scheduler::fourth_monday() const {
        return process(days, days_of_month(), 4, boost::date_time::Monday);
    }
    scheduler::date_type scheduler::fourth_tuesday() const {
        return process(days, days_of_month(), 4, boost::date_time::Tuesday);
    }
    scheduler::date_type scheduler::fourth_wednesday() const {
        return process(days, days_of_month(), 4, boost::date_time::Wednesday);
    }
    scheduler::date_type scheduler::fourth_thursday() const {
        return process(days, days_of_month(), 4, boost::date_time::Thursday);
    }
    scheduler::date_type scheduler::fourth_friday() const {
        return process(days, days_of_month(), 4, boost::date_time::Friday);
    }
    scheduler::date_type scheduler::fourth_saturday() const {
        return process(days, days_of_month(), 4, boost::date_time::Saturday);
    }
    scheduler::date_type scheduler::fourth_sunday() const {
        return process(days, days_of_month(), 4, boost::date_time::Sunday);
    }

    scheduler::date_type scheduler::last_monday() const {
        return process(days, days_of_month(), -1, boost::date_time::Monday);
    }
    scheduler::date_type scheduler::last_tuesday() const {
        return process(days, days_of_month(), -1, boost::date_time::Tuesday);
    }
    scheduler::date_type scheduler::last_wednesday() const {
        return process(days, days_of_month(), -1, boost::date_time::Wednesday);
    }
    scheduler::date_type scheduler::last_thursday() const {
        return process(days, days_of_month(), -1, boost::date_time::Thursday);
    }
    scheduler::date_type scheduler::last_friday() const {
        return process(days, days_of_month(), -1, boost::date_time::Friday);
    }
    scheduler::date_type scheduler::last_saturday() const {
        return process(days, days_of_month(), -1, boost::date_time::Saturday);
    }
    scheduler::date_type scheduler::last_sunday() const {
        return process(days, days_of_month(), -1, boost::date_time::Sunday);
    }
}  // namespace meetup
