#pragma once

#include "Object.hpp"

class CopyablePtr
{
    public:
        CopyablePtr(): _obj { nullptr } {}

        CopyablePtr(int n): _obj { new Object(n) } {}

        bool operator==(const std::nullptr_t& ptr) const {
            return _obj == ptr;
        }

        const Object& operator*() const {
            return *_obj;
        }
    private:
        Object* _obj;
};