#pragma once

#include "../Component.h"
#include "../../Managers/TextureManager.h"

#include "TransformComponent.h"

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class SpriteComponent : public Component
{
public:
	SpriteComponent(SDL_Texture* texture, const glm::vec2& resolution)
		: m_Resolution(resolution)
	{
		m_Texture = texture;
		m_SrcRect.x = 0;
		m_SrcRect.y = 0;
		m_SrcRect.w = static_cast<int>(m_Resolution.x);
		m_SrcRect.h = static_cast<int>(m_Resolution.y);
	}

	void Init() override
	{
		m_Transform = owner->GetComponent<TransformComponent>();
	}

	void Update(float time) override
	{
		m_DestRect.x = static_cast<int>(m_Transform->position.x - m_DestRect.w / 2);
		m_DestRect.y = static_cast<int>(m_Transform->position.y - m_DestRect.h / 2);
		m_DestRect.w = static_cast<int>(m_Resolution.x * m_Transform->scale.x);
		m_DestRect.h = static_cast<int>(m_Resolution.y * m_Transform->scale.y);
	}

	void Render(SDL_Renderer* renderer) override
	{
		SDL_Point center = { 512, 512 };
		SDL_RenderCopyEx(renderer, m_Texture, &m_SrcRect, &m_DestRect, NULL, NULL, m_Flip);
	}


private:
	TransformComponent* m_Transform;

	SDL_Texture* m_Texture;
	SDL_Rect m_SrcRect;
	SDL_Rect m_DestRect;
	glm::vec2 m_Resolution;

	SDL_RendererFlip m_Flip = SDL_FLIP_NONE;
};