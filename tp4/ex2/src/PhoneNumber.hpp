#include <iostream>
#include <vector>

class PhoneNumber
{
    public:
        PhoneNumber(int v1, int v2, int v3, int v4, int v5): _v1 {v1}, _v2 {v2}, _v3 {v3}, _v4 {v4}, _v5 {v5} {};
        bool is_valid()
        {
            auto values = std::vector<int> { _v1, _v2, _v3, _v4, _v5 };
            for (auto v: values)
            if (0 > v || v > 99)
            {
                return false;
            }
            return true;
        }

    private:
        int _v1;
        int _v2;
        int _v3;
        int _v4;
        int _v5;

};
