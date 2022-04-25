#pragma once

#include "SwordSong/Drawable.h"

namespace SwordSong {
    class StaticTile : public virtual Drawable {
    public:
        StaticTile(ColoredTile tile);
        StaticTile(ColoredTile tile, bool solid);

        virtual bool IsSolid() const override;
        virtual ColoredTile GetTile() const override;
    private:
        bool solid;
        ColoredTile tile;
    };
}