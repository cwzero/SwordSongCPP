#include "SwordSong/Engine.h"
#include "SwordSong/Game.h"
#include "SwordSong/RenderEngine.h"
#include "SwordSong/TileGrid.h"
#include "SwordSong/Window.h"

#include <iostream>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace SwordSong;

Engine::Engine() {
	this->window = std::make_unique<Window>(this);
}

Engine::~Engine() {

}

void Engine::Initialize() {
	window->Initialize();
	window->MakeCurrent();

	int width, height;
	window->GetSize(&width, &height);
	grid = std::make_shared<TileGrid>(width, height);

	game = std::make_unique<Game>(grid);
	renderEngine = std::make_unique<RenderEngine>(grid);

	renderEngine->Initialize();

	game->Initialize();
}

void Engine::Shutdown() {
	game->Shutdown();
	window->Shutdown();
}

void Engine::Run() {
	Initialize();

	while (Loop()) {}

	Shutdown();
}

bool Engine::Loop() {
	window->Clear();
	window->ProcessInput();

	double delta = window->GetDelta();
	static double accumulator = 0;
	accumulator += delta;

	while (accumulator >= 20) {
		Update();
		accumulator -= 20;
	}

	Render(accumulator / 20);

	window->SwapBuffers();
	return !window->ShouldClose();
}

void Engine::Update() {
	game->Update();
}

void Engine::Render(double delta) {
	game->Render(delta);
	renderEngine->Draw();
}

void Engine::KeyEvent(Key key) {
	game->KeyEvent(key);
}