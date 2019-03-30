/*
<Dylan Higbee>
<June 26th, 2018>
<7:27AM>
<EntityManager.cpp>
<Entity Manager Class Implementation>
*/

#include "stdafx.h"
#include "EntityManager.h"

namespace ECS
{
	EntityManager::EntityManager()
	{
		
	}

	EntityManager::~EntityManager()
	{

	}

	void EntityManager::Initialize()
	{

	}

	void EntityManager::Update(float _deltaTime)
	{
		for (int i = 0; i < entities.size(); i++)
			entities[i]->Update(_deltaTime);
	}

	void EntityManager::ShutDown()
	{

	}

	Entity* EntityManager::CreateEntity(std::string _entityName)
	{
		Entity* newEntity = new Entity(currentEntityID, _entityName);
		entities.insert( std::pair<Entity_ID, Entity*>(currentEntityID, newEntity) );

		currentEntityID++;
		return newEntity;
	}

	void EntityManager::AddEntity(Entity* _entity)
	{
		entities.insert(std::pair<Entity_ID, Entity*>(currentEntityID, _entity));
	}

	void EntityManager::RemoveEntity(Entity* _entity)
	{
		std::map<Entity_ID, Entity*>::iterator iter = entities.find(_entity->GetEntityKey());
		entities.erase(iter);
	}

	Entity* EntityManager::FindEntity(Entity_ID _id)
	{
		std::map<Entity_ID, Entity*>::iterator iter = entities.find(_id);
		return iter->second;
	}


}
