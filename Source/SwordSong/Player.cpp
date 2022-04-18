#include "SwordSong/Player.h"
#include "SwordSong/Drawable.h"

namespace SwordSong {
    ColoredTile Player::GetTile() {
        return {{0, 4}, {1, 1, 1}};
    }
}