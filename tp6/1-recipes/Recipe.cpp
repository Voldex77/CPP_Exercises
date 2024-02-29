#include "Recipe.hpp"
#include <iostream>

Recipe::Recipe(std::vector<std::string> materials, std::vector<std::string> products) : _id(next_id++), _materials { materials }, _products { products } {
    std::cout << Recipe::_id << " was created" << std::endl;
}

Recipe::~Recipe() {
    std::cout << Recipe::_id << " was destroyed" << std::endl;
}