#include <array>
#include <iostream>

struct Driver
{};

struct Wheel
{
    int value;
};

struct Car
{
    explicit Car(Driver& d)
    : driver { d }
    {}

    Driver&              driver;
    std::array<Wheel, 4> wheels;
};

int main()
{
    auto driver = Driver {};
    auto car = Car { driver };

    for(auto i =0; i < 4; i++)
    {
        car.wheels[i].value = i;
    }
    auto& first_wheel = car.wheels.front();
    auto  last_wheel = car.wheels.back();
                                                // <-- on est ici
    std::cout << first_wheel.value << std::endl;
    std::cout << last_wheel.value << std::endl;
    std::cout << car.wheels[3].value << std::endl;
    return 0;
}

/*
cas b
case référence en pointillé
---         ___
| | - - - > | |
---         ___

case mémoire/pointeur

___
| | - - - > X
___

référence il est forcément pas possible qu'il n'y a rien dedans

A -> B
1. Pointeur nul
2. Renvignable


pointeur vs référence

ownership sert à gérer la mémoire
si A own B, au moment de la destruction de A, B se détruit
C'est pour éviter de se souvenir de la libération de mémoire

observant
pointeur qui est détruit, la référence ne sera pas détruit
ownant

&a et b ne peut pas car b n'a pas la syntaxe pour faire cela

int& a =
int* b=null
b=
a= correspond à (*b)=*/