#pragma once

#include "../EntityManager.h"
#include "glm/glm.hpp"

#include <SDL2/SDL.h>

#include "../../Game.h"

class TransformComponent : public Component
{
public:
	TransformComponent(const glm::vec2& pos = { 0.0f, 0.0f }, 
		const glm::vec2& vel = { 0.0f, 0.0f }, 
		const glm::vec2& scale = { 1.0f, 1.0f })
		: position(pos)
		, velocity(vel)
		, scale(scale)
	{
	}

	~TransformComponent()
	{
	}

	void Init() override
	{

	}

	void Update(float time) 
	{
		position.x += velocity.x * time;
		position.y += velocity.y * time;
	}

	void Render(SDL_Renderer* renderer) 
	{
	}

public:
	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 scale;

private:
	SDL_Rect rect = {};
};