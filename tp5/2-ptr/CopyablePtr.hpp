#pragma once

#include "Object.hpp"
#include <utility>

class CopyablePtr
{
    public:
        CopyablePtr(): _obj { nullptr } {}

        CopyablePtr(int n): _obj { new Object(n) } {}

        CopyablePtr(const CopyablePtr& other) {
            if (other == nullptr) {
                _obj = nullptr;
            } else {
                _obj = new Object(*other._obj);
            }
        }

        CopyablePtr(CopyablePtr&& other): _obj { std::move(other._obj) } {
            other._obj = nullptr;
        }

        ~CopyablePtr() {
            if (_obj != nullptr) {
                delete _obj;
            }
        }

        bool operator==(const std::nullptr_t& ptr) const {
            return _obj == ptr;
        }

        const Object& operator*() const {
            return *_obj;
        }

        void operator=(std::nullptr_t newobj) {
            delete _obj;
            _obj = newobj;
        }

        CopyablePtr& operator=(const CopyablePtr& other) {
            if (this != &other) {
                if (other._obj != nullptr) {
                    delete _obj;
                }
                _obj = new Object(*other._obj);
            }
            return *this;
        }

        CopyablePtr& operator=(CopyablePtr&& other) {
            if (this != &other) {
                if (other._obj != nullptr) {
                    delete _obj;
                }
                _obj = other._obj;
                other._obj = nullptr;
            }
            return *this;
        }
    private:
        Object* _obj;
};