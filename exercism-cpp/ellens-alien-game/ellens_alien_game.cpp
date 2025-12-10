namespace targets {
    class Alien {
    public:
        Alien(const int x, const int y) : x_coordinate(x), y_coordinate(y) {
        }

        [[nodiscard]]
        int get_health() const {
            return health;
        }

        bool hit() {
            --health;
            if (health < 0)
                health = 0;
            return true;
        }

        [[nodiscard]]
        bool is_alive() const {
            return health > 0;
        }

        bool teleport(const int x_new, const int y_new) {
            x_coordinate = x_new;
            y_coordinate = y_new;
            return true;
        }

        [[nodiscard]]
        bool collision_detection(const Alien &other) const {
            return x_coordinate == other.x_coordinate && y_coordinate == other.y_coordinate;
        }

        int x_coordinate = 0;
        int y_coordinate = 0;
    private:
        int health = 3;
    };
} // namespace targets
