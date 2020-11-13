#pragma once

#include "Entity.h"
#include "Component.h"

class EntityManager
{
public:
	void Update(float time);
	void Render(SDL_Renderer* renderer);
	void ClearData();
	bool IsEmpty();
	Entity& CreateEntity(const std::string& entityName);
	Entity& GetEntity(const std::string& entityName);
	std::vector<Entity*> GetEntities() const;
	unsigned int GetEntityCount() const;

private:
	std::vector<Entity*> m_Entities;
};