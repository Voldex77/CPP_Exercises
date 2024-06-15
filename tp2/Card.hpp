#pragma once
#include <string>
#include <iostream>
#include <array>
#include <unordered_map>

enum class CardValue {
    As = 1, Deux, Trois, Quatre, Cinq, Six, Sept, Huit, Neuf, Dix,
    Valet, Dame, Roi
};

enum class CardColor {
    Coeur, Pique, Carreau, Trefle
};


class Card
{
public:
    Card(unsigned int value, std::string color);
    // void print() const {
    //     std::array<std::string, 14> values = { "", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi" };
    //     std::cout << values[_value] << " de " << _color << std::endl;
    // };

    void print() const {
        auto getValueName = [](CardValue value) {
            switch (value) {
                case CardValue::As:    return "As";
                case CardValue::Deux:  return "Deux";
                case CardValue::Trois: return "Trois";
                case CardValue::Quatre: return "Quatre";
                case CardValue::Cinq:  return "Cinq";
                case CardValue::Six:   return "Six";
                case CardValue::Sept:  return "Sept";
                case CardValue::Huit:  return "Huit";
                case CardValue::Neuf:  return "Neuf";
                case CardValue::Dix:   return "Dix";
                case CardValue::Valet: return "Valet";
                case CardValue::Dame:  return "Dame";
                case CardValue::Roi:   return "Roi";
            }
            return ""; // Cas par défaut (normalement non atteint)
        };

        auto getColorName = [](CardColor color) {
            switch (color) {
                case CardColor::Coeur:   return "Coeur";
                case CardColor::Pique:   return "Pique";
                case CardColor::Carreau: return "Carreau";
                case CardColor::Trefle:  return "Trefle";
            }
            return ""; // Cas par défaut (normalement non atteint)
        };
        std::cout << getValueName(_value) << " de " << getColorName(_color) << std::endl;
    };

    CardValue toCardValue(unsigned int value) {
        static const CardValue values[] = {
            CardValue::As, CardValue::Deux, CardValue::Trois, CardValue::Quatre,
            CardValue::Cinq, CardValue::Six, CardValue::Sept, CardValue::Huit,
            CardValue::Neuf, CardValue::Dix, CardValue::Valet, CardValue::Dame,
            CardValue::Roi
        };
        if (value > 13) {
            throw std::invalid_argument("Invalid card value");
        }
        return values[value - 1];
    }
    CardColor toCardColor(const std::string& color) {
        static const std::unordered_map<std::string, CardColor> colorMap = {
            {"Coeur", CardColor::Coeur},
            {"Pique", CardColor::Pique},
            {"Carreau", CardColor::Carreau},
            {"Trefle", CardColor::Trefle}
        };
        auto it = colorMap.find(color);
        if (it == colorMap.end()) {
            throw std::invalid_argument("Invalid card color");
        }
        return it->second;
    }

    std::string toString(CardValue value) {
        static const std::unordered_map<CardValue, std::string> valueNames = {
            {CardValue::As, "As"}, {CardValue::Deux, "2"}, {CardValue::Trois, "3"}, {CardValue::Quatre, "4"},
            {CardValue::Cinq, "5"}, {CardValue::Six, "6"}, {CardValue::Sept, "7"}, {CardValue::Huit, "8"},
            {CardValue::Neuf, "9"}, {CardValue::Dix, "10"}, {CardValue::Valet, "Valet"},
            {CardValue::Dame, "Dame"}, {CardValue::Roi, "Roi"}
        };
        return valueNames.at(value);
    }

    // friend std::ostream& operator<<(std::ostream& stream, const Card& card) {
    //     std::array<std::string, 4> colors = { "Coeur", "Pique", "Carreau", "Trèfle" };
    //     return stream << values.at[card._value] << " de " << card._color;
    // };

    friend std::ostream& operator<<(std::ostream& stream, const Card& card) {
        auto getValueName = [](CardValue value) {
            switch (value) {
                case CardValue::As:    return "As";
                case CardValue::Deux:  return "Deux";
                case CardValue::Trois: return "Trois";
                case CardValue::Quatre: return "Quatre";
                case CardValue::Cinq:  return "Cinq";
                case CardValue::Six:   return "Six";
                case CardValue::Sept:  return "Sept";
                case CardValue::Huit:  return "Huit";
                case CardValue::Neuf:  return "Neuf";
                case CardValue::Dix:   return "Dix";
                case CardValue::Valet: return "Valet";
                case CardValue::Dame:  return "Dame";
                case CardValue::Roi:   return "Roi";
            }
            return ""; // Cas par défaut (normalement non atteint)
        };

        auto getColorName = [](CardColor color) {
            switch (color) {
                case CardColor::Coeur:   return "Coeur";
                case CardColor::Pique:   return "Pique";
                case CardColor::Carreau: return "Carreau";
                case CardColor::Trefle:  return "Trefle";
            }
            return ""; // Cas par défaut (normalement non atteint)
        };

        return stream << getValueName(card._value) << " de " << getColorName(card._color);
    };

    bool operator==(Card other) const {
        return _value == other._value;
    }

    bool operator<(Card other) const {
        return _value < other._value;
    }

private:
    //unsigned int _value;
    //std::string _color;
    CardValue _value;
    CardColor _color;
};
