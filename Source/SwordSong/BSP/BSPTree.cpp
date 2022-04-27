#include "SwordSong/BSP/BSPTree.h"
#include "SwordSong/BSP/BSPNode.h"

using namespace SwordSong::BSP;

BSPTree::BSPTree(int width, int height) {
    root = std::make_unique<BSPNode>(width, height);
}

BSPTree::~BSPTree() {
    
}