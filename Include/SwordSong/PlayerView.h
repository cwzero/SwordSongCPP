#pragma once

#include <memory>

namespace SwordSong {
    class GameWorld;
    class Player;
    class TileGrid;
    class PlayerView {
    public:
        PlayerView(std::shared_ptr<Player> player, int width, int height);

        void Update();
        void Render(GameWorld& world, TileGrid& grid);

        void SetPosition(int x, int y, int z);
    private:
        int width, height;
        int x, y, z;
        std::shared_ptr<Player> player;
    };
}