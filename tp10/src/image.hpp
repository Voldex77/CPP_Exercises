#pragma once

#include <array>
#include <cstddef>
// UTILISEZ --std=c++17


template <typename P, size_t W, size_t H>
class Image
{
    public:
        Image(const P& pixel) {
            for(auto &line: _pixels) {
                for (auto &p: line) {
                    p = pixel;
                }
            }
        }
        Image() = default;

        P& operator()(const size_t i, const size_t j) {
            return _pixels[j][i];
        }
        const P& operator()(const size_t i, const size_t j) const {
            return _pixels[j][i];
        }

        friend Image operator+(const Image& self, const Image& other) {
            auto result = new Image<P, W, H>();

            for (auto h = size_t {0}; h < H; h++) {
                for (auto w = size_t {0}; w < W; w++) {
                    result._pixels[w][h] = self(w, h) + other(w, h);
                }
            }
            return result;
        }



    private:
        std::array<std::array<P, W>, H> _pixels;
};