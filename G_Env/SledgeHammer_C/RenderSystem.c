#include "RenderSystem.h"

SDL_Texture* LoadTexture(char* filePath, SDL_Renderer* renderer)
{
	SDL_Surface* s = IMG_Load(filePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);

	return texture;
}

void InitializeSprite(Sprite* sprite,
		char* filePath,
		Vector2D position,
		Vector2D sheetSize,
		Vector2D textureSize,
		Vector2D currentFrame,
		SDL_Point anchor,
		double angle,
		double scale,
		SDL_Renderer* renderer)
{
	sprite->texture = LoadTexture(filePath, renderer);
	sprite->position = position;
	sprite->sheetSize = sheetSize;
	sprite->textureSize = textureSize;
	sprite->currentFrame = currentFrame;
	sprite->anchor = anchor;
	sprite->angle = angle;

	SdlRectInitialize(
		&sprite->src,
		(int)(currentFrame.x * textureSize.x),
		(int)(currentFrame.y * textureSize.y),
		(int)(textureSize.x),
		(int)(textureSize.y));

	SdlRectInitialize(
		&sprite->clip,
		(int)position.x,
		(int)position.y,
		(int)(textureSize.x * scale),
		(int)(textureSize.y * scale));
}

void DrawSprite(Sprite* sprite, SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, sprite->texture, &sprite->src, &sprite->clip, sprite->angle, &sprite->anchor, SDL_FLIP_NONE);
}

void DestroySprite(Sprite* sprite)
{
	SDL_DestroyTexture(sprite->texture);
	sprite->texture = NULL;
	printf("Sprite destroyed.\n");
}