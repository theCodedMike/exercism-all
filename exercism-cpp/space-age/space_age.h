#pragma once

namespace space_age {
    class space_age {
    public:
        explicit space_age(unsigned long long age_in_seconds);

        [[nodiscard]]
        unsigned long long seconds() const;

        [[nodiscard]]
        double on_earth() const;

        [[nodiscard]]
        double on_mercury() const;

        [[nodiscard]]
        double on_venus() const;

        [[nodiscard]]
        double on_mars() const;

        [[nodiscard]]
        double on_jupiter() const;

        [[nodiscard]]
        double on_saturn() const;

        [[nodiscard]]
        double on_uranus() const;

        [[nodiscard]]
        double on_neptune() const;

    private:
        unsigned long long age = 0;
    };
} // namespace space_age
