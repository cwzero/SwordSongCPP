#include "SwordSong/Drawable.h"
#include "SwordSong/Tile.h"
#include "SwordSong/TileGrid.h"

namespace SwordSong {
    void Drawable::Draw(TileGrid& grid, int x, int y) {
            grid.SetTile(GetTile(), x, y);
    }

    void Drawable::Draw(TileGrid& grid, TilePoint loc) {
            grid.SetTile(GetTile(), loc);
    }
}