#pragma once

namespace SwordSong {
	typedef struct {
		int tx, ty;
	} Tile;

	typedef struct {
		float r, g, b;
	} TileColor;

	typedef struct {
		int x, y;
	} TilePoint;

	typedef struct {
		Tile tile;
		TileColor color;
	} ColoredTile;
}