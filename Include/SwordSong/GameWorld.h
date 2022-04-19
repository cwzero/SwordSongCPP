#pragma once

#include <memory>

namespace SwordSong {
    class Drawable;
    class GameWorld {
    public:
        GameWorld(int width, int height, int depth);

        inline int GetWidth() {
            return width;
        }

        inline int GetHeight() {
            return height;
        }

        inline int GetDepth() {
            return depth;
        }

        Drawable* GetVisible(int x, int y, int z);

        void SetVisible(int x, int y, int z, Drawable* drawable);
    private:
        int width, height, depth;
        Drawable**** world;
    };
}