#pragma once
#include <string>

class Person
{
    public:
        Person (std::string first_name, std::string surname):  _first_name(first_name), _surname(surname) {};
        std::string getFirstName();
        std::string getSurname();
    
    private:
        std::string _first_name;
        std::string _surname;
};