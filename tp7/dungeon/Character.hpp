#pragma once

#include "Entity.hpp"

class Character : public Entity
{
    public:
        Character(int x, int y);
        char get_representation() const override;
    private:
        Entity entity;
};