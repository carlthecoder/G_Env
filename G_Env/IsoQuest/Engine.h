#pragma once
#include "Game.h"
#include <SDL.h>
#include <memory>

class Engine
{
public:
	Engine();
	~Engine();

	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool IsRunning() { return isRunning; }

	static SDL_Renderer* renderer;

private:
	bool isRunning;
	SDL_Window* window;	
	std::unique_ptr<Game> game;	
};