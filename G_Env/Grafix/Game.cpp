#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::LoadContent()
{
}

void Game::UnloadContent()
{
}

void Game::Initialize()
{
	windowWidth = 800;
	windowHeight = 600;	
	
	Engine::Initialize();
}

void Game::Update()
{	
}

void Game::Draw()
{
	graphicsDevice.ClearRenderTarget(0.0f, 0.0f, 0.0f);

	graphicsDevice.Render();
}
