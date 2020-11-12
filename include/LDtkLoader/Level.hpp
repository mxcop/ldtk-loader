// Created by Modar Nasser on 12/11/2020.

#pragma once

#include <string>
#include <vector>

#include "LDtkLoader/thirdparty/json.hpp"
#include "LDtkLoader/DataTypes.hpp"
#include "LDtkLoader/Layer.hpp"

namespace ldtk {

    class World;

    class Level {
        friend World;
    public:
        Level(Level&& other) noexcept ;
        ~Level();

        const std::string name;
        const unsigned int uid;
        const UIntPoint size;

        auto allLayers() const -> const std::vector<Layer*>&;

    private:
        explicit Level(const nlohmann::json& j, World* w);

        bool no_delete=false;
        std::vector<Layer*> m_layers;
    };

}

