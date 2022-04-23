#include "SwordSong/Drawable.h"
#include "SwordSong/TileGrid.h"

namespace SwordSong {
	ColoredTile Drawable::GetTile() const {
		return {{0, 0}, {0, 0, 0}};
	}

	void Drawable::Draw(TileGrid& grid, int x, int y) const {
		grid.SetTile(GetTile(), x, y);
	}
}