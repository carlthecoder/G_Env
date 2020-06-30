#pragma once
#include "MapManager.h"
#include "Player.h"
#include <memory>

#include "RenderSystem.h"

class Game
{
public:
	Game();
	~Game();

	void Update();
	void Render();

	MapManager& GetMapManager();

	static RenderSystem* renderSystem;

private:
	std::unique_ptr<Entity> player;
	std::unique_ptr<MapManager> mapManager;
	std::vector<std::unique_ptr<Entity>> entities;
};