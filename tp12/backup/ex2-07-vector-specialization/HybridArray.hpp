#pragma once

#include <array>
#include <functional>
#include <utility>

template <typename TValue, size_t TStaticSize>
class HybridArray
{
    public:
        template <typename... TArgs>
        HybridArray(TArgs&&... args) {
            if constexpr (sizeof...(args) < TStaticSize) {
                (push_back(std::forward<TArgs>(args)), ...);
            } else {
                (_vectorvalues.push_back(std::forward<TArgs>(args)), ...);
                _staticIndex = _vectorvalues.size();
            }
        }

        constexpr static size_t static_size() {
            return TStaticSize;
        }

        TValue& push_back(const TValue& value) {
            if (_staticIndex < TStaticSize) {
                return _values[_staticIndex++] = value;
            }
            if (_staticIndex == TStaticSize) {
                for(auto elem: _values) {
                    _vectorvalues.push_back(std::move(elem));
                }
            }
            _vectorvalues.push_back(value);
            _staticIndex++;
            return _vectorvalues.back();
        }

        size_t size() const {
            return _staticIndex;
        }

        const TValue& operator[](unsigned int index) const {
            return _vectorvalues.empty() ? _values[index] : _vectorvalues[index];
        }

        TValue& operator[](unsigned int index) {
            return _vectorvalues.empty() ? _values[index] : _vectorvalues[index];
        }

    private:
        std::vector<TValue> _vectorvalues;
        std::array<TValue, TStaticSize> _values;
        size_t _staticIndex = 0u;
};

template <typename TValue>
class HybridArray<TValue, 0u> : public std::vector<TValue>
{
    using std::vector<TValue>::vector;
};