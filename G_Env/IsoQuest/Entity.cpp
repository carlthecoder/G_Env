#include "Entity.h"

void Entity::AddComponent(Component* component)
{
	std::unique_ptr<Component> p{ component };
	components.push_back(std::move(p));
}

Component* Entity::GetComponent(ComponentTypes type)
{
	for (auto& component : components)
	{
		if (component->GetComponentType() == type)
		{
			return component.get();
		}
	}

	return nullptr;
}