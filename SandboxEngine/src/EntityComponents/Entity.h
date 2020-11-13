#pragma once

#include "Component.h"

#include <vector>
#include <string>
#include <map>
#include <typeinfo>

class EntityManager;
class Entity
{
public:
	Entity(EntityManager& manager)
		: m_Manager(&manager)
		, m_IsActive(true)
	{
	}

	Entity(EntityManager& manager, const std::string& name)
		: m_Manager(&manager)
		, m_IsActive(true)
		, m_Name(name)
	{
	}

	~Entity()
	{
		m_IsActive = false;
		for (auto component : m_Components)
			delete component;
		m_Components.clear();
	}

	inline void Update(float time)
	{
		if (m_IsActive)
		{
			for (auto& component : m_Components)
			{
				component->Update(time);
			}
		}
	}

	inline void Render(SDL_Renderer* renderer)
	{
		if (m_IsActive)
		{
			for (auto& component : m_Components)
			{
				component->Render(renderer);
			}
		}
	}

	template<typename T, typename... Targs>
	T& AddComponent(Targs&&... args)
	{
		T* component = new T(std::forward<Targs>(args)...);
		component->owner = this;
		m_Components.emplace_back(component);
		m_ComponentTypeMap[&typeid(*component)] = component;
		component->Init();
		return *component;
	}

	template <typename T>
	T* GetComponent()
	{
		return static_cast<T*>(m_ComponentTypeMap[&typeid(T)]);
	}

	inline void SetActive(bool active)
	{
		m_IsActive = active;
	}

	bool const IsActive() const { return m_IsActive; }

	inline const std::string& GetName() const { return m_Name; }

private:
	EntityManager* m_Manager;
	std::vector<Component*> m_Components;
	std::map<const std::type_info*, Component*> m_ComponentTypeMap;

	std::string m_Name;
	bool m_IsActive;
};