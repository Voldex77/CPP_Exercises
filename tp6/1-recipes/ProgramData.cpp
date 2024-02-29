#include "ProgramData.hpp"


void ProgramData::add_material(std::string name)
{
    _materials.push_back(std::make_unique<Material>(name));
}

void ProgramData::get_materials(std::vector<const Material*>& materials) const
{
    for(const auto& material: _materials) {
        materials.push_back(material.get());
    }
}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{}

void ProgramData::collect_doable_recipes(std::vector<const Recipe*>& recipes) const
{}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;
    return result;
}