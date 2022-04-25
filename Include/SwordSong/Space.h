#pragma once

#include <memory>

#include "SwordSong/Drawable.h"
#include "SwordSong/StackTile.h"

namespace SwordSong {
    class Space : public virtual Drawable {
    public:
        Space();

		virtual void Draw(TileGrid& grid, int x, int y) const override;

        virtual inline Drawable* GetForeground() const {
            return foreground;
        }

        virtual inline Drawable* GetBackground() const {
            return background;
        }

        virtual inline Drawable* GetMidground() const {
            return midground.get();
        }

        virtual void SetForeground(Drawable* fg);
        virtual void ClearForeground();
        virtual void PushMidground(Drawable& mg);
        virtual Drawable& PopMidground();
        virtual void ClearMidground();
        virtual void RemoveMidground(Drawable& mg);
        virtual void SetBackground(Drawable* bg);
        virtual void ClearBackground();
    private:
        Drawable* foreground;
        std::unique_ptr<StackTile> midground;
        Drawable* background;
    };
}