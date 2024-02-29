#include "Material.hpp"
#include <iostream>

// en général, on fait celui là car on fait de copie au paramètre et à la fin on ne fait pas de copie
Material::Material(std::string name) : _name { std::move(name) } {
    std::cout << _name << " was created" << std::endl;
}

// ici, on demande de faire une copie, puis la copie sera détruite après la désinstanciation
//Material::Material(const std::string& name) : _name { name } {
//}


Material::~Material() {
    std::cout << _name << " was destroyed" << std::endl;
}