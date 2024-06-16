#pragma once

#include <ostream>
#include <sstream>
#include <vector>

class Recipe
{
    public:
        Recipe(std::vector<std::string> materials, std::vector<std::string> products): _materials { materials }, _products {products} {
            static size_t id = 1;
            _id = id++;
            std::cout << "Recipe (" << _id << ") was created" << std::endl;
        }

        ~Recipe() {
            std::cout << "Recipe (" << _id << ") was destroyed" << std::endl;
        }

        const std::vector<std::string>& get_materials() const { return _materials; }
        const std::vector<std::string>& get_products() const { return _products; }

        // Affiche l'identifiant et la formule d'une recette.
        friend std::ostream& operator<<(std::ostream& stream, const Recipe& recipe) {
            std::stringstream builder;
            builder << "(" << recipe._id << ") ";
            for(auto m: recipe._materials) {
                builder << m << " ";
            }
            builder << "=>";
            for(auto p: recipe._products) {
                builder << " " << p;
            }
            builder << std::endl;
            return stream << builder.str() ; }
    private:
        std::vector<std::string> _materials;
        std::vector<std::string> _products;
        size_t _id;
};
