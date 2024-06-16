#pragma once

#include <string>

class DerivedString {
    public:
        DerivedString(const std::string& str): _str {str} {}
        const std::string& data() const {
            return _str;
        }
    private:
        std::string _str;
};