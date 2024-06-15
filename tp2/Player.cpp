#include "Player.hpp"
#include <algorithm>
#include <random>

Player::Player(const std::string& name): _name {name}, _score {0} {}

void Player::deal_all_cards(Player& p1, Player& p2) {
    std::vector<Card> all_cards;
    std::vector<std::string> colors = { "Coeur", "Pique", "Carreau", "Trefle"};
    auto cmpt = 0;
    for(auto c: colors) {
        for(auto v = 1; v < 14; v++) {
            all_cards.emplace_back(v, c);
            cmpt++;
        }
    }
    std::random_device rd;
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));
    for(auto i = 0; i < all_cards.size(); i++) {
        if (i < (all_cards.size() / 2)) {
            p1._cards.emplace_back(all_cards[i]);
        } else {
            p2._cards.emplace_back(all_cards[i]);
        }
    }
}

unsigned int Player::turn_number = 0;

void Player::play(Player& p1, Player& p2) {
    std::cout << "Player 1" << std::endl;
    p1[turn_number].print();
    std::cout << std::endl;
    std::cout << "Player 2" << std::endl;
    p2[turn_number].print();
    std::cout << std::endl;

    if (p1[turn_number] < p2[turn_number]) {
        p1._score++;
    } else if (p1[turn_number] == p2[turn_number])
    {
        /* nothing */
    } else {
        p2._score++;
    }
    
}