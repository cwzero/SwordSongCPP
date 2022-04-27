#include "SwordSong/BSP/BSPNode.h"

using namespace SwordSong::BSP;

BSPNode::BSPNode(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

BSPNode::BSPNode(int width, int height) : BSPNode(0, 0, width, height) {
    
}

BSPNode::~BSPNode() {
    
}