#pragma once

#include <memory>

namespace SwordSong {
    class GameWorld;
    class Player;
    class TileGrid;
    class PlayerView {
    public:
        PlayerView(std::shared_ptr<Player> player);

        void Render(GameWorld& world, TileGrid& grid);
    private:
        std::shared_ptr<Player> player;
    };
}