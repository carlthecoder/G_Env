#include "Game.h"
#include "Entity.h"
#include <iostream>
#include <memory>
#include <vector>

RenderSystem* Game::renderSystem = nullptr;

Game::Game()
	:
	mapManager(std::make_unique<MapManager>())
{
	renderSystem = new RenderSystem();

	player = std::make_unique<Entity>();
	player->AddComponent(new SpriteComponent("Assets/player.png", 96, 104));
	entities.push_back(std::move(player));	
}

Game::~Game()
{
	delete renderSystem;
	std::cout << "Game deleted. \n";
}

void Game::Update()
{
	auto kbd = SDL_GetKeyboardState(0);

	if (kbd[SDL_SCANCODE_A])
	{
		mapManager->MoveMapLeft();
	}
	if (kbd[SDL_SCANCODE_D])
	{
		mapManager->MoveMapRight();
	}
	if (kbd[SDL_SCANCODE_W])
	{
		mapManager->MoveMapUp();
	}
	if (kbd[SDL_SCANCODE_S])
	{
		mapManager->MoveMapDown();
	}
}

void Game::Render()
{
	mapManager->DrawMap();

	renderSystem->Render();
}

MapManager& Game::GetMapManager()
{
	return *mapManager.get();
}