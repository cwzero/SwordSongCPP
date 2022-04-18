#include "SwordSong/GameWorld.h"
#include "SwordSong/Drawable.h"

namespace SwordSong {
    GameWorld::GameWorld(int width, int height, int depth) {
        this->width = width;
        this->height = height;
        this->depth = depth;

        world = new Drawable***[depth];
        for (int z = 0; z < depth; z++) {
            world[z] = new Drawable**[height];
            for (int y = 0; y < height; y++) {
                world[z][y] = new Drawable*[width];
                for (int x = 0; x < width; x++) {
                    world[z][y][x] = nullptr;
                }
            }
        }
    }

    Drawable* GameWorld::GetVisible(int x, int y, int z) {
        if ((x < 0 || x > width)
            || (y < 0 || y > height)
            || (z < 0 || z > depth)) {
            return nullptr;
        }
        return world[z][y][x];
    }
}