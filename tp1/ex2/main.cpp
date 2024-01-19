#include "Person.hpp"
#include <iostream>

int main()
{
    Person person{"Palluche", "La Faluche"};
    std::cout << person.getFirstName() << " " << person.getSurname() << std::endl;
    return 0;
}