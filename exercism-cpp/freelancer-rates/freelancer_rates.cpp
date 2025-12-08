// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>

// daily_rate calculates the daily rate given an hourly rate
#include <cmath>

double daily_rate(const double hourly_rate) {
    return hourly_rate * 8.0;
}

// apply_discount calculates the price after a discount
double apply_discount(const double before_discount, const double discount) {
    return before_discount * (1 - discount / 100.0);
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(const double hourly_rate, const double discount) {
    return static_cast<int>(ceil(apply_discount(daily_rate(hourly_rate) * 22.0, discount)));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(const int budget, const double hourly_rate, const double discount) {
    return static_cast<int>(floor(budget / apply_discount(daily_rate(hourly_rate), discount)));
}
