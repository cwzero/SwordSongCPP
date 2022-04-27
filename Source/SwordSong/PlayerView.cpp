#include "SwordSong/GameWorld.h"
#include "SwordSong/Player.h"
#include "SwordSong/PlayerView.h"
#include "SwordSong/TileGrid.h"

#include <iostream>

using namespace SwordSong;

PlayerView::PlayerView(std::shared_ptr<Player> player, int width, int height) {
	this->player = player;
	this->width = width;
	this->height = height;

	this->x = -1;
	this->y = -1;
	this->z = -1;
}

void PlayerView::SetPosition(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void PlayerView::Update() {
	this->z = this->player->GetZ();

	int px = this->player->GetX();
	int py = this->player->GetY();

	int dx = width / 4;
	int dy = height / 4;

	int minX = this->x - dx;
	int maxX = this->x + dx;

	int minY = this->y - dy;
	int maxY = this->y + dy;

	while (px < minX) {
		this->x--;
		minX = this->x - dx;
	}

	while (px > maxX) {
		this->x++;
		maxX = this->x + dx;
	}

	while (py < minY) {
		this->y--;
		minY = this->y - dy;
	}

	while (py > maxY) {
		this->y++;
		maxY = this->y + dy;
	}
}

void PlayerView::Render(GameWorld& world, TileGrid& grid) {
	if (this->x < 0 || this->x > world.GetWidth()) {
		this->x = player->GetX();
	}

	if (this->y < 0 || this->y > world.GetHeight()) {
		this->y = player->GetY();
	}

	this->z = player->GetZ();

	int xm = width / 2;
	int ym = width / 2;

	for (int x = -xm; x < xm; x++) {
		for (int y = -ym; y < ym; y++) {
			int tx = this->x + x;
			int ty = this->y + y;

			Drawable* d = world.GetVisible(tx, ty, this->z);
			if (d) {
				d->Draw(grid, x, y);
			}
		}
	}
}