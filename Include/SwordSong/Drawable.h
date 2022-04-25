#pragma once

#include "SwordSong/Tile.h"

namespace SwordSong {
	class TileGrid;
	class Drawable {
	public:
		virtual ColoredTile GetTile() const;
		virtual bool IsSolid() const {
			return false;
		}
		virtual void Draw(TileGrid& grid, int x, int y) const;
	private:
	};
}