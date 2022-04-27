#include "SwordSong/BSP/BSPGenerator.h"
#include "SwordSong/GameWorld.h"
#include "SwordSong/Drawing.h"

#include <functional>
#include <iostream>
#include <random>

using namespace SwordSong;
using namespace SwordSong::BSP;

typedef void (*BSPCallback) (GameWorld& world, Room room);

void DoSplit(GameWorld& world, BSPCallback callback, Room left, Room right);
void SplitRoom(GameWorld& world, BSPCallback callback, Room parent);

std::random_device rd;
std::mt19937 rng(rd());

int minWidth = 40;
int minHeight = 40;

int rMinWidth = 10;
int rMaxWidth = 30;
int rMinHeight = 10;
int rMaxHeight = 30;

bool ShouldSplitHorizontal(Room room) {
	return room.width > minWidth;
}

bool ShouldSplitVertical(Room room) {
	return room.height > minHeight;
}

int genBreak(int dim, int p) {
	int min = dim * 0.2;
	int max = dim - min;
	int minP = p + min;
	int maxP = p + max;

	if (minP > maxP) {
		return 0;
	}

	std::uniform_int_distribution<int> uni(minP, maxP);
	int result = uni(rng);

	if (result < 0 || result < p) {
		return 0;
	}
	return result;
}

void SplitHorizontal(GameWorld& world, BSPCallback callback, Room parent) {
	Room left = { parent.x, parent.y, parent.z, parent.width, parent.height },
		right = { parent.x, parent.y, parent.z, parent.width, parent.height };

	int x = genBreak(parent.width, parent.x);

	if (!x) {
		return;
	}

	left.width = x - left.x;
	right.width = parent.width - left.width;
	right.x = x;

	DoSplit(world, callback, left, right);
}

void SplitVertical(GameWorld& world, BSPCallback callback, Room parent) {
	Room left = { parent.x, parent.y, parent.z, parent.width, parent.height },
		right = { parent.x, parent.y, parent.z, parent.width, parent.height };

	int y = genBreak(parent.height, parent.y);

	if (!y) {
		return;
	}

	left.height = y - left.y;
	right.height = parent.height - left.height;
	right.y = y;

	DoSplit(world, callback, left, right);
}

void DoSplit(GameWorld& world, BSPCallback callback, Room left, Room right) {
	SplitRoom(world, callback, left);
	SplitRoom(world, callback, right);
}

void SplitRoom(GameWorld& world, BSPCallback callback, Room parent) {
	bool splitH = ShouldSplitHorizontal(parent);
	bool splitV = ShouldSplitVertical(parent);

	if (splitH && splitV) {
		std::uniform_int_distribution<int> bgen(0, 1);
		bool b = bgen(rng);
		if (b) {
			SplitHorizontal(world, callback, parent);
			return;
		}
		else {
			SplitVertical(world, callback, parent);
			return;
		}
	}
	else if (splitH) {
		SplitHorizontal(world, callback, parent);
		return;
	}
	else if (splitV) {
		SplitVertical(world, callback, parent);
		return;
	}
	else {
		callback(world, parent);
	}
}

void GenerateBSP(GameWorld& world, BSPCallback callback) {
	SplitRoom(world, callback, { 0, 0, 0, world.GetWidth() - 1, world.GetHeight() - 1 });
}

Room ShrinkRoom(Room room) {
	Room result = {room.x, room.y, room.z, room.width, room.height};

	int minWidth = rMinWidth;
	if (minWidth > room.width - 2) {
		minWidth = room.width - 2;
	}

	int maxWidth = rMaxWidth;
	if (maxWidth > room.width - 2) {
		maxWidth = room.width - 2;
	}

	std::uniform_int_distribution<int> widthGen(minWidth, maxWidth);

	int minHeight = rMinHeight;
	if (minHeight > room.height - 2) {
		minHeight = room.height - 2;
	}

	int maxHeight = rMaxHeight;
	if (maxHeight > room.height - 2) {
		maxHeight = room.height - 2;
	}

	std::uniform_int_distribution<int> heightGen(minHeight, maxHeight);

	int width = widthGen(rng);
	int height = heightGen(rng);

	int mx = (room.width - width - 1);
	while (mx <= 1) {
		width -= 1;
		mx = (room.width - width - 1);
	}
	result.width = width;
	if (mx > 1) {
		std::uniform_int_distribution<int> xGen(1, mx);
		int dx = xGen(rng);

		result.x += dx;
	}

	int my = (room.height - height - 1);
	while (my <= 1) {
		height -= 1;
		my = (room.height - height - 1);
	}
	result.height = height;
	if (my > 1) {
		std::uniform_int_distribution<int> yGen(1, my);
		int dy = yGen(rng);

		result.y += dy;
	}

	return result;
}

void HandleRoom(GameWorld& world, Room room) {
	DrawRoom(world, { 0, 0, 1 }, { 0, 1, 0 }, ShrinkRoom(room));
}

void BSPGenerator::Generate(GameWorld& world) {
	GenerateBSP(world, HandleRoom);
}