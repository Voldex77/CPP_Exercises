#pragma once

#include <cstddef>
#include <array>
#include <vector>

template <typename TValue, size_t StaticSize>
class HybridArray {
    public:
        constexpr static size_t static_size() {
            return StaticSize;
        }

        size_t size() const {
            return index;
        }

        TValue& operator[](int i) {
            return (vector.empty()) ? array[i] : vector[i];
        }

        const TValue& operator[](int i) const {
            return (vector.empty()) ? array[i] : vector[i];
        }

        TValue& push_back(TValue v) {
            if (index < StaticSize) {
                return array[index++] = v;
            }
            vector.push_back(std::move(v));
            index++;
            return vector.back();
        }
    private:
        std::array<TValue, StaticSize> array;
        std::vector<TValue> vector;
        size_t index;
};