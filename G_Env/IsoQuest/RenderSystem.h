#pragma once
#include "Entity.h"
#include "SpriteComponent.h"
#include <memory>
#include <vector>

using SpriteComponents = std::vector<SpriteComponent*>;

class RenderSystem
{
public:
	static void RegisterSpriteComponent(SpriteComponent* component);
	static void UnregisterSpriteComponent(SpriteComponent* component);
	void Render();

private:
	static SpriteComponents spriteComponents;
};