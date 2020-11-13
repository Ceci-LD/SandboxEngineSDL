#pragma once

#include "Scene/Scene.h"
#include "EntityComponents/BaseComponents.h"

#include <iostream>
#include "Grid.h"

class ExampleScene : public Scene
{
public:
	ExampleScene(SDL_Renderer* renderer, SceneManager& sceneManager)
		: Scene(renderer, sceneManager)
	{
		m_TextureManager->AddTexture("tile", "res/isoBox.png");

		for (size_t i = 0; i < grid.positions.size(); i++)
		{
			Entity& tile = m_EntityManager->CreateEntity(std::to_string(i));
			tile.AddComponent<TransformComponent>(
				grid.positions[i],
				glm::vec2(0, 0),
				glm::vec2(grid.scale));
			tile.AddComponent<SpriteComponent>(m_TextureManager->GetTexture("tile"), grid.size);
			//Add Animation Component

			tiles.push_back(&tile);
		}
	}

	virtual void OnCreate() override
	{
	}

	virtual void Update(float time) override
	{

	}

	virtual void PollEvents(SDL_Event& event) override
	{

	}

	virtual void OnDestroy() override
	{
	}

private:
	Grid grid;
	std::vector<Entity*> tiles;
};