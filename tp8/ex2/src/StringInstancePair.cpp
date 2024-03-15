#include "StringInstancePair.hpp"


StringInstancePair::StringInstancePair(std::string str) : _str { str } {}

std::string StringInstancePair::get_str() {
    return _str;
}

InstanceCounter StringInstancePair::get_instance_counter() {
    return i;
}