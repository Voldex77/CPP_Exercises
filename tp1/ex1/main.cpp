#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Entre ton nom: ";

    std::string name;
    std::cin >> name;
    std::cout << "Bonjour " << name << " !" << std::endl;

    return 0;
}


// On remarque que cela ne prend que 24 caractères.
// On peut en déduire que le tableau de caractère a une limite de mémoire.
// Pour stocker le nom de l'utilisateur à la place du tableau de char, nous allons
// nous servir de la librairie "string".