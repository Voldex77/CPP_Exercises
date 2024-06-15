#pragma once

#include "PhoneBookEntry.hpp"
#include <list>

class PhoneBook {
    public:
        PhoneBook() = default;

        /*void add_entry(PhoneBookEntry e) {
            book.emplace_back(e);
        }*/

        bool add_entry(const PhoneBookEntry& e) {
            for(const auto& en: book) {
                if (en.get_name() == e.get_name()) {
                    return false;
                }
            }
            if (e.get_number().is_valid()) {
                book.emplace_back(e);
                return true;
            }
            return false;
        } 

        const PhoneNumber* get_number(const std::string& name) const {
            for(const auto& pn : book) {
                if (pn.get_name() == name) {
                    return &(pn.get_number());
                }
            }
            return nullptr;
        }

    private:
        std::list<PhoneBookEntry> book;
};