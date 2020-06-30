#include "SpriteComponent.h"

#include "Game.h"
#include "TextureManager.h"
#include <iostream>

SpriteComponent::SpriteComponent(const char* spritePath, int width, int height)
	:
	Component(ComponentTypes::SpriteComponent)
{
	Src.x = Src.y = 0;
	Dest.x = Dest.y = 0;

	Src.w = width;
	Src.h = height;

	Dest.w = width / 2;
	Dest.h = height / 2;
	Texture = TextureManager::LoadTexture(spritePath);

	RegisterToRenderSystem();
}

SpriteComponent::~SpriteComponent()
{
	UnregisterFromRenderSystem();	
	std::cout << "SpriteComponent is destroyed.\n";
}

void SpriteComponent::RegisterToRenderSystem()
{
	Game::renderSystem->RegisterSpriteComponent(this);
}

void SpriteComponent::UnregisterFromRenderSystem()
{
	Game::renderSystem->UnregisterSpriteComponent(this);
}