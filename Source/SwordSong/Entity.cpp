#include "SwordSong/Entity.h"
#include "SwordSong/GameWorld.h"

#include <iostream>

using namespace SwordSong;

void Entity::AddToWorld(GameWorld* world, int x, int y, int z) {
	if (this->world) {
		RemoveFromWorld(this->world);
	}

	this->world = world;

	if (world) {
		world->SetForeground(x, y, z, this);
		this->x = x;
		this->y = y;
		this->z = z;
	}
}

void Entity::RemoveFromWorld(GameWorld* world) {
	if (world) {
		world->RemoveForeground(x, y, z, this);
	}
}