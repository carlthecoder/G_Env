#pragma once
#include "Entities.h"
#include <vector>

class EntityManager
{
public:
	EntityManager() = default;
	EntityManager(const EntityManager&) = delete;
	EntityManager& operator=(const EntityManager&) = delete;
	~EntityManager() = default;

	/// <summary>
	/// Adds an entity to the manager. This will allow the manager to call update on the entity.
	/// </summary>
	static void AddEntity(Entity* entity);

	/// <summary>
	/// Removes an entity from the manager. This will stop the manager from calling update on the entity.
	/// </summary>
	static void RemoveEntity(Entity* entity);

	/// <summary>
	/// Cycles through all the entities registered in the manager and calls update on them.
	/// </summary>
	static void Update();

private:
	static bool EntityRegistered(Entity* entity);

	static std::vector<Entity*> entities;
};