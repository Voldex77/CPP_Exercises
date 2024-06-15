#include <string>

class Person
{
    public:
        Person(std::string first_name, std::string surname) : _first_name(first_name), _surname(surname) {};
        std::string get_first_name() {return _first_name; }
        std::string get_surname() { return _surname; }
    private:
        std::string _first_name;
        std::string _surname;
};