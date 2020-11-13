#include "TextureManager.h"

#include <SDL2\SDL_image.h>
#include <iostream>

TextureManager::TextureManager(SDL_Renderer* renderer)
	: m_Renderer(renderer)
{
}

TextureManager::~TextureManager()
{
}

void TextureManager::ClearData()
{
	for (auto& texture : m_Textures)
	{
		delete texture.second;
	}
	m_Textures.clear();
}

void TextureManager::AddTexture(const std::string& textureID, const char* filepath)
{
	SDL_Surface* surface = IMG_Load(filepath);
	if (!surface)
		std::cout << "Failed to create surface : " << SDL_GetError() << std::endl;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
	if (!surface)
		std::cout << "Failed to create texture : " << SDL_GetError() << std::endl;

	SDL_FreeSurface(surface);
	m_Textures.emplace(textureID, texture);
}

SDL_Texture* TextureManager::GetTexture(const std::string& textureID)
{
	return m_Textures[textureID];
}
