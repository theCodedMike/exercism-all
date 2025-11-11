#include "zebra_puzzle.h"
#include <algorithm>
#include <array>

namespace zebra_puzzle {
    // Constants for readability
    enum House { FIRST = 0, SECOND, THIRD, FOURTH, FIFTH };
    enum Color { RED, GREEN, IVORY, YELLOW, BLUE };
    enum Nationality { ENGLISH, SPANISH, UKRAINIAN, NORWEGIAN, JAPANESE };
    enum Drink { COFFEE, TEA, MILK, ORANGE_JUICE, WATER };
    enum Pet { DOG, SNAIL, FOX, HORSE, ZEBRA };
    enum Hobby { DANCING, PAINTING, READING, FOOTBALL, CHESS };

    Solution solve() {
        // Initialize arrays for each attribute
        std::array<Color, 5> colors{};
        std::array<Nationality, 5> nationalities{};
        std::array<Drink, 5> drinks{};
        std::array<Pet, 5> pets{};
        std::array<Hobby, 5> hobbies{};
        // Initialize arrays with all possible permutations
        std::array<int, 5> color_indices = {RED, GREEN, IVORY, YELLOW, BLUE};
        std::array<int, 5> nationality_indices = {ENGLISH, SPANISH, UKRAINIAN, NORWEGIAN, JAPANESE};
        std::array<int, 5> drink_indices = {COFFEE, TEA, MILK, ORANGE_JUICE, WATER};
        std::array<int, 5> pet_indices = {DOG, SNAIL, FOX, HORSE, ZEBRA};
        std::array<int, 5> hobby_indices = {DANCING, PAINTING, READING, FOOTBALL, CHESS};
        // For each possible permutation of colors, nationalities, drinks, pets, and hobbies
        do {
            for (int i = 0; i < 5; i++) {
                colors[i] = static_cast<Color>(color_indices[i]);
            }
            // Skip if the green house is not immediately to the right of the ivory house (6)
            int green_index = std::find(colors.begin(), colors.end(), GREEN) - colors.begin();
            int ivory_index = std::find(colors.begin(), colors.end(), IVORY) - colors.begin();
            if (green_index != ivory_index + 1) {
                continue;
            }
            do {
                for (int i = 0; i < 5; i++) {
                    nationalities[i] = static_cast<Nationality>(nationality_indices[i]);
                }
                // Skip if the Norwegian does not live in the first house (10)
                if (nationalities[FIRST] != NORWEGIAN) {
                    continue;
                }
                // Skip if the Englishman does not live in the red house (2)
                int english_index = std::find(nationalities.begin(), nationalities.end(), ENGLISH) - nationalities.
                                    begin();
                int red_index = std::find(colors.begin(), colors.end(), RED) - colors.begin();
                if (english_index != red_index) {
                    continue;
                }
                // Skip if the Norwegian does not live next to the blue house (15)
                int norwegian_index = std::find(nationalities.begin(), nationalities.end(), NORWEGIAN) - nationalities.
                                      begin();
                int blue_index = std::find(colors.begin(), colors.end(), BLUE) - colors.begin();
                if (std::abs(norwegian_index - blue_index) != 1) {
                    continue;
                }
                do {
                    for (int i = 0; i < 5; i++) {
                        drinks[i] = static_cast<Drink>(drink_indices[i]);
                    }
                    // Skip if the Ukrainian does not drink tea (5)
                    int ukrainian_index = std::find(nationalities.begin(), nationalities.end(), UKRAINIAN) -
                                          nationalities.begin();
                    if (drinks[ukrainian_index] != TEA) {
                        continue;
                    }
                    // Skip if the person in the green house does not drink coffee (4)
                    if (drinks[green_index] != COFFEE) {
                        continue;
                    }
                    // Skip if the person in the middle house does not drink milk (9)
                    if (drinks[THIRD] != MILK) {
                        continue;
                    }
                    do {
                        for (int i = 0; i < 5; i++) {
                            pets[i] = static_cast<Pet>(pet_indices[i]);
                        }
                        // Skip if the Spaniard does not own the dog (3)
                        int spanish_index = std::find(nationalities.begin(), nationalities.end(), SPANISH) -
                                            nationalities.begin();
                        if (pets[spanish_index] != DOG) {
                            continue;
                        }
                        do {
                            for (int i = 0; i < 5; i++) {
                                hobbies[i] = static_cast<Hobby>(hobby_indices[i]);
                            }
                            // Skip if the snail owner does not like dancing (7)
                            int snail_index = std::find(pets.begin(), pets.end(), SNAIL) - pets.begin();
                            if (hobbies[snail_index] != DANCING) {
                                continue;
                            }
                            // Skip if the person in the yellow house is not a painter (8)
                            int yellow_index = std::find(colors.begin(), colors.end(), YELLOW) - colors.begin();
                            if (hobbies[yellow_index] != PAINTING) {
                                continue;
                            }
                            // Skip if the person who plays football does not drink orange juice (13)
                            int football_index = std::find(hobbies.begin(), hobbies.end(), FOOTBALL) - hobbies.begin();
                            if (drinks[football_index] != ORANGE_JUICE) {
                                continue;
                            }
                            // Skip if the Japanese person does not play chess (14)
                            int japanese_index =
                                    std::find(nationalities.begin(), nationalities.end(), JAPANESE) - nationalities.
                                    begin();
                            if (hobbies[japanese_index] != CHESS) {
                                continue;
                            }
                            // Skip if the person who enjoys reading does not live next to the person with the fox (11)
                            int reading_index = std::find(hobbies.begin(), hobbies.end(), READING) - hobbies.begin();
                            int fox_index = std::find(pets.begin(), pets.end(), FOX) - pets.begin();
                            if (std::abs(reading_index - fox_index) != 1) {
                                continue;
                            }
                            // Skip if the painter's house is not next to the house with the horse (12)
                            int painting_index = std::find(hobbies.begin(), hobbies.end(), PAINTING) - hobbies.begin();
                            int horse_index = std::find(pets.begin(), pets.end(), HORSE) - pets.begin();
                            if (std::abs(painting_index - horse_index) != 1) {
                                continue;
                            }
                            // If we've passed all constraints, we have a solution
                            Solution solution;
                            // Find who drinks water
                            int water_index = std::find(drinks.begin(), drinks.end(), WATER) - drinks.begin();
                            switch (nationalities[water_index]) {
                                case ENGLISH: solution.drinksWater = "Englishman";
                                    break;
                                case SPANISH: solution.drinksWater = "Spaniard";
                                    break;
                                case UKRAINIAN: solution.drinksWater = "Ukrainian";
                                    break;
                                case NORWEGIAN: solution.drinksWater = "Norwegian";
                                    break;
                                case JAPANESE: solution.drinksWater = "Japanese";
                                    break;
                            }
                            // Find who owns the zebra
                            int zebra_index = std::find(pets.begin(), pets.end(), ZEBRA) - pets.begin();
                            switch (nationalities[zebra_index]) {
                                case ENGLISH: solution.ownsZebra = "Englishman";
                                    break;
                                case SPANISH: solution.ownsZebra = "Spaniard";
                                    break;
                                case UKRAINIAN: solution.ownsZebra = "Ukrainian";
                                    break;
                                case NORWEGIAN: solution.ownsZebra = "Norwegian";
                                    break;
                                case JAPANESE: solution.ownsZebra = "Japanese";
                                    break;
                            }
                            return solution;
                        } while (std::next_permutation(hobby_indices.begin(), hobby_indices.end()));
                    } while (std::next_permutation(pet_indices.begin(), pet_indices.end()));
                } while (std::next_permutation(drink_indices.begin(), drink_indices.end()));
            } while (std::next_permutation(nationality_indices.begin(), nationality_indices.end()));
        } while (std::next_permutation(color_indices.begin(), color_indices.end()));
        // If no solution is found (should not happen given the puzzle has a unique solution)
        return {"No solution found", "No solution found"};
    } // namespace zebra_puzzle
}
