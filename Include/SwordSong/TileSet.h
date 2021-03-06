#pragma once

#include <memory>
#include "SwordSong/Tile.h"

namespace SwordSong {
	class Model;
	class Shader;

	class TileSet {
	public:
		TileSet(const char* fileName, int gridWidth, int gridHeight);
		~TileSet();

		void Load();
		void Use();

		void DrawTile(int tx, int ty, float r, float g, float b, float x, float y);
		void DrawTile(Tile tile, TileColor color, TilePoint location);
		void DrawTile(ColoredTile tile, TilePoint location);
		void DrawTile(Tile tile, TileColor color, int x, int y);
		void DrawTile(ColoredTile tile, int x, int y);

		unsigned int texture[16][16];
	private:
		const char* fileName;
		std::unique_ptr<Model> model;
		std::unique_ptr<Shader> shader;
	};
}