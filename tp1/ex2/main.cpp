#include "Person.hpp"
#include <iostream>
#include <vector>
#include <sstream>
int main()
{
    int numbers;
    std::cout << "Nombre de personnes: ";
    std::cin >> numbers;

    auto persons = std::vector<Person> {};
    std::string fn, sn;
    for (auto i = 0; i < numbers; i++)
    {
        std::cout << "Prenom: ";
        std::cin >> fn;
        std::cout << "Nom: ";
        std::cin >> sn;
        persons.emplace_back(fn, sn);
    }
    std::stringstream builder;
    builder << "Les personnes sont";
    for (auto p: persons)
    {
        builder << " " << p.getFirstName() << ", " << p.getSurname();
    }
    std::cout << builder.str() << "." << std::endl;
    return 0;
}

// ici, pour déclarer un tableau de Person, on est obligé de passer par auto avec vector.