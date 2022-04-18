#pragma once

#include "SwordSong/Entity.h"

namespace SwordSong {
    class Player : public Entity {
        virtual ColoredTile GetTile() override;
        virtual void Update() override;
    };
}