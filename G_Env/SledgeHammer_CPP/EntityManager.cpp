#include "EntityManager.h"

std::vector<Entity*> EntityManager::entities {};

void EntityManager::AddEntity(Entity* entity)
{
	if (EntityRegistered(entity))
	{
		return;
	}

	entities.push_back(entity);	
}

void EntityManager::RemoveEntity(Entity* entity)
{
	if (EntityRegistered(entity))
	{
		entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());

		delete entity;
		entity = nullptr;

		if (entities.size() == 0)
		{
			std::vector<Entity*> vec;
			entities.swap(vec);
		}
	}
}

void EntityManager::Update()
{
	for (size_t i = 0; i < entities.size(); ++i)
	{
		entities[i]->Update();
	}
}

bool EntityManager::EntityRegistered(Entity* entity)
{
	for (const auto ent : entities)
	{
		if (ent == entity)
		{
			return true;
		}
	}
	return false;
}