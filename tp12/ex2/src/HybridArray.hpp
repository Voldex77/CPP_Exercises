#pragma once

#include <cstddef>
#include <array>
#include <vector>

template <typename TValue, size_t StaticSize>
class HybridArray {
    public:
        template <typename... TArgs>
        HybridArray(TArgs&&... args) {
            if constexpr (sizeof...(args) < StaticSize) {
                (push_back(std::forward<TArgs>(args)), ...);
            } else {
                (vector.push_back(std::forward<TArgs>(args)), ...);
                index = vector.size();
            }
        }

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

        TValue& push_back(const TValue& v) {
            if (index < StaticSize) {
                return array[index++] = v;
            }
            for(auto e: array) {
                vector.push_back(std::move(e));
            }
            vector.push_back(v);
            index++;
            return vector.back();
        }
    private:
        std::array<TValue, StaticSize> array;
        std::vector<TValue> vector;
        size_t index = 0u;
};

template<typename TValue>
class HybridArray<TValue, 0u> : public std::vector<TValue> {
    using std::vector<TValue>::vector; // ici, on apporte tous les fonctions membres de std::vector dans HybridArray.
};