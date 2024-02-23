#include "CopyablePtr.hpp"

CopyablePtr::CopyablePtr() : _object { nullptr } {}

bool CopyablePtr::operator==(std::nullptr_t other) {
    if (_object == other) {
        return true;
    }
    return false;
}