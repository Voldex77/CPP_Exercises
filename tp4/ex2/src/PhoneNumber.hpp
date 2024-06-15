#pragma once

#include <vector>
#include <sstream>
#include <ostream>

class PhoneNumber {
    public:
        PhoneNumber(int n1, int n2, int n3, int n4, int n5): _numbers { std::vector<int> { n1, n2, n3, n4, n5 } } {}
        bool is_valid() const {
            for (auto n: _numbers) {
                if (n < 0 || n > 99) {
                    return false;
                }
            }
            return true;
        }
        int operator[](int index) const {
            if (index < 0 || index >= _numbers.size()) {
                return -1;
            }
            return _numbers[index];
        }

        friend std::ostream& operator<<(std::ostream& stream, PhoneNumber pn) {
            std::stringstream builder;
            for(auto n: pn._numbers) {
                if (n / 10 == 0) {
                    builder << "0";
                }
                builder << n;                
            }
            return stream << builder.str();
        }
    private:
        std::vector<int> _numbers;
};