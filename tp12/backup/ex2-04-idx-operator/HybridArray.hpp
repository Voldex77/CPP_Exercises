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
            values.push_back(value);
            return values.back();
        }

        size_t size() const {
            return values.size();
        }

        const TValue& operator[](unsigned int index) const {
            return values[index];
        }

        TValue& operator[](unsigned int index) {
            return values[index];
        }
        

    private:
        std::vector<TValue> values;

};