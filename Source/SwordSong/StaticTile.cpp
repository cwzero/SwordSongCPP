#include "SwordSong/StaticTile.h"

namespace SwordSong {
    StaticTile::StaticTile(ColoredTile tile) {
        this->tile = tile;
        this->solid = false;
    }

    StaticTile::StaticTile(ColoredTile tile, bool solid) {
        this->tile = tile;
        this->solid = solid;
    }

    bool StaticTile::IsSolid() const {
        return this->solid;
    }

    ColoredTile StaticTile::GetTile() const {
        return this->tile;
    }
}