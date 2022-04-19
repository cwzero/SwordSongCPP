#pragma once

#include "SwordSong/Entity.h"

namespace SwordSong {
    class GameWorld;
    class Player : public Entity {
    public:
        Player(std::shared_ptr<GameWorld> world);
        virtual ColoredTile GetTile() override;
        virtual void Update() override;
    private:
        std::shared_ptr<GameWorld> world;
    };
}