#pragma once

#include <string>
#include <memory>
#include <utility>

class StringInstancePair
{
    public:
        StringInstancePair(const std::string& str): _str { std::move(str) }, _ins { std::make_unique<InstanceCounter>() } {}

        //StringInstancePair(StringInstancePair&& other): _str { std::move(other._str) }, _ins {std::move(other._ins)} {}
        StringInstancePair(StringInstancePair&& other) = default;
        
        StringInstancePair(const StringInstancePair& other) {
            if (this != &other) {
                _str = other._str;
                _ins = std::make_unique<InstanceCounter>(other.get_instance_counter());
            }
        }

        const std::string& get_str() const {
            return _str;
        }
        const InstanceCounter& get_instance_counter() const {
            return *_ins;
        }
        
    private:
        std::string _str;
        std::unique_ptr<InstanceCounter> _ins;
};