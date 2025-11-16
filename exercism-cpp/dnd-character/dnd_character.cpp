#include "dnd_character.h"
#include <cmath>
#include <random>
#include <set>

namespace dnd_character {
    int modifier(const int constitution_modifier) {
        return static_cast<int>(std::floor((constitution_modifier - 10.0) / 2.0));
    }

    int ability() {
        static std::random_device rd;
        static std::mt19937 engine(rd());
        static std::uniform_int_distribution distribution(1, 6);
        static std::multiset<int> container;
        container.clear();
        for (auto i = 1; i <= 4; ++i)
            container.insert(distribution(engine));

        return std::accumulate(++container.cbegin(), container.cend(), 0);
    }

    Character::Character()
        : strength(ability()),
          dexterity(ability()),
          constitution(ability()),
          intelligence(ability()),
          wisdom(ability()),
          charisma(ability()),
          hitpoints(10 + modifier(constitution)) {

    }
}  // namespace dnd_character
