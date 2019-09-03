#ifndef ENTITY_H
#define ENTITY_H

/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<Entity.h>
<Entity Class Declaration>
*/

#include "Component.h"

#include <typeindex>
#include <memory>
#include <vector>

#include "Haze_Functions_STD.h"

namespace ECS
{
	class Entity
	{

	public:

		Entity(const int _ENTITY_KEY);
		Entity(const int _ENTITY_KEY, std::string _name);

		~Entity();

		void Update(float _deltaTime);

		const Entity_ID								GetEntityKey()	{ return ENTITY_KEY; }
		const std::string							GetEntityName() { return entityName; }

		template< class ComponentType>
		void										AddComponent(ComponentType* _component);

		template< class ComponentType >
		ComponentType*								GetComponent();

		template< class ComponentType >
		std::vector< ComponentType * >				GetComponents();

		template< class ComponentType>
		bool										RemoveComponent();

		template< class ComponentType >
		int											RemoveComponents();

		template< class ComponentType >
		bool										Contains();

	private:

		Entity_ID		ENTITY_KEY;
		std::string		entityName;

		std::vector< std::unique_ptr<Component> > components;
	};

	template< class ComponentType >
	void Entity::AddComponent(ComponentType* _component)
	{
		Haze_Functions_STD::console(this->entityName);
		Haze_Functions_STD::console("Add Component: ");
		Haze_Functions_STD::console(this->ENTITY_KEY);
		Haze_Functions_STD::console(typeid(ComponentType).name());

		dynamic_cast<Component*>(_component)->owner = this;

		components.emplace_back(std::make_unique< ComponentType >(*_component));
	}

	template< class ComponentType >
	ComponentType * Entity::GetComponent() 
	{
		for (auto && component : components) 
		{
			if (component->isClassType(ComponentType::Type))
				return static_cast< ComponentType * >(component.get());
		}

		return nullptr;
	}

	template< class ComponentType >
	std::vector< ComponentType * > Entity::GetComponents()
	{
		std::vector< ComponentType * > componentsOfType;

		for (auto && component : components)
		{
			if (component->isClassType(ComponentType::Type))
				componentsOfType.emplace_back(static_cast< ComponentType * >(component.get()));
		}

		return componentsOfType;
	}

	template< class ComponentType >
	bool Entity::RemoveComponent() 
	{
		Haze_Functions_STD::console(this->entityName);
		Haze_Functions_STD::console("Remove Component: ");
		Haze_Functions_STD::console(typeid(ComponentType).name());

		if (components.empty())
			return false;

		auto index = std::find_if(components.begin(), components.end(), [classType = ComponentType::Type](auto & component) 
		{ return component->isClassType(classType); });

		bool success = index != components.end();

		if (success)
			components.erase(index);

		return success;
	}

	template< class ComponentType >
	int Entity::RemoveComponents() 
	{
		Haze_Functions_STD::console(this->entityName);
		Haze_Functions_STD::console("Remove Components: ");

		if (components.empty())
			return 0;

		int numRemoved = 0;
		bool success = false;

		do 
		{
			auto index = std::find_if(components.begin(), components.end(), [classType = ComponentType::Type](auto & component) 
			{ return component->isClassType(classType); });

			success = index != components.end();

			if (success) 
			{
				console(typeid(components[i]).name());
				components.erase(index);
				++numRemoved;
			}

		} while (success);

		return numRemoved;
	}

	template< class ComponentType >
	bool Entity::Contains()
	{
		for (auto && component : components)
		{
			if (component->isClassType(ComponentType::Type))
				return true;
		}

		return false;
	}
}

#endif

