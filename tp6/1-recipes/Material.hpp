#pragma once

#include <ostream>
#include <iostream>

class Material
{
    public:
        Material(std::string name): _name { name } {
            std::cout << _name << " was created" << std::endl;
        }

        ~Material() {
            std::cout << _name << " was destroyed" << std::endl;
        }

        // Affiche le nom d'un materiau.
        friend std::ostream& operator<<(std::ostream& stream, const Material& material) {
            return stream << material._name;
        }
    private:
        std::string _name;

};
