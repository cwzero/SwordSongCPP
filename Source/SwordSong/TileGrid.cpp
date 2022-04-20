#include "SwordSong/TileGrid.h"
#include "SwordSong/TileSet.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace SwordSong {
	TileGrid::TileGrid(int width, int height) {
		this->width = width / 16;
		this->height = height / 16;
		tileSet = std::make_unique<TileSet>("16x16-sb-ascii.png", this->width, this->height);
		this->grid = new ColoredTile*[this->width];
		for (int i = 0; i < this->width; i++) {
			this->grid[i] = new ColoredTile[this->height];
			for (int j = 0; j < this->height; j++) {
				this->grid[i][j] = {{0, 0}, {0, 0, 0}};
			}
		}
	}

	TileGrid::~TileGrid() {
		for (int i = 0; i < this->width; i++) {
			delete grid[i];
		}
		delete grid;		
	}

	void TileGrid::Clear() {
		for (int i = 0; i < this->width; i++) {
			for (int j = 0; j < this->height; j++) {
				this->grid[i][j] = { {0, 0}, {0, 0, 0} };
			}
		}
	}

	void TileGrid::Load() {
		tileSet->Load();
	}

	void TileGrid::Draw() {
		tileSet->Use();

		int xm = width/2, ym = height/2;

		for (int x = -xm; x < xm; x++) {
			for (int y = -ym; y < ym; y++) {
				tileSet->DrawTile(grid[x + xm][y + ym], {x, y});
			}
		}

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void TileGrid::SetTile(ColoredTile tile, int x, int y) {
		int xm = width/2, ym = height/2;
		this->grid[x + xm][y + ym] = tile;
	}

	void TileGrid::SetTile(ColoredTile tile, TilePoint loc) {
		SetTile(tile, loc.x, loc.y);
	}

	void TileGrid::SetTile(Tile tile, TileColor color, int x, int y) {
		SetTile({ tile, color }, x, y);
	}

	void TileGrid::SetTile(Tile tile, TileColor color, TilePoint loc) {
		SetTile({ tile, color }, loc);
	}
}