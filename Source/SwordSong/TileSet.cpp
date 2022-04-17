#include "SwordSong/TileSet.h"
#include "SwordSong/Model.h"
#include "SwordSong/Shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SwordSong {
	TileSet::TileSet(const char* fileName) {
		texture = 0;
		this->fileName = fileName;
		model = new Model();
		shader = new Shader();
	}

	TileSet::~TileSet() {
		delete model;
		delete shader;
	}

	void TileSet::Load() {
		model->Initialize();
		

		std::string path = "E:/Projects/CPP/SwordSong/Resources/Shaders/";
		shader->Load((path + "shader.vs").c_str(), (path + "shader.fs").c_str());

		int width, height, comp;
		unsigned char* image = stbi_load(("../../Resources/Textures/" + std::string(fileName)).c_str(), &width, &height, &comp, STBI_rgb_alpha);
		
		if (image == 0) {
			std::cout << stbi_failure_reason() << std::endl;
			exit(1);
		}

		if (image != 0) {
			glGenTextures(1, &texture);

			glBindTexture(GL_TEXTURE_2D, texture);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, 0);

			stbi_image_free(image);
		}
	}

	void TileSet::Use() {
		glBindTexture(GL_TEXTURE_2D, texture);
		shader->Use();
	}

	void TileSet::DrawTile(int tx, int ty, float r, float g, float b, int x, int y) {
		float a = 1.0f / 16.0f;
		float xu = a / 2.0f, yu = a;

		shader->SetVec3("color", r, g, b);
		shader->SetVec2("offset", tx * a, ty * a);
		shader->SetVec2("pos", x * xu, y * yu);
		model->Render();
	}

	void TileSet::DrawTile(Tile tile, TileColor color, TilePoint location) {
		DrawTile(tile.tx, tile.ty, color.r, color.g, color.b, location.x, location.y);
	}
}