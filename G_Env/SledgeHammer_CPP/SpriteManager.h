#pragma once
#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class SpriteManager
{
public:
	static SDL_Texture* LoadTexture(const char* filepath);

	/// <summary>
	/// Adds a Sprite to the manager. This will allow the manager to call update and draw on the sprite.
	/// </summary>
	static void AddSprite(Sprite* sprite);

	/// <summary>
	/// Removes a Sprite from the manager. This will stop the manager from calling update and draw on the sprite.
	/// </summary>
	static void RemoveSprite(Sprite* sprite);

	/// <summary>
	/// Cycles through all the sprites registered in the manager and calls update on them.
	/// </summary>
	static void Update();

	/// <summary>
	/// Cycles through all the sprites registered in the manager and calls draw on them.
	/// </summary>
	static void Draw();

private:
	static bool SpriteInBatch(Sprite* sprite);

	static std::vector<Sprite*> spriteBatch;
};