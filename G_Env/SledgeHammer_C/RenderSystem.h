#pragma once
#ifndef TANK_RENDERSYS_H
#define TANK_RENDERSYS_H

#include "Helpers.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2D.h"
#include <SDL.h>

typedef struct Sprite_t
{
	SDL_Texture* texture;
	SDL_Rect src;
	SDL_Rect clip;
	SDL_Point anchor;
	Vector2D position;
	Vector2D sheetSize;
	Vector2D textureSize;
	Vector2D currentFrame;
	double angle;
	double scale;
} Sprite;

typedef struct RenderSystem_t
{
	SDL_Renderer* renderer;
	Sprite* spriteBatch;
} RenderSystem;

SDL_Texture* RenderSystem_LoadTexture(char* filePath, SDL_Renderer* renderer);

void RenderSystem_InitializeSprite(Sprite* sprite,
	char* filePath,
	Vector2D position,
	Vector2D sheetSize,
	Vector2D textureSize,
	Vector2D currentFrame,
	SDL_Point anchor,
	double angle,
	double scale,
	SDL_Renderer*);

void RenderSystem_DrawSprite(Sprite* sprite, SDL_Renderer*);
void RenderSystem_DestroySprite(Sprite* sprite);

#endif // !TANK_RENDERSYS_H