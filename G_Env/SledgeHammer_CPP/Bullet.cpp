#include "Bullet.h"
#include "EntityManager.h"
#include "SpriteManager.h"

extern int windowWidth;
extern int windowHeight;

Bullet::Bullet(Vector2D position, Vector2D direction, float angle)
	:
	position { position },
	direction { direction },
	DrawableEntity( "Assets/bullet.png", position, Vector2D(0, 0), Vector2D(30, 8), Vector2D(0, 0), angle, 0.5f )
{}

void Bullet::Update()
{
	position.x += direction.x * speed;
	position.y += direction.y * speed;

	if (position.x < 0 || position.x >= windowWidth || position.y < 0 || position.y >= windowHeight)
	{
		EntityManager::RemoveEntity(this);
		SpriteManager::RemoveSprite(&sprite);
		return;
	}

	sprite.SetPosition(position);
}