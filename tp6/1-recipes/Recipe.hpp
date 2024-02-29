#pragma once

#include <ostream>
#include <sstream>
#include <vector>
#include <memory>
#include "Material.hpp"

class Recipe
{
    public:
        Recipe(std::vector<std::string> materials, std::vector<std::string> products);
        ~Recipe();
        // Affiche l'identifiant et la formule d'une recette.
        friend std::ostream& operator<<(std::ostream& stream, const Recipe& recipe) {
            std::stringstream builder;
            builder << "(" << recipe.Recipe::_id << ")";
            for(const auto& material: recipe._materials) {
                builder << " " << material;
            }
            builder << " =>";
            for(const auto& product: recipe._products) {
                builder << " " << product;
            }
            return stream << builder.str();
        }
    private:
        std::vector<std::string> _materials;
        std::vector<std::string> _products;
        size_t _id;
        inline static size_t next_id = 1;
};
