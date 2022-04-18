#pragma once

#include "SwordSong/Tile.h"
#include "SwordSong/TileGrid.h"

namespace SwordSong {
	class Drawable {
	public:
		virtual ColoredTile GetTile() {
			return {{0, 0}, {0, 0, 0}};
		}

		inline virtual void Draw(TileGrid& grid, int x, int y) {
			grid.SetTile(GetTile(), x, y);
		}
		inline virtual void Draw(TileGrid& grid, TilePoint loc) {
			grid.SetTile(GetTile(), loc);
		}
	};
}