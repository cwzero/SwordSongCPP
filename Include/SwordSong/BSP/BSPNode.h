#pragma once

#include <memory>

namespace SwordSong::BSP {
    class BSPNode {
    public:
        BSPNode(int x, int y, int width, int height);
        BSPNode(int width, int height);
        ~BSPNode();
    private:
        int x, y;
        int width, height;
    };
}