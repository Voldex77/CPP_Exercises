#pragma once

#include <unordered_map>

struct Point2d {
    int x;
    int y;
};

enum class Content {
    Empty, Red, Yellow
};

template <> class Point2dHash<Point2d> {
    public:
        std::size_t operator()(const Point2d& pt) const {
            for (auto i = 0, ie = pt.x(); i != ie; ++i)
            //return 
        }
};

int main(void) {
    std::unordered_map<Point2d, Content> grid; // Le compilateur indique que Point2d manque une fonction de hachage car unordered_map est un hashmap.
    return 0;
}