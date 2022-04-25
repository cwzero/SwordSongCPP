#pragma once

#include "SwordSong/Movable.h"
#include <memory>

namespace SwordSong {
    class GameWorld;
    class Player : public virtual Movable {
    public:
        Player(std::shared_ptr<GameWorld> world);
        virtual bool IsSolid() const override;
        virtual ColoredTile GetTile() const override;
        virtual void Update() override;
    private:
        std::shared_ptr<GameWorld> world;
    };
}