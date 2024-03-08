#pragma once

#include "Entity.hpp"

class Trap : public Entity
{
    public:
        Trap(const int width, const int height);
        char get_representation() const override;
        void update() override;
};