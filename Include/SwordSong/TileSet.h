#pragma once

#include <memory>
#include "SwordSong/Tile.h"

namespace SwordSong {
	class Model;
	class Shader;

	class TileSet {
	public:
		TileSet(const char* fileName, int gridWidth, int gridHeight);
		virtual ~TileSet();

		virtual void Load();
		virtual void Use();

		virtual void DrawTile(int tx, int ty, float r, float g, float b, float x, float y);
		virtual void DrawTile(Tile tile, TileColor color, TilePoint location);
		virtual void DrawTile(ColoredTile tile, TilePoint location);

		unsigned int texture[16][16];
	private:
		const char* fileName;
		std::unique_ptr<Model> model;
		std::unique_ptr<Shader> shader;
	};
}