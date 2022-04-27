#include "SwordSong/BSP/BSPNode.h"
#include "SwordSong/GameWorld.h"
#include "SwordSong/Drawing.h"

#include <functional>
#include <iostream>
#include <random>

constexpr int MIN_WIDTH = 10;
constexpr int MAX_WIDTH = 40;
constexpr int MIN_HEIGHT = 10;
constexpr int MAX_HEIGHT = 40;

using namespace SwordSong;
using namespace SwordSong::BSP;

std::random_device rd;
std::mt19937 rng(rd());

int genBreak(int base, int min, int max) {
    std::uniform_int_distribution<int> uni(min, max);
    return base + uni(rng);
}

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

Room shrinkRoom(Room input) {
    Room result = input;

    if (genBreak(0, 0, 100) > 5) {
        if (result.width > MIN_WIDTH && result.width < MAX_WIDTH) {
            int w = genBreak(0, MIN_WIDTH, result.width);
            result.width = w;

            int maxX = result.width - w;

            int dx = 0;
            if (maxX > 0) {
                dx = genBreak(0, 0, maxX);
                result.x += dx;
            }
        }

        if (result.height > MIN_HEIGHT && result.height < MAX_HEIGHT) {
            int h = genBreak(0, MIN_HEIGHT, result.height);
            result.height = h;

            int maxY = result.height - h;

            int dy = 0;
            if (maxY > 0) {
                dy = genBreak(0, 0, maxY);
                result.y += dy;
            }
        }
    }

    return result;
}

Room BSPNode::GetInternal(int z) {
    Room result = {
        this->x + 2, this->y + 2, z, this->width - 3, this->height - 3
    };
    if (genBreak(0, 0, 100) > 5) {
        result = shrinkRoom(result);
    }
    else {
        result.x = this->x + 1;
        result.y = this->y + 1;
        result.z = z;
        result.width = this->width - 2;
        result.height = this->height - 2;
    }

    return result;
}

bool BSPNode::ShouldSplitHorizontal() {
    return IsLeaf() && width > MAX_WIDTH;
}

bool BSPNode::ShouldSplitVertical() {
    return IsLeaf() && height > MAX_HEIGHT;
}

void BSPNode::Split() {
    bool splitH = ShouldSplitHorizontal();
    bool splitV = ShouldSplitVertical();

    if (splitH && splitV) {
        std::uniform_int_distribution<int> bgen(0, 1);
        bool b = bgen(rng);

        if (b) {
            type = SplitType::Horizontal;
            SplitHorizontal();
        }
        else
        {
            type = SplitType::Vertical;
            SplitVertical();
        }
    }
    else if (splitH)
    {
        type = SplitType::Horizontal;
        SplitHorizontal();
    }
    else if (splitV)
    {
        type = SplitType::Vertical;
        SplitVertical();
    }

    if (!IsLeaf()) {
        leftChild->Split();
        rightChild->Split();
    }
}

void BSPNode::SplitHorizontal() {
    int minWidth = this->width * 0.2;

    if (minWidth < MIN_WIDTH) {
        minWidth = MIN_WIDTH;
    }

    int maxWidth = this->width * 0.8;
    if (maxWidth <= minWidth || maxWidth < MIN_WIDTH) {
        return;
    }

    int x = genBreak(this->x, minWidth, maxWidth);
    int lx = this->x;
    int lw = x - lx;

    int rx = x;
    int rw = this->width - lw;

    int y = this->y;
    int h = this->height;

    leftChild = std::make_unique<BSPNode>(lx, y, lw, h);
    rightChild = std::make_unique<BSPNode>(rx, y, rw, h);
}

void BSPNode::SplitVertical() {
    int minHeight = this->height * 0.2;
    if (minHeight < MIN_HEIGHT) {
        minHeight = MIN_HEIGHT;
    }

    int maxHeight = this->height * 0.8;
    if (maxHeight <= minHeight || maxHeight < MIN_HEIGHT) {
        return;
    }

    int y = genBreak(this->y, minHeight, maxHeight);

    int ly = this->y;
    int lh = y - ly;

    int ry = y;
    int rh = this->height - lh;

    int x = this->x;
    int w = this->width;

    leftChild = std::make_unique<BSPNode>(x, ly, w, lh);
    rightChild = std::make_unique<BSPNode>(x, ry, w, rh);
}

void BSPNode::Iterate(GameWorld& world, BSPCallback callback) {
    callback(world, this);

    if (leftChild) {
        leftChild->Iterate(world, callback);
    }

    if (rightChild) {
        rightChild->Iterate(world, callback);
    }
}

void BSPNode::Connect() {
    if (leftChild) {
        leftChild->Connect();
    }

    if (rightChild) {
        rightChild->Connect();
    }

    DoConnect();
}

void BSPNode::DoConnect() {

}