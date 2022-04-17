#pragma once

#include <memory>

#include "SwordSong/Tile.h"

namespace SwordSong {
	class TileSet;

	class TileGrid {
	public:
		TileGrid(int width, int height);
		~TileGrid();

		void Load();

		void Draw();

		void GetSize(int *width, int *height);

		void SetTile(int x, int y, ColoredTile tile);
	private:
		int width, height;
		std::unique_ptr<TileSet> tileSet;
		ColoredTile **grid;
	};
}