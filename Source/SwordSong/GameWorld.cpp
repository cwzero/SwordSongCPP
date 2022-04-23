#include "SwordSong/GameWorld.h"
#include "SwordSong/Drawable.h"

namespace SwordSong {
	GameWorld::GameWorld(int width, int height, int depth) {
		this->width = width;
		this->height = height;
		this->depth = depth;

		world = new Space***[depth];
		for (int z = 0; z < depth; z++) {
			world[z] = new Space**[height];
			for (int y = 0; y < height; y++) {
				world[z][y] = new Space*[width];
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
		return GetSpace(x, y, z);
	}

	void GameWorld::SetForeground(int x, int y, int z, Drawable* drawable) {
		Space* space = GetSpace(x, y, z);
		if (space) {
			space->SetForeground(drawable);
		}
	}

	void GameWorld::SetMidground(int x, int y, int z, Drawable* drawable) {
		Space* space = GetSpace(x, y, z);
		if (space) {
			space->PushMidground(*drawable);
		}
	}

	void GameWorld::SetBackground(int x, int y, int z, Drawable* drawable) {
		Space* space = GetSpace(x, y, z);
		if (space) {
			space->SetBackground(drawable);
		}
	}

	Space* GameWorld::GetSpace(int x, int y, int z) {
		if (!IsValid(x, y, z))
			return nullptr;
		
		if (world[z][y][x] == nullptr) {
			world[z][y][x] = new Space();
		}

		return world[z][y][x];
	}
	
	void GameWorld::RemoveForeground(int x, int y, int z, Drawable* drawable) {
		Space* space = GetSpace(x, y, z);
		if (space) {
			if (space->GetForeground() == drawable) {
				space->ClearForeground();
			}
		}
	}

	void GameWorld::RemoveMidground(int x, int y, int z, Drawable* drawable) {
		Space* space = GetSpace(x, y, z);
		if (space) {
			space->RemoveMidground(*drawable);
		}
	}

	void GameWorld::RemoveBackground(int x, int y, int z, Drawable* drawable) {
		Space* space = GetSpace(x, y, z);
		if (space && space->GetBackground() == drawable) {
			space->ClearBackground();
		}
	}
}