#include "EntityManager.h"
#include "Game.h"
#include "SpriteManager.h"
#include <iostream>

Game::Game()
	:
	player(std::make_unique<Player>())
{}

Game::~Game()
{
	std::cout << "Game destructed..\n";
}

void Game::Initialize()
{
	player->Initialize();
}

void Game::Update()
{
	player->Update();
	EntityManager::Update();
	SpriteManager::Update();
}

void Game::Draw()
{
	player->Draw();
	SpriteManager::Draw();
}