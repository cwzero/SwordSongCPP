#include "SwordSong/BSPGenerator.h"
#include "SwordSong/GameWorld.h"
#include "SwordSong/Drawing.h"
#include "SwordSong/Drawing.h"

#include <functional>
#include <iostream>
#include <random>

using namespace SwordSong;

typedef void (*BSPCallback) (GameWorld& world, Room room);

void SplitRoom(GameWorld& world, BSPCallback callback, Room parent);

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)

int minWidth = 80;
int minHeight = 80;

void SplitHorizontal(GameWorld& world, BSPCallback callback, Room parent) {
	Room left = { parent.x, parent.y, parent.z, parent.width, parent.height },
		right = { parent.x, parent.y, parent.z, parent.width, parent.height };

	// Horizontal Split
	int min = parent.width * 0.2;
	int max = parent.width - min;
	int minX = parent.x + min;
	int maxX = parent.x + max;

	if (minX > maxX || minX < 3 || maxX < 3) {
		return;
	}

	std::uniform_int_distribution<int> uni(minX, maxX); // guaranteed unbiased
	int x = uni(rng);

	if (x < 3 || x < parent.x) {
		return;
	}

	left.width = x - left.x;
	right.width = parent.width - left.width - 1;
	right.x = x + 1;

	SplitRoom(world, callback, left);
	SplitRoom(world, callback, right);
}

void SplitVertical(GameWorld& world, BSPCallback callback, Room parent) {
	Room left = { parent.x, parent.y, parent.z, parent.width, parent.height },
		right = { parent.x, parent.y, parent.z, parent.width, parent.height };

	// Vertical Split
	int min = (parent.height) * 0.2;
	int max = (parent.height) - min;
	int minY = parent.y + min;
	int maxY = parent.y + max;

	if (minY > maxY || minY < 3 || maxY < 3) {
		return;
	}

	std::uniform_int_distribution<int> uni(minY, maxY); // guaranteed unbiased
	int y = uni(rng);

	if (y < 0 || y < parent.y) {
		return;
	}

	left.height = y - left.y;
	right.height = parent.height - left.height - 1;
	right.y = y + 1;

	SplitRoom(world, callback, left);
	SplitRoom(world, callback, right);
}

void SplitRoom(GameWorld& world, BSPCallback callback, Room parent) {
	if (parent.width > minWidth || parent.height > minHeight) {
		std::uniform_int_distribution<int> bgen(0, 1);
		bool b = bgen(rng);
		if (b && parent.width > minWidth) {
			SplitHorizontal(world, callback, parent);
		}
		else if (parent.height > minWidth) {
			SplitVertical(world, callback, parent);
		}
		else {
			callback(world, parent);
		}
	}
	else {
		callback(world, parent);
	}
}

void GenerateBSP(GameWorld& world, BSPCallback callback) {
	Room root = { 0, 0, 0, world.GetWidth(), world.GetHeight() };

	SplitRoom(world, callback, root);
}

void HandleRoom(GameWorld& world, Room room) {
	DrawRoom(world, { 0, 0, 1 }, { 0, 1, 0 }, room);
}

void BSPGenerator::Generate(GameWorld& world) {
	GenerateBSP(world, HandleRoom);
}