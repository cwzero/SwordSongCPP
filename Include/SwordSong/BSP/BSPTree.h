#pragma once

#include <memory>

namespace SwordSong::BSP {
    class BSPNode;

    class BSPTree {
    public:
        BSPTree(int width, int height);
        ~BSPTree();

        inline BSPNode* GetRoot() {
            return root.get();
        }
    private:
        std::unique_ptr<BSPNode> root;
    };
}