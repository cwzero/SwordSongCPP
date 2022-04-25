#pragma once

#include "SwordSong/GameWorld.h"
#include "SwordSong/Tile.h"

namespace SwordSong {
	typedef struct {
		int x;
		int y;
		int z;
		int width;
		int height;
	} Room;

	void DrawRoom(GameWorld& world, TileColor wallColor, TileColor floorColor, Room room);
}