#include "SwordSong/GameWorld.h"
#include "SwordSong/Drawable.h"

namespace SwordSong {
	GameWorld::GameWorld(int width, int height, int depth) {
		this->width = width;
		this->height = height;
		this->depth = depth;

		world = new Drawable * **[depth];
		for (int z = 0; z < depth; z++) {
			world[z] = new Drawable * *[height];
			for (int y = 0; y < height; y++) {
				world[z][y] = new Drawable * [width];
				for (int x = 0; x < width; x++) {
					world[z][y][x] = nullptr;
				}
			}
		}
	}

	GameWorld::~GameWorld() {
		for (int z = 0; z < depth; z++) {
			for (int y = 0; y < height; y++) {
				delete[] world[z][y];
			}
			delete[] world[z];
		}
		delete[] world;
	}

    bool GameWorld::IsValid(int x, int y, int z) {
		return (x >= 0 && x < width)
			&& (y >= 0 && y < height)
			&& (z >= 0 && z < depth);
	}

	Drawable* GameWorld::GetVisible(int x, int y, int z) {
		if (!IsValid(x, y, z))
			return nullptr;
		return world[z][y][x];
	}

	void GameWorld::SetVisible(int x, int y, int z, Drawable* drawable) {
		if (!IsValid(x, y, z))
			return;
		world[z][y][x] = drawable;
	}
	
	void GameWorld::Remove(int x, int y, int z, Drawable* drawable) {
		if (!IsValid(x, y, z))
			return;
		if (world[z][y][x] == drawable) {
			world[z][y][x] = nullptr;
		}
	}
}