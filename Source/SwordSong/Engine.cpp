#include "SwordSong/Engine.h"
#include "SwordSong/Game.h"
#include "SwordSong/RenderEngine.h"
#include "SwordSong/Window.h"

#include <iostream>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SwordSong {
	Engine::Engine() {
		game = std::make_unique<Game>();
		renderEngine = std::make_unique<RenderEngine>();
		window = std::make_unique<Window>();
	}

	Engine::~Engine() {

	}

	void Engine::Initialize() {
		window->Initialize();
		window->MakeCurrent();

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
		renderEngine->Draw();
		game->Render(delta);
	}
}