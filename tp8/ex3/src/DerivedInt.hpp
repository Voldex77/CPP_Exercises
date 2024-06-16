#pragma once

class DerivedInt: public Base {
    public:
        DerivedInt(int n): _n {n} {}
        int data() const {
            return _n;
        }

        bool is_null() const override {
            return _n == 0;
        }
    private:
        int _n;
};