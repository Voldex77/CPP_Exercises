#include "Trap.hpp"

Trap::Trap(const int width, const int height) : Entity(random_value(0, width), random_value(0, height)) {}

char Trap::get_representation() const { return 'X';}

void Trap::update() { }