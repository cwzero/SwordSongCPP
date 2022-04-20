#pragma once

#include <memory>

namespace SwordSong {
    class Drawable;
    class GameWorld {
    public:
        GameWorld(int width, int height, int depth);
        ~GameWorld();

        inline int GetWidth() {
            return width;
        }

        inline int GetHeight() {
            return height;
        }

        inline int GetDepth() {
            return depth;
        }

        bool IsValid(int x, int y, int z);

        Drawable* GetVisible(int x, int y, int z);

        void SetVisible(int x, int y, int z, Drawable* drawable);

        void Remove(int x, int y, int z, Drawable* drawable);
    private:
        int width = 0, height = 0, depth = 0;
        Drawable**** world;
    };
}