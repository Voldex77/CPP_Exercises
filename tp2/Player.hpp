#pragma once

#include "Card.hpp"
#include <string>
#include <vector>

class Player {
    public:
        Player(const std::string& name);

        static void deal_all_cards(Player& p1, Player& p2);
        Card operator[](unsigned int index) {
            return _cards[index];
        }

        static unsigned int turn_number;

        static void play(Player& p1, Player& p2);

        unsigned int get_score() const {
            return _score;
        }

        std::string get_name() const {
            return _name;
        }

    private:
        std::string _name;
        std::vector<Card> _cards;
        unsigned int _score;
};