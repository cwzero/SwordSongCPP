#pragma once

#include <memory>

#include "SwordSong/Drawable.h"
#include "SwordSong/StackTile.h"

namespace SwordSong {
    class Space : public virtual Drawable {
    public:
        Space();

		virtual void Draw(TileGrid& grid, int x, int y) const override;

        virtual void SetForeground(Drawable *fg);
        virtual void PushMidground(Drawable *mg);
        virtual Drawable* PopMidground();
        virtual void RemoveMidground(Drawable *mg);
        virtual void SetBackground(Drawable *bg);
    private:
        Drawable *foreground;
        std::unique_ptr<StackTile> midground;
        Drawable *background;
    };
}