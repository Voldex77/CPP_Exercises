#pragma once

#include <ostream>

class Material
{
    public:
        Material(std::string name);
        ~Material();
        // Affiche le nom d'un materiau.
        friend std::ostream& operator<<(std::ostream& stream, const Material& material) { return stream << material._name; }
    private:
        std::string _name;
};
