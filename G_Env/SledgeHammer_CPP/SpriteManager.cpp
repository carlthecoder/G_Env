#include "SpriteManager.h"
#include <algorithm>

extern SDL_Renderer* renderer;

std::vector<Sprite*> SpriteManager::spriteBatch {};

SDL_Texture* SpriteManager::LoadTexture(const char* filepath)
{
	SDL_Surface* tempSurface = IMG_Load(filepath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	SDL_FreeSurface(tempSurface);	

	return texture;
}

void SpriteManager::AddSprite(Sprite* sprite)
{
	if (SpriteInBatch(sprite))
	{
		return;
	}
	spriteBatch.push_back(sprite);
}

void SpriteManager::RemoveSprite(Sprite* sprite)
{
	if (SpriteInBatch(sprite))
	{
		spriteBatch.erase(std::remove(spriteBatch.begin(), spriteBatch.end(), sprite), spriteBatch.end());

		if (spriteBatch.size() == 0)
		{
			std::vector<Sprite*> vec;
			spriteBatch.swap(vec);
		}
	}
}

void SpriteManager::Update()
{
	for (const auto sprite : spriteBatch)
	{
		sprite->Update();
	}
}

void SpriteManager::Draw()
{
	for (const auto sprite : spriteBatch)
	{
		sprite->Draw();
	}
}

bool SpriteManager::SpriteInBatch(Sprite* sprite)
{
	for (const auto spr : spriteBatch)
	{
		if (spr == sprite)
		{
			return true;
		}
	}

	return false;
}