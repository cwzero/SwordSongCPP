#include "SwordSong/GameWorld.h"
#include "SwordSong/Player.h"
#include "SwordSong/PlayerView.h"
#include "SwordSong/TileGrid.h"

namespace SwordSong {
	PlayerView::PlayerView(std::shared_ptr<Player> player) {
		this->player = player;
	}

	void PlayerView::Render(GameWorld& world, TileGrid& grid) {
		player->Draw(grid, {0, 0});
		/*grid.SetTile({ {0,  4}, {1, 1, 1} }, { 0, 0 });
		grid.SetTile({ {0,  5}, {1, 0, 1} }, { 1, 1 });
		grid.SetTile({ {0, 11}, {1, 1, 1} }, { 0, 1 });
		grid.SetTile({ {0,  6}, {0, 1, 1} }, { -1, -1 });
		grid.SetTile({ {1, 11}, {1, 1, 1} }, { 1, 0 });
		grid.SetTile({ {2, 11}, {1, 1, 0} }, { 0, -1 });*/
	}
}