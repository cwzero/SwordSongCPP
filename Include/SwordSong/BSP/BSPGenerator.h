#pragma once

#include "SwordSong/Generator.h"

namespace SwordSong::BSP {
    class BSPGenerator : public virtual Generator {
    public:
        virtual void Generate(GameWorld& world) override;
    private:
    };
}