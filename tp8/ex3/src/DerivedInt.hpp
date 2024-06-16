#pragma once

class DerivedInt: public Base {
    public:
        DerivedInt(int n): Base("Int"), _n {n} {}
        int data() const {
            return _n;
        }

        bool is_null() const override {
            return _n == 0;
        }
        std::string to_string() const override {
            return std::to_string(_n);
        }
    private:
        int _n;
};