#include "RenderSystem.h"
#include "TextureManager.h"
#include <iostream>

SpriteComponents RenderSystem::spriteComponents;

void RenderSystem::RegisterSpriteComponent(SpriteComponent* component)
{
	bool contains = false;

	for (auto comp : spriteComponents)
	{
		if (comp == component)
		{
			contains = true;
		}
	}

	if (!contains)
	{
		spriteComponents.push_back(component);

		std::cout << "Registered sprite component in RenderSystem. \n";
	}
}

void RenderSystem::UnregisterSpriteComponent(SpriteComponent* component)
{
	bool contains = false;

	for (auto comp : spriteComponents)
	{
		if (comp == component)
		{
			contains = true;
		}
	}

	if (contains)
	{
		spriteComponents.erase(std::remove(spriteComponents.begin(), spriteComponents.end(), component), spriteComponents.end());
		std::cout << "Unregistered sprite component from RenderSystem. \n";
	}
}

void RenderSystem::Render()
{
	for (auto component : spriteComponents)
	{		
		TextureManager::Render(component->Texture, &component->Src, &component->Dest);
	}
}