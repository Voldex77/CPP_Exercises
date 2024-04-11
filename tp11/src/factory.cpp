#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <map>

// Liste des entitées à construire
std::string desc = R"(Object
Person
Dog
Cat
Tree
House
)";

class Entity
{
public:
    virtual void print() const = 0;
};

class Factory
{
public:
    using Builder = std::function<std::unique_ptr<Entity>()>;

    template <typename TDerivedEntity, typename... TArgs>
    void register_entity(const std::string& id, TArgs&&... args)
    {
        Builder builder = [&args... ]() { return std::make_unique<TDerivedEntity>(args...); };
        _builders.emplace(id, builder);
    }

    std::unique_ptr<Entity> build(const std::string& id) const {
        auto func = _builders.find(id);
        if (func != _builders.end()) {
            return func->second();
        }
        return nullptr;
    }

private:
    std::map<std::string, Builder> _builders;
};

class Object : public Entity
{
public:
    void print() const override { std::cout << "Object" << std::endl; }
};

class Tree : public Object
{
public:
    void print() const override { std::cout << "Tree" << std::endl; }
};

class Person : public Entity
{
public:
    explicit Person(std::string name)
        : _name { std::move(name) }
    {}

    void print() const override { std::cout << _name << std::endl; }

    void               set_name(std::string name) { _name = std::move(name); }
    const std::string& get_name() const { return _name; }

private:
    std::string _name;
};

class Animal : public Entity
{
public:
    explicit Animal(std::string species)
        : _species { std::move(species) }
    {}

    void print() const override { std::cout << _species << std::endl; }

private:
    std::string _species;
};

class House : public Object
{
public:
    explicit House(Person& owner)
        : _owner { owner }
    {}

    void print() const override { std::cout << "House owned by " << _owner.get_name() << std::endl; }

private:
    Person& _owner;
};

int main()
{
    Factory factory;

    factory.register_entity<Object>("Object");
    factory.register_entity<Person>("Person", "Jean");
    factory.register_entity<Tree>("Tree");

    factory.register_entity<Animal>("Dog", "Dog");

    Person jean("jean");
    factory.register_entity<House>("House", std::reference_wrapper<Person>(jean));


    std::vector<std::unique_ptr<Entity>> entities;

    std::stringstream s;
    s << desc;
    while (!s.eof())
    {
        std::string e;
        s >> e;

        entities.emplace_back(factory.build(e));
    }

    for (const auto& e : entities)
    {
        if (e != nullptr)
        {
            e->print();
        }
    }

    return 0;
}
