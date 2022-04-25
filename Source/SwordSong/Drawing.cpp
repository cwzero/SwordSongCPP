#include "SwordSong/Drawing.h"
#include "SwordSong/Drawable.h"
#include "SwordSong/StaticTile.h"

using namespace SwordSong;

typedef struct {
	Drawable* Floor;
	Drawable* NWCorner;
	Drawable* NECorner;
	Drawable* SECorner;
	Drawable* SWCorner;
	Drawable* HorizontalWall;
	Drawable* VerticalWall;
} RoomTiles;

RoomTiles MakeRoomTiles(TileColor wallColor, TileColor floorColor) {
	RoomTiles result = {};

	result.Floor = new StaticTile({ {0, 11}, floorColor });
	result.NECorner = new StaticTile({ {15, 11}, wallColor }, true);
	result.NWCorner = new StaticTile({ {10, 13}, wallColor }, true);
	result.SWCorner = new StaticTile({ {0, 12}, wallColor }, true);
	result.SECorner = new StaticTile({ {9, 13}, wallColor }, true);
	
	result.VerticalWall = new StaticTile({ {3, 11}, wallColor }, true);
	result.HorizontalWall = new StaticTile({ {4, 12}, wallColor }, true);

	return result;
}

void DrawCorners(GameWorld& world, RoomTiles tiles, Room room) {
	world.SetBackground(room.x, room.y, room.z, tiles.SWCorner);
	world.SetBackground(room.x + room.width, room.y, room.z, tiles.SECorner);
	world.SetBackground(room.x, room.y + room.height, room.z, tiles.NWCorner);
	world.SetBackground(room.x + room.width, room.y + room.height, room.z, tiles.NECorner);
}

void DrawWalls(GameWorld& world, RoomTiles tiles, Room room) {
	DrawCorners(world, tiles, room);

	for (int dx = 1; dx < room.width; dx++) {
		int x = room.x + dx;

		world.SetBackground(x, room.y, room.z, tiles.HorizontalWall);
		world.SetBackground(x, room.y + room.height, room.z, tiles.HorizontalWall);
	}

	for (int dy = 1; dy < room.height; dy++) {
		int y = room.y + dy;

		world.SetBackground(room.x, y, room.z, tiles.VerticalWall);
		world.SetBackground(room.x + room.width, y, room.z, tiles.VerticalWall);
	}
}

void DrawFloor(GameWorld& world, RoomTiles tiles, Room room) {

	for (int dx = 1; dx < room.width; dx++) {
		int x = room.x + dx;
		for (int dy = 1; dy < room.height; dy++) {
			int y = room.y + dy;
			world.SetBackground(x, y, room.z, tiles.Floor);
		}
	}
}

void SwordSong::DrawRoom(GameWorld& world, TileColor wallColor, TileColor floorColor, Room room) {
	RoomTiles tiles = MakeRoomTiles(wallColor, floorColor);
	DrawWalls(world, tiles, room);
	DrawFloor(world, tiles, room);
}