#pragma once

namespace SwordSong {
	typedef struct {
		float tx, ty;
	} Tile;

	typedef struct {
		float r, g, b;
	} TileColor;

	typedef struct {
		float x, y;
	} TilePoint;

	class Model;
	class Shader;

	class TileSet {
	public:
		TileSet(const char* fileName);
		virtual ~TileSet();

		virtual void Load();
		virtual void Use();

		virtual void DrawTile(float tx, float ty, float r, float g, float b, float x, float y);
		virtual void DrawTile(Tile tile, TileColor color, TilePoint location);

		unsigned int texture;
	private:
		const char* fileName;
		Model *model;
		Shader *shader;
	};
}