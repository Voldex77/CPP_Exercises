#include "CopyablePtr.hpp"

CopyablePtr::CopyablePtr() : _object { nullptr } {}

CopyablePtr::CopyablePtr(int value) : _object { new Object(value) } {}

bool CopyablePtr::operator==(std::nullptr_t other) const {
    if (_object == other) {
        return true;
    }
    return false;
}

const Object& CopyablePtr::operator*() const {
    return *_object;
}

CopyablePtr& CopyablePtr::operator=(std::nullptr_t null) {
    _object = std::move(null);
    return *this;
}