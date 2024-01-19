#include "utils.hpp"

int main()
{
    print_hello();
    // print_bye();
    return 0;
}


/*

1. char * en c
std::string en cpp

std::vector
std::array (tableau statique) il te laisse pas de la mémoire non initialisé

2.
- preprocession
1ère étape de compilation cherche tous les # copie brutement dans le #include
copie fichier dans un autre. Modification textutel qui ne sont pas la vraie syntaxe (macros)

- compilation
Le but est de créer un arbre syntaxique correctement.
Ecrit le code machine. Crée code avec des trous (appels de fonctions/jump)

- edition de lien
Remplir les trous.


3. a. "error: 'qqchose' was not declared in this scope" signifie que la variable n'a pas été déclaré dans le hpp.
Soit on a pas inclut le bon fichier.
b. "error: 'qqchose' is not a member of 'std'" signifie qu
foiré dans les includes (std::string mais on a pas inclut le module <string> et du coup, il n'a pas pu trouvé la variable)

4. référence indéfinie

compilation

on a des modules :
compilation (build): main.o et utils.o (crée à partir de main.cpp et de utils.cpp)
edition de lien (link): Lorsqu'on link le fichier , l'erreur c'est qu'on n'a pas la référence de utils car on a pas définie le module utils.o


5. L'erreur c'est qu'on a définit plusieurs fois print_bye. (1 dans main.cpp et 1 dans utils.hpp)
Dans utils.hpp : print_bye est une définition et pas une déclaration.
Comme il est dans 2 endroits (main.cpp et utils.cpp), bah ce n'est plus possible.
Pour résoudre cela, on doit laisser en commentaire tous ses fonctions sauf une.

6.

*/