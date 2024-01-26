#pragma once
#include "Card.hpp"
#include <vector>

class Player
{
private:
    std::string _name;
    std::vector<Card> _cards;
public:
    static unsigned int _score;
    Player(const std::string& name);
};
