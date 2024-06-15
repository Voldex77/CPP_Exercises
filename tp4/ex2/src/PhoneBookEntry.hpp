#pragma once

#include <string>
#include "PhoneNumber.hpp"

class PhoneBookEntry {
    public:
        PhoneBookEntry(const std::string& name, const PhoneNumber& number): _name {name}, _number { number } {}

        const std::string& get_name() const {
            return _name;
        }
        const PhoneNumber& get_number() const {
            return _number;
        }

        bool operator==(const PhoneBookEntry& other) const {
            return _name == other._name;
        }
    private:
        std::string _name;
        PhoneNumber _number;
};