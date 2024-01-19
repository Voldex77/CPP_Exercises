#include "Person.hpp"
#include <iostream>

int main()
{
    Person person;
    person.first_name = "Palluche";
    person.surname = "La Falluche";

    std::cout << person.first_name << " " << person.surname << std::endl;
    return 0;
}