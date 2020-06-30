#include "Engine.h"

#include <iostream>

SDL_Renderer* Engine::renderer = nullptr;

Engine::Engine()
{}

Engine::~Engine()
{
	std::cout << "Engine deleted.\n";
}

void Engine::Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
		width = 1920;
		height = 1080;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL subsystems initialized." << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window)
		{
			std::cout << "Window created." << std::endl;

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				std::cout << "Renderer created." << std::endl;

				isRunning = true;
			}
		}
	}
	else
	{
		std::cout << "SDL initialization failed...\n Exiting program \n";
		isRunning = false;
	}

	game = std::make_unique<Game>();
}

void Engine::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
			case SDL_QUIT:
				isRunning = false;
				break;

			case SDL_MOUSEWHEEL:
				if (event.wheel.y > 0) // scroll up
				{
					game->GetMapManager().ZoomIn();
				}
				else if (event.wheel.y < 0) // scroll down
				{
					game->GetMapManager().ZoomOut();
				}
				break;
		}
	}
}

void Engine::Update()
{
	game->Update();
}

void Engine::Render()
{
	SDL_RenderClear(renderer);
	{
		game->Render();
	}
	SDL_RenderPresent(renderer);
}

void Engine::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Engine cleaned.\n";
}