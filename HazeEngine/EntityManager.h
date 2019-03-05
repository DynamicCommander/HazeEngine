#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<EntityManager.cpp>
<Entity Manager Class Declaration>
*/

#include "CSystem.h"

#include "Entity.h"
#include "Component.h"

#include <map>

namespace ECS
{                    
	class EntityManager : public Haze_Engine::CSystem
	{

	public:
		EntityManager();
		~EntityManager();

		void Initialize(Haze_Engine::HazeEngine* _engine);
		void Update(float _deltaTime);
		void ShutDown();

		Entity* CreateEntity(std::string _entityName);

		void AddEntity(Entity* _entity);
		void RemoveEntity(Entity* _entity);

		Entity* FindEntity(Entity_ID _id);

		template <class T>
		Entity* FindEntityByType();

		template <class T>
		std::vector<Entity*> FindEntitiesByType();

	private:
		Haze_Engine::HazeEngine * hzEngine;

		int currentEntityID = 0;
		std::map<Entity_ID, Entity*> entities;
	};


	template <class T>
	Entity* EntityManager::FindEntityByType()
	{
		for (std::map<Entity_ID, Entity*>::iterator iter = entities.begin(); iter != entities.end(); iter++)
		{
			if (iter->second->Contains<T>())
			{
				return iter->second;
			}
		}
	}

	template <class T>
	std::vector<Entity*> EntityManager::FindEntitiesByType()
	{
		std::vector<Entity*> entitiesByName;
		for (std::map<Entity_ID, Entity*>::iterator iter = entities.begin(); iter != entities.end(); iter++)
		{
			if (iter->second->Contains<T>())
			{
				entitiesByName.push_back(iter->second);
			}
		}

		return entitiesByName;
	}

}

#endif

