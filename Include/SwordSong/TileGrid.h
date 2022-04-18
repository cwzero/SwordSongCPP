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

		inline void GetSize(int* width, int* height) {
			*width = this->width;
			*height = this->height;
		}

		inline int GetWidth() {
			return width;
		}

		inline int GetHeight() {
			return height;
		}
		
		void SetTile(Tile tile, TileColor color, int x, int y);
		void SetTile(Tile tile, TileColor color, TilePoint loc);

		void SetTile(ColoredTile tile, int x, int y);
		void SetTile(ColoredTile tile, TilePoint loc);
	private:
		int width, height;
		std::unique_ptr<TileSet> tileSet;
		ColoredTile **grid;
	};
}