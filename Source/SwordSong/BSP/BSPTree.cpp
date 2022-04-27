#include "SwordSong/BSP/BSPTree.h"
#include "SwordSong/BSP/BSPNode.h"
#include "SwordSong/GameWorld.h"

using namespace SwordSong::BSP;

BSPTree::BSPTree(int width, int height) {
    root = std::make_unique<BSPNode>(width, height);
}

BSPTree::~BSPTree() {
    
}

void BSPTree::Split() {
    root->Split();
}

void BSPTree::Iterate(GameWorld& world, BSPCallback callback) {
    root->Iterate(world, callback);
}

void BSPTree::Connect() {
    root->Connect();
}