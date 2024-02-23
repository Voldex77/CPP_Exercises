#pragma once

#include "Object.hpp"

class CopyablePtr
{
    public:
        CopyablePtr();
        CopyablePtr(int value);
        bool operator==(std::nullptr_t other) const;
        const Object& operator*() const;
        CopyablePtr& operator=(std::nullptr_t null);
    private:
        Object* _object;
};