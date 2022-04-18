#pragma once

#include "SwordSong/Drawable.h"

namespace SwordSong {
    class Player : public Drawable {
        virtual ColoredTile GetTile() override;
    };
}