#include "Character.hpp"

Character::Character(int x, int y) : Entity(x, y) {}

char Character::get_representation() const { return 'O'; }

// void Character::update() { Entity::update(); }