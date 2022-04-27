#pragma once

#include "SwordSong/GameWorld.h"
#include "SwordSong/Tile.h"

namespace SwordSong {
	struct _Room;
	typedef struct _Room Room;
	struct _Room {
		int x;
		int y;
		int z;
		int width;
		int height;
	};

	void DrawRoom(GameWorld& world, TileColor wallColor, TileColor floorColor, Room room);
}