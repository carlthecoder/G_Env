#pragma once
#include "ComponentTypes.h"
#include <iostream>

class Component
{
public:
	Component(ComponentTypes type) : componentType(type) {};

	virtual ~Component() { std::cout << "Component is destroyed.\n"; } 

	ComponentTypes GetComponentType()
	{
		return componentType;
	}

private:
	ComponentTypes componentType;
};