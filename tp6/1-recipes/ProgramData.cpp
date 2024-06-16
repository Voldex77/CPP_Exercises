#include "ProgramData.hpp"


void ProgramData::add_material(std::string name)
{
    _materials.push_back(std::make_unique<Material>(std::move(name)));
}

void ProgramData::get_materials(std::vector<const Material*>& materials) const
{
    for (const auto& m: _materials) {
        materials.push_back(m.get());
    }
}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{
    auto& newrecipe = _recipes.emplace_back(std::make_unique<Recipe>(std::move(materials), std::move(products)));
    for (auto m: materials) {}
    std::cout << "Recipe " << newrecipe.get() << " has been registered";
}

void ProgramData::collect_doable_recipes(std::vector<const Recipe*>& recipes) const
{}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;
    return result;
}