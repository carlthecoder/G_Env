#pragma once
#include "Vector2D.h"
#include <SDL.h>
#include <iostream>

class Sprite
{
public:
	Sprite(const char* filePath, Vector2D position, Vector2D sheetsize, Vector2D texturesize, Vector2D currentframe, float angle = 0, float scale = 1, int anchorX = 0, int anchorY = 0);
	~Sprite() 
	{
		SDL_DestroyTexture(texture);
		std::cout << "Sprite destructed\n";
	}

	/// <summary>
	/// Sprites are equal if they point to the same object and thus have the same memory address.
	/// </summary>
	bool operator==(Sprite* other) { return this == other; }

	/// <summary>
	/// Updates a Sprite.
	/// Typically this function will be called from a SpriteManager that updates all the sprites in its own Update method.
	/// </summary>
	virtual void Update();

	/// <summary>
	/// Draws the Sprite.
	/// Typically this function will be called from a SpriteManager that draws all the sprites in its own Update method.
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// Sets the position of the Sprite.
	/// Typically this function is called when a DrawableEntity wants to update its position on the screen.
	/// </summary>
	void SetPosition(Vector2D position)
	{
		pos = position;
	}

private:
	SDL_Texture* texture;
	Vector2D pos;
	Vector2D sheetSize;
	Vector2D textureSize;
	Vector2D currentFrame;
	SDL_Rect src;
	SDL_Rect clip;
	SDL_Point anchor {};
	float angle { 0 };
};