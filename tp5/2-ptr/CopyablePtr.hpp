#pragma once

#include "Object.hpp"

class CopyablePtr
{
    public:
        CopyablePtr(): _obj { nullptr } {}
        
        bool operator==(const std::nullptr_t& ptr) const {
            return _obj == ptr;
        }
    private:
        Object* _obj;
};