#include "SwordSong/RenderEngine.h"
#include "SwordSong/Model.h"
#include "SwordSong/Shader.h"
#include "SwordSong/TileSet.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <string>
#include <iostream>
#include <cstdio>

namespace SwordSong {
	RenderEngine::RenderEngine() {
		tileSet = new TileSet("16x16-sb-ascii.png");		
	}

	RenderEngine::~RenderEngine() {
		delete tileSet;
	}

	void RenderEngine::Initialize() {
		tileSet->Load();
	}

	void RenderEngine::Shutdown() {
		
	}

	void RenderEngine::Draw() {
		tileSet->Use();

		Tile tile = {0, 4};
		TileColor color = {1, 1, 1};

		tileSet->DrawTile(tile, color, {0, 0});
		tileSet->DrawTile(tile, color, {0, 1});
		tileSet->DrawTile(tile, color, {1, 0});
		tileSet->DrawTile(tile, color, {1, 1});

		glBindTexture(GL_TEXTURE_2D, 0);
	}
}