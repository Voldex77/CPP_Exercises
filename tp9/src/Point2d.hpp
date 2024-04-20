#pragma once

#include <unordered_map>
#include <iostream>

struct Point2d {
    int x = 0;
    int y = 0;
};

enum class Content {
    Empty, Red, Yellow
};

std::ostream& operator<<(std::ostream& stream, Content content) {
    switch(content) {
        case Content::Empty: return stream << "-";
        case Content::Red: return stream << "X";
        case Content::Yellow: return stream << "O";
    }
    return stream;
}

class Point2dHash {
    public:
        std::size_t operator()(const Point2d& pt) const {
            return pt.x ^ ~pt.y;
        }
};

class Point2dEqual {
    public:
        bool operator()(const Point2d& pt, const Point2d pt2) const {
            return pt.x == pt2.x && pt.y == pt2.y;
        }
};

int main() {
    // std::unordered_map<Point2d, Content> grid;
    // 3. L'erreur de compilation indique que le constructeur par défaut de std::unordered_map ne peut pas être référencé.
    // Cela est dû au hashage. std::hash
    std::unordered_map<Point2d, Content, Point2dHash, Point2dEqual> grid;
    grid.emplace(Point2d { 3, 4 }, Content::Red);
    grid.emplace(Point2d { 1, 2 }, Content::Yellow);
    for (auto y = 0; y < 5; ++y)
    {
        for (auto x = 0; x < 5; ++x)
        {
            std::cout << grid[Point2d { x, y }] << " ";
        }

        std::cout << "\n";
    }
    return 0;
}
