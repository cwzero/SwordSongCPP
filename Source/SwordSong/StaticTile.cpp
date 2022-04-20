#include "SwordSong/StaticTile.h"

namespace SwordSong {
    StaticTile::StaticTile(ColoredTile tile) {
        this->tile = tile;
    }

    ColoredTile StaticTile::GetTile() const {
        return this->tile;
    }
}