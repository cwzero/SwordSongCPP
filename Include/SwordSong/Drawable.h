#pragma once

#include "SwordSong/Tile.h"

namespace SwordSong {
    class TileGrid;
    class Drawable {
    public:
        virtual ColoredTile GetTile() = 0;
        virtual void Draw(TileGrid& grid, int x, int y);
        virtual void Draw(TileGrid& grid, TilePoint loc);
    };
}