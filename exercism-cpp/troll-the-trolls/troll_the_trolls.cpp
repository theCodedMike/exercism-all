namespace hellmath {
    // Task 1 - Define an `AccountStatus` enumeration to represent the four
    // account types: `troll`, `guest`, `user`, and `mod`.
    enum AccountStatus {
        troll, guest, user, mod
    };

    // Task 1 - Define an `Action` enumeration to represent the three
    // permission types: `read`, `write`, and `remove`.
    enum Action {
        read, write, remove
    };

    // Task 2 - Implement the `display_post` function, that gets two arguments
    // of `AccountStatus` and returns a `bool`. The first argument is the status of
    // the poster, the second one is the status of the viewer.
    bool display_post(const AccountStatus poster, const AccountStatus viewer) {
        if (poster == troll)
            return viewer == troll;
        return true;
    }

    // Task 3 - Implement the `permission_check` function, that takes an
    // `Action` as a first argument and an `AccountStatus` to check against. It
    // should return a `bool`.
    bool permission_check(const Action action, const AccountStatus status) {
        switch (status) {
            case guest:
                return action <= read;
            case mod:
                return action <= remove;
            default:
                return action <= write;
        }
    }

    // Task 4 - Implement the `valid_player_combination` function that
    // checks if two players can join the same game. The function has two parameters
    // of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(const AccountStatus player1, const AccountStatus player2) {
        switch (player1) {
            case guest: return false;
            case troll: return player2 == troll;
            default: return player2 >= user;
        }
    }

    // Task 5 - Implement the `has_priority` function that takes two
    // `AccountStatus` arguments and returns `true`, if and only if the first
    // account has a strictly higher priority than the second.
    bool has_priority(const AccountStatus player1, const AccountStatus player2) {
        return player1 > player2;
    }
} // namespace hellmath
