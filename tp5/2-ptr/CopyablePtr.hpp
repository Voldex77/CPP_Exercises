#include "Object.hpp"

class CopyablePtr
{
    public:
        CopyablePtr();
        bool operator==(std::nullptr_t other);
    private:
        Object* _object;
};