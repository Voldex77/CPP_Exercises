#include <iostream>
#include <vector>
#include <sstream>
#include "Person.hpp"


int main() {
    Person p("Palluche", "La Falluche");
    std::cout << "La personne s'appelle " << p.get_first_name() << p.get_surname() << std::endl;

    int cmpt;
    std::cout << "Nombre de personnes: ";
    std::cin >> cmpt;

    std::vector<Person> tab;
    std::string prenom, nom;
    for (auto i = 0; i < cmpt; i++) {
        std::cout << "Prenom: ";
        std::cin >> prenom;
        std::cout << "Nom: ";
        std::cin >> nom;
        tab.emplace_back(prenom, nom);
    }
    std::stringstream builder;
    builder << "Les personnes sont ";
    auto flag = false;
    for (auto p: tab) {
        if (flag == true) {
            builder << ", ";
        }
        builder << p.get_first_name() << " " << p.get_surname();
        flag = true;
    }
    builder << "." << std::endl;
    std::cout << builder.str();

    return 0;
}