#include "Character.hpp"



Character::Character(int x, int y) : Entity(x, y) {}

// int Character::get_x() const { return _x; }
// int Character::get_y() const { return _y; }

char Character::get_representation() const { return 'O'; }

// void Character::update() { random_move(_x, _y); }