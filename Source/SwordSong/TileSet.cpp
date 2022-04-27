#include "SwordSong/TileSet.h"
#include "SwordSong/Model.h"
#include "SwordSong/Shader.h"
#include "SwordSong/SwordSong.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace SwordSong;

TileSet::TileSet(const char* fileName, int gridWidth, int gridHeight) {
	this->fileName = fileName;
	model = std::make_unique<Model>();
	shader = std::make_unique<Shader>(gridWidth, gridHeight);
}

TileSet::~TileSet() {
}

void TileSet::Load() {
	model->Initialize();

	shader->Load((SourcePath + "/Resources/Shaders/shader.vs").c_str(), (SourcePath + "/Resources/Shaders/shader.fs").c_str());

	int width, height, comp;
	unsigned char* image = stbi_load((SourcePath + "/Resources/Textures/" + std::string(fileName)).c_str(), &width, &height, &comp, STBI_rgb_alpha);

	if (image == 0) {
		std::cout << stbi_failure_reason() << std::endl;
		exit(1);
	}

	if (image != 0) {

		for (int x = 0; x < 16; x++) {
			for (int y = 0; y < 16; y++) {
				glGenTextures(1, &texture[x][y]);
				glBindTexture(GL_TEXTURE_2D, texture[x][y]);

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

				glPixelStorei(GL_UNPACK_ROW_LENGTH, 256);
				glPixelStorei(GL_UNPACK_SKIP_PIXELS, x * 16);
				glPixelStorei(GL_UNPACK_SKIP_ROWS, y * 16);
				glPixelStorei(GL_UNPACK_ALIGNMENT, 0);

				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 16, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
		}

		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(image);
	}
}

void TileSet::Use() {

}

void TileSet::DrawTile(int tx, int ty, float r, float g, float b, float x, float y) {
	glBindTexture(GL_TEXTURE_2D, texture[tx][ty]);
	shader->Use();

	float xu = (1.0f / 16.0f), yu = (1.0f / 16.0f);

	shader->SetVec3("color", r, g, b);
	shader->SetPosition((x * xu), (y * yu));
	model->Render();
}

void TileSet::DrawTile(Tile tile, TileColor color, int x, int y) {
	DrawTile(tile.tx, tile.ty, color.r, color.g, color.b, x, y);
}

void TileSet::DrawTile(ColoredTile tile, int x, int y) {
	DrawTile(tile.tile, tile.color, x, y);
}

void TileSet::DrawTile(Tile tile, TileColor color, TilePoint location) {
	DrawTile(tile.tx, tile.ty, color.r, color.g, color.b, location.x, location.y);
}

void TileSet::DrawTile(ColoredTile tile, TilePoint location) {
	DrawTile(tile.tile, tile.color, location);
}