#include "SwordSong/GameWorld.h"
#include "SwordSong/Player.h"
#include "SwordSong/PlayerView.h"
#include "SwordSong/TileGrid.h"

namespace SwordSong {
	PlayerView::PlayerView(std::shared_ptr<Player> player, int width, int height) {
		this->player = player;
		this->width = width;
		this->height = height;
	}

	void PlayerView::Render(GameWorld& world, TileGrid& grid) {
		int xm = width / 2;
		int ym = width / 2;

		int px = player->GetX();
		int py = player->GetY();
		int pz = player->GetZ();

		for (int x = -xm; x < xm; x++) {
			for (int y = -ym; y < ym; y++) {
				int tx = px + x;
				int ty = py + y;

				Drawable* d = world.GetVisible(tx, ty, pz);
				if (d) {
					d->Draw(grid, x, y);
				}
			}
		}
	}
}