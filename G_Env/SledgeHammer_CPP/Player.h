#pragma once
#include "Point2D.h"
#include "Vector2D.h"
#include <SDL.h>

class Player
{
public:
	Player() = default;
	~Player();
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;

	void Initialize();
	void Update();
	void Draw();

private:
	void HandleBaseInput();
	void HandleGunInput();
	void CalculateDirectionVector(Vector2D& tempVec);
	void Shoot();

	// Base Sprite
	SDL_Rect baseSrc {};
	SDL_Rect baseClip {};
	SDL_Texture* basetexture;
	float baseAngle { 0 };
	SDL_Point baseAnchor {};
	const int baseTextureWidth { 88 };
	const int baseTextureHeight { 74 };

	// Gun Sprite
	SDL_Rect gunSrc {};
	SDL_Rect gunClip {};
	SDL_Texture* guntexture;
	float gunAngle { 0 };
	SDL_Point gunAnchor {};
	const int gunTextureWidth { 90 };
	const int gunTextureHeight { 52 };
	const int gunOffset { 26 };

	// Cross Hair Sprite
	SDL_Rect crossSrc {};
	SDL_Rect crossClip {};
	SDL_Texture* crosshairTexture;
	float crossAngle { 0 };
	SDL_Point crossAnchor { 0 };
	const int crossTextureDim { 16 };
	const int crossHairOffset { crossTextureDim / 2 };

	Vector2D position {};
	Vector2D direction {};
	Vector2D originVec {};
	Vector2D aimVector {};
	SDL_Point mousePoint {};	
	Vector2D gunLocation {};

	bool canShoot = true;
	const int bulletOffset { 55 };	
	const float movementSpeed { 2.0f };
	const float rotationSpeed { 0.4f };
	const float rotationSpeedMultiplier { 2.0f };
};