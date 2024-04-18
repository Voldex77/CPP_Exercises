#pragma once

#include <array>
#include <functional>
#include <utility>

template <typename TValue, size_t TStaticSize>
class HybridArray
{
    public:
        constexpr static size_t static_size() {
            return TStaticSize;
        }

        TValue& push_back(const TValue& value) {
            if (_staticIndex < TStaticSize) {
                return _values[_staticIndex++] = value;
            }
            if (_staticIndex == TStaticSize) {
                for(auto elem: _values) {
                    _vectorvalues.push_back(elem);
                }
            }
            //_vectorvalues.push_back(value);
            return _vectorvalues[_staticIndex++] = value;
        }

        size_t size() const {
            //return (_vectorvalues.empty() ? _staticIndex : _vectorvalues.size());
            return _staticIndex;
        }

        const TValue& operator[](unsigned int index) const {
            return _values[index];
        }

        TValue& operator[](unsigned int index) {
            return _values[index];
        }


    private:
        std::vector<TValue> _vectorvalues;
        std::array<TValue, TStaticSize> _values;
        size_t _staticIndex = 0u;
};