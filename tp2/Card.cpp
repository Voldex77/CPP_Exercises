#include "Card.hpp"

Card::Card(unsigned int value, std::string color) : _value { value }, _color { color }
{
}

const unsigned int& Card::getValue() const
{
    return _value;
}

const std::string& Card::getColor() const
{
    return _color;
}

bool Card::operator==(Card other)
{
    return _value == other.getValue();
};