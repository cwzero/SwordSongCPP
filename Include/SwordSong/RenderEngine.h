#pragma once

namespace SwordSong {
	class Model;
	class Shader;
	class TileSet;

	class RenderEngine {
	public:
		RenderEngine();
		virtual ~RenderEngine();

		void Initialize();
		void Shutdown();

		void Draw();
	private:
		Model *model;
		Shader *shader;
		TileSet *tileSet;
	};
}