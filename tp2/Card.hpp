#include <string>
#include <iostream>

class Card
{
private:
    unsigned int _value;
    std::string _color;

public:
    Card(unsigned int value, std::string color);
    void print() { std::cout << _value << " de " << _color << std::endl; };
};
