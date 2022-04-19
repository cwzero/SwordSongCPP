#pragma once

#include "SwordSong/Movable.h"

namespace SwordSong {
    class GameWorld;
    class Player : public virtual Movable {
    public:
        Player(std::shared_ptr<GameWorld> world);
        virtual ColoredTile GetTile() override;
        virtual void Update() override;
    private:
        std::shared_ptr<GameWorld> world;
    };
}