#include "TextureManager.h"
#include "Engine.h"
#include <SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char* filePath)
{
	SDL_Surface* tmpSurface = IMG_Load(filePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return texture;
}

void TextureManager::Render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst)
{
	SDL_RenderCopy(Engine::renderer, texture, src, dst);
}
