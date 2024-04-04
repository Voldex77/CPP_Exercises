#pragma once

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



    private:
        std::array<std::array<P, W>, H> _pixels;
};