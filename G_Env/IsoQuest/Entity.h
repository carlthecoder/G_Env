#pragma once
#include "Component.h"
#include <iostream>
#include <memory>
#include <vector>

class Entity
{
public:
	Entity() = default;
	~Entity() { std::cout << "Entity is destroyed.\n"; }

	void AddComponent(Component* component);
	Component* GetComponent(ComponentTypes type);

private:
	std::vector<std::unique_ptr<Component>> components;
};