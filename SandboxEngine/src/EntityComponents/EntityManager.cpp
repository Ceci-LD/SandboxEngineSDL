#include "EntityManager.h"

void EntityManager::Update(float time)
{
	for (auto& entity : m_Entities)
	{
		entity->Update(time);
	}
}

void EntityManager::Render(SDL_Renderer* renderer)
{
	for (auto& entity : m_Entities)
	{
		entity->Render(renderer);
	}
}

void EntityManager::ClearData()
{
	for (auto& entity : m_Entities)
	{
		delete entity;
	}
	m_Entities.clear();
}

bool EntityManager::IsEmpty()
{
	return m_Entities.size() == 0;
}

Entity& EntityManager::CreateEntity(const std::string& entityName)
{
	Entity* entity = new Entity(*this, entityName);
	m_Entities.push_back(entity);
	return *entity;
}

Entity& EntityManager::GetEntity(const std::string& entityName)
{
	for (size_t i = 0; i < m_Entities.size(); i++)
	{
		if (m_Entities[i]->GetName() == entityName)
			return *m_Entities[i];
	}
}

std::vector<Entity*> EntityManager::GetEntities() const
{
	std::vector<Entity*> entities;
	entities.reserve(m_Entities.size());
	for (auto& entity : m_Entities)
	{
		entities.emplace_back(entity);
	}
	return entities;
}

unsigned int EntityManager::GetEntityCount() const
{
	return (unsigned int)m_Entities.size();
}
