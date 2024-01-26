#pragma once
#include "Card.hpp"
#include <vector>
#include <random>
#include <algorithm>

class Player
{
private:
    std::string _name;
    std::vector<Card> _cards;
public:
    static unsigned int _score;
    Player(const std::string& name);
    static void deal_all_cards(Player& p1, Player& p2) {
        //std::vector<Card> all_cards = std::vector<Card> {};
        std::vector<Card> all_cards;
        //enum Colors = { Pique, Carreau, Trefle, Coeur };
        for (auto color = 0; color < 4; color++) {
            for (auto value = 1; value < 13; value++) {
                all_cards.emplace_back(Card {value, color});
            }
        }
        for (auto card: p2._cards) {
            all_cards.emplace_back(card);
        }
        std::random_device rd;
        std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));
    };

    const std::string& getName();
    const std::vector<Card>& getCards();
    const Card operator[](int index) const;
};
