#pragma once

namespace SwordSong {
	typedef struct {
		int tx, ty;
	} Tile;

	typedef struct {
		int r, g, b;
	} TileColor;

	typedef struct {
		int x, y;
	} TilePoint;

	class Model;
	class Shader;

	class TileSet {
	public:
		TileSet(const char* fileName);
		virtual ~TileSet();

		virtual void Load();
		virtual void Use();

		virtual void DrawTile(int tx, int ty, float r, float g, float b, int x, int y);
		virtual void DrawTile(Tile tile, TileColor color, TilePoint location);

		unsigned int texture;
	private:
		const char* fileName;
		Model *model;
		Shader *shader;
	};
}