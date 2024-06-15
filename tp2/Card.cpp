#include "Card.hpp"

// Card::Card(unsigned int value, std::string color) : _value { value }, _color { color }
// {
// };
Card::Card(unsigned int value, std::string color) : _value (toCardValue(value)), _color ( toCardColor(color))
{
};