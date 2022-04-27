#include "SwordSong/Movable.h"
#include "SwordSong/GameWorld.h"

#include <iostream>

using namespace SwordSong;

void Movable::MoveNorth() {
	MoveRelative(0, 1, 0);
}

void Movable::MoveEast() {
	MoveRelative(1, 0, 0);
}

void Movable::MoveSouth() {
	MoveRelative(0, -1, 0);
}

void Movable::MoveWest() {
	MoveRelative(-1, 0, 0);
}

void Movable::MoveUp() {
	MoveRelative(0, 0, -1);
}

void Movable::MoveDown() {
	MoveRelative(0, 0, 1);
}

void Movable::MoveRelative(int dx, int dy, int dz) {
	MoveTo(GetX() + dx, GetY() + dy, GetZ() + dz);
}

void Movable::MoveTo(int x, int y, int z) {
	if (world && world->IsValid(x, y, z)) {
		if (!IsSolid() || !world->IsSolid(x, y, z)) {
			RemoveFromWorld(world);
			AddToWorld(world, x, y, z);
		}
	}
}