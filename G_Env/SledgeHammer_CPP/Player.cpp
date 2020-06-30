#include "Bullet.h"
#include "EntityManager.h"
#include "Player.h"
#include "RectHelpers.h"
#include "SpriteManager.h"
#include "VectorHelpers.h"
#include <cmath>
#include <iostream>

extern int windowWidth;
extern int windowHeight;
extern SDL_Renderer* renderer;

Player::~Player()
{
	std::cout << "Player destructed..\n";
}

void Player::Initialize()
{
	basetexture = SpriteManager::LoadTexture("Assets/tank_base_small.png");
	guntexture = SpriteManager::LoadTexture("Assets/tank_gun_small.png");
	crosshairTexture = SpriteManager::LoadTexture("Assets/crosshair_black.png");

	RectHelpers::SetRect(baseSrc, 0, 0, baseTextureWidth, baseTextureHeight);
	RectHelpers::SetRect(baseClip, 0, 0, baseTextureWidth, baseTextureHeight);
	RectHelpers::SetRect(gunSrc, 0, 0, gunTextureWidth, gunTextureHeight);
	RectHelpers::SetRect(gunClip, 0, 0, gunTextureWidth, gunTextureHeight);
	RectHelpers::SetRect(crossSrc, 0, 0, crossTextureDim, crossTextureDim);
	RectHelpers::SetRect(crossClip, 0, 0, crossTextureDim, crossTextureDim);

	// Set the anchor points for the rotation
	baseAnchor.x = baseTextureWidth / 2;;
	baseAnchor.y = baseTextureHeight / 2;
	gunAnchor.x = gunOffset;
	gunAnchor.y = gunOffset;

	// Set the origin vector. i.e. the neutral aim position;
	originVec.x = 1;
	originVec.y = 0;

	// Position player in the the window center
	position.x = windowWidth / 2.f - baseAnchor.x;
	position.y = windowHeight / 2.f - baseAnchor.y;

	baseClip.x = (int)position.x;
	baseClip.y = (int)position.y;
	gunClip.x = baseClip.x + gunOffset;
	gunClip.y = baseClip.y + gunOffset;
}

void Player::Update()
{
	HandleBaseInput();
	HandleGunInput();
}

void Player::Draw()
{
	SDL_RenderCopyEx(renderer, crosshairTexture, &crossSrc, &crossClip, crossAngle, &crossAnchor, SDL_FLIP_NONE);
	SDL_RenderCopyEx(renderer, basetexture, &baseSrc, &baseClip, baseAngle, &baseAnchor, SDL_FLIP_NONE);
	SDL_RenderCopyEx(renderer, guntexture, &gunSrc, &gunClip, gunAngle, &gunAnchor, SDL_FLIP_NONE);
}

void Player::HandleBaseInput()
{
	auto keystate = SDL_GetKeyboardState(0);

	if (keystate[SDL_SCANCODE_A])
	{
		baseAngle -= rotationSpeed * rotationSpeedMultiplier;
		if (baseAngle < 0)
		{
			baseAngle = 359;
		}
	}

	if (keystate[SDL_SCANCODE_D])
	{
		baseAngle += rotationSpeed * rotationSpeedMultiplier;
		if (baseAngle >= 360)
		{
			baseAngle = 0;
		}
	}

	if (keystate[SDL_SCANCODE_W])
	{
		CalculateDirectionVector(direction);

		position.x += direction.x * movementSpeed;
		position.y += direction.y * movementSpeed;
	}

	if (keystate[SDL_SCANCODE_S])
	{
		CalculateDirectionVector(direction);

		position.x -= direction.x * movementSpeed;
		position.y -= direction.y * movementSpeed;
	}

	baseClip.x = (int)position.x;
	baseClip.y = (int)position.y;
	gunClip.x = baseClip.x + baseAnchor.x - gunOffset;
	gunClip.y = baseClip.y + baseAnchor.y - gunOffset;
}

void Player::HandleGunInput()
{
	// Get mouse position
	auto state = SDL_GetMouseState(&mousePoint.x, &mousePoint.y);
	crossClip.x = mousePoint.x - crossHairOffset;
	crossClip.y = mousePoint.y - crossHairOffset;

	// Calculate gun location
	gunLocation.x = position.x + baseAnchor.x;
	gunLocation.y = position.y + baseAnchor.y;

	// calculate the vector from the gun to mousepoint;
	aimVector.x =(float)(mousePoint.x - gunLocation.x);
	aimVector.y =(float)(mousePoint.y - gunLocation.y);

	// calculate the aim angle
	gunAngle = VectorHelpers::GetVectorsAngle(aimVector, originVec);
	gunAngle *= (float)(180 / M_PI);

	if (mousePoint.y < gunLocation.y)
	{
		gunAngle = 360 - gunAngle;
	}

	if (state == SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		Shoot();
	}
	else if (state == 0)
	{
		canShoot = true;
	}
}

void Player::CalculateDirectionVector(Vector2D& dirVec)
{
	float rad = (float)(baseAngle * M_PI / 180.f);
	dirVec.x = std::cos(rad);
	dirVec.y = std::sin(rad);
}

void Player::Shoot()
{
	if (!canShoot)
	{
		return;
	}
	
	auto aimDirections = VectorHelpers::GetNormalizedVector(aimVector);
	Vector2D bulletLocation {
		gunLocation.x + bulletOffset * aimDirections.x,
		gunLocation.y + bulletOffset * aimDirections.y 
	};	

	auto bullet = new Bullet(bulletLocation, aimDirections, gunAngle);
	EntityManager::AddEntity(bullet);
	SpriteManager::AddSprite(bullet->GetSprite());
	canShoot = false;
}