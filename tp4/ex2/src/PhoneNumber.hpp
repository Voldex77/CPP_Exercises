#pragma once

#include <vector>

class PhoneNumber {
    public:
        PhoneNumber(std::vector<int> numbers): _numbers { numbers } {}
    private:
        std::vector<int> _numbers;
}