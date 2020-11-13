#pragma once

#include "EntityComponents/EntityManager.h"
#include "Managers/TextureManager.h"

#include <memory>
#include <iostream>

class SceneManager;
class Scene
{
public:
	Scene(SDL_Renderer* renderer, SceneManager& sceneManager)
		: m_Renderer(renderer)
		, m_SceneManager(&sceneManager)
	{
		m_EntityManager.reset(new EntityManager());
		m_TextureManager.reset(new TextureManager(m_Renderer));
	}
	~Scene()
	{
	}

	virtual void OnCreate() = 0;
	virtual void OnDestroy() = 0;

	virtual void Update(float time) = 0;
	virtual void PollEvents(SDL_Event& event) = 0;

	void UpdateScene(float time)
	{
		Update(time);

		if (!m_EntityManager->IsEmpty())
			m_EntityManager->Update(time);
	}
	void RenderScene()
	{
		if (!m_EntityManager->IsEmpty())
			m_EntityManager->Render(m_Renderer);
	}

protected:
	SDL_Renderer* m_Renderer;
	std::unique_ptr<EntityManager> m_EntityManager;
	std::unique_ptr<TextureManager> m_TextureManager;
	std::unique_ptr<SceneManager> m_SceneManager;
};