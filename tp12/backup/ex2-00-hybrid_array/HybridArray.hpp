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

    private:
        std::vector<TValue> values;

};