#include "SwordSong/BSP/BSPGenerator.h"
#include "SwordSong/BSP/BSPNode.h"
#include "SwordSong/BSP/BSPTree.h"
#include "SwordSong/GameWorld.h"
#include "SwordSong/Drawing.h"

#include <functional>
#include <iostream>
#include <random>

using namespace SwordSong;
using namespace SwordSong::BSP;

void BSPGenerator::Generate(GameWorld& world) {
	auto tree = std::make_unique<BSPTree>(world.GetWidth() - 1, world.GetHeight() - 1);
	tree->Split();

	tree->Iterate(world, [](GameWorld& world, BSPNode* node) {
		if (node->IsLeaf()) {
			DrawRoom(world, { 0, 0, 1 }, { 0, 1, 0 }, node->GetInternal(0));
		}
	});
}