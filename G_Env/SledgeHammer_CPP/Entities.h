#pragma once
#include "Sprite.h"
#include "Vector2D.h"
#include <iostream>

class Entity
{
public:
	Entity() = default;
	virtual ~Entity() { std::cout << "Entity destructed..\n"; };

	/// <summary>
	/// Entities are equal if they point the same object and thus have the same memory address.
	/// </summary>
	bool operator==(Entity* other) { return this == other; }

	/// <summary>
	/// Updates an Entity.
	/// Typically this function will be called from an EntityManager that updates all the entities in its own Update method.
	/// </summary>
	virtual void Update() {};
};

class DrawableEntity : public Entity
{
public:
	/// <summary>
	/// The constructor for a drawableEntity. A class deriving from DrawableEntity must call this constructor so that it's sprite can be initialized.
	/// <summary>
	DrawableEntity(const char* filePath, Vector2D position, Vector2D sheetsize, Vector2D texturesize, Vector2D currentframe, float angle = 0, float scale = 1, int anchorX = 0, int anchorY = 0);
	virtual ~DrawableEntity() { std::cout << "DrawableEntity destructed!\n"; };

	/// <summary>
	/// Returns a pointer to a DrawableEntity's Sprite.
	/// GetSprite is declared inline.
	/// </summary>
	Sprite* GetSprite() { return &sprite; }

protected:
	Sprite sprite;
};