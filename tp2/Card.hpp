#pragma once

#include <string>
#include <iostream>

class Card
{
private:
    unsigned int _value;
    std::string _color;

public:
    Card(unsigned int value, std::string color);
    void print() const { std::cout << _value << " de " << _color << std::endl; };
    const unsigned int& getValue() const;
    const std::string& getColor() const;
    bool operator==(Card other);

};
