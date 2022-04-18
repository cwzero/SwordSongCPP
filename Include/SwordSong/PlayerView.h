#pragma once

#include <memory>

namespace SwordSong {
    class GameWorld;
    class Player;
    class TileGrid;
    class PlayerView {
    public:
        PlayerView(std::shared_ptr<Player> player, int width, int height);

        void Render(GameWorld& world, TileGrid& grid);
    private:
        int width, height;
        std::shared_ptr<Player> player;
    };
}