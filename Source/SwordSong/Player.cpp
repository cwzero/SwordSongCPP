#include "SwordSong/Player.h"
#include "SwordSong/GameWorld.h"

namespace SwordSong {
    Player::Player(std::shared_ptr<GameWorld> world) {
        this->world = world;
    }

    ColoredTile Player::GetTile() {
        return {{0, 4}, {1, 1, 1}};
    }

    void Player::Update() {
        
    }
}