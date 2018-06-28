/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<Entity.cpp>
<Entity Class Implementation>
*/

#include "stdafx.h"

#include "Entity.h"

namespace ECS
{
	Entity::Entity(const int _ENTITY_KEY)
	{
		ENTITY_KEY = ENTITY_KEY;
		entityName = nullptr;
		components = std::vector< std::unique_ptr< Component> >();
	}

	Entity::Entity(const int _ENTITY_KEY, std::string _name)
	{
		ENTITY_KEY = ENTITY_KEY;
		entityName = _name;
		components = std::vector< std::unique_ptr< Component> >();
	}

	Entity::~Entity()
	{

	}

	void Entity::AddComponent(Component* _component)
	{
		components.emplace_back(_component);
	}

}