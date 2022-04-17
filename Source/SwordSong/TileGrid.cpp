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
		delete grid;		
	}

	void TileGrid::Load() {
		tileSet->Load();
	}

	void TileGrid::GetSize(int *width, int *height) {
		*width = this->width;
		*height = this->height;
	}

	void TileGrid::Draw() {
		tileSet->Use();

		int xm = width/2, ym = height/2;

		for (int x = -xm; x < xm; x++) {
			for (int y = -ym; y < ym; y++) {
				tileSet->DrawTile(grid[x + xm][y + ym], {(float)x, (float)y});
			}
		}

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void TileGrid::SetTile(int x, int y, ColoredTile tile) {
		int xm = width/2, ym = height/2;
		this->grid[x + xm][y + ym] = tile;
	}
}