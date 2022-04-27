#include "SwordSong/Player.h"
#include "SwordSong/GameWorld.h"

using namespace SwordSong;

Player::Player(std::shared_ptr<GameWorld> world) {
	this->world = world;
}

ColoredTile Player::GetTile() const {
	return { {0, 4}, {1, 1, 1} };
}

bool Player::IsSolid() const {
	//return true;
	return false;
}

void Player::Update() {

}