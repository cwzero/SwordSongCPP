#pragma once

namespace SwordSong {
    class GameWorld;
    class Generator {
    public:
        virtual void Generate(GameWorld& world) = 0;
    private:
    };
}