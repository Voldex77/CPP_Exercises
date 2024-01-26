#include "Player.hpp"

Player::Player(const std::string& name) : _name { name }
{
    _cards = std::vector<Card> {};
}

unsigned int Player::_score = 0;

void Player::deal_all_cards(Player& p1, Player& p2);

const std::string& Player::getName()
{
    return _name;
}
const std::vector<Card>& Player::getCards()
{
    return _cards;
}

const Card Player::operator[](unsigned int index) const
{
    return _cards[index];
}