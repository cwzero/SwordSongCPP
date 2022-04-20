#pragma once

#include "SwordSong/Drawable.h"

namespace SwordSong {
    class StaticTile : public virtual Drawable {
    public:
        StaticTile(ColoredTile tile);
        virtual ColoredTile GetTile() const override;
    private:
        ColoredTile tile;
    };
}