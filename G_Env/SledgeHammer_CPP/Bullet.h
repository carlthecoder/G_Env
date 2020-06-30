#pragma once
#include "Entities.h"
#include "Sprite.h"
#include "Vector2D.h"
#include <SDL.h>
#include <iostream>

class Bullet final: public DrawableEntity
{
public:
	Bullet(Vector2D position, Vector2D direction, float angle = 0);
	~Bullet() override { std::cout << "Bullet destructed..\n"; }

	/// <summary>
	/// Updates the Bullet's flight trajectory and impact.
	/// Typically this function will be called through polymorphism by an EntityManager.
	/// </summary>
	virtual void Update() override;

private:
	Vector2D position;
	Vector2D direction;
	float speed = 20.f;
};