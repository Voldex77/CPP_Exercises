#pragma once

#include <string>
#include "../lib/InstanceCounter.hpp"

class StringInstancePair
{
    public:
        StringInstancePair(std::string str);
        std::string get_str();
        InstanceCounter get_instance_counter();
    private:
        std::string _str;
        InstanceCounter i;
};