#pragma once
#include <iostream>
#include <vector>

class PhoneNumber
{
    public:
        PhoneNumber(int v1, int v2, int v3, int v4, int v5)
        {
            v = std::vector<int> { v1, v2, v3, v4, v5 };
        };
        bool is_valid() const
        {
            for (auto e: v)
            if (0 > e || e > 99)
            {
                return false;
            }
            return true;
        }

        int operator[] (int index) const
        {
            if (index < 0 || index > 4)
            {
                return -1;
            }
            return v[index];
        }


    private:
        std::vector<int> v;
};
