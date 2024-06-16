#pragma once

class DerivedInt{
    public:
        DerivedInt(int n): _n {n} {}
        int data() const {
            return _n;
        }
    private:
        int _n;
};