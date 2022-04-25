#pragma once

#include <memory>
#include "SwordSong/Space.h"

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
        bool IsSolid(int x, int y, int z);
        
        Drawable* GetVisible(int x, int y, int z);

        void SetForeground(int x, int y, int z, Drawable* drawable);
        void SetMidground(int x, int y, int z, Drawable* drawable);
        void SetBackground(int x, int y, int z, Drawable* drawable);

        void RemoveForeground(int x, int y, int z, Drawable* drawable);
        void RemoveMidground(int x, int y, int z, Drawable* drawable);
        void RemoveBackground(int x, int y, int z, Drawable* drawable);
    private:
        Space* GetSpace(int x, int y, int z);

        int width = 0, height = 0, depth = 0;
        Space**** world;
    };
}