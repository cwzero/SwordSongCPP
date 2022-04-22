#pragma once

#include "SwordSong/Drawable.h"

namespace SwordSong {
    class StackTile : public virtual Drawable {
    public:
        StackTile();
        ~StackTile();

		virtual void Draw(TileGrid& grid, int x, int y) const override;

        virtual void Push(Drawable* d);
        virtual Drawable* Pop();
        virtual void Remove(Drawable* d);

        virtual bool IsEmpty();
    private:
    };
}