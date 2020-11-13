#pragma once

#include "../EntityComponents/EntityManager.h"
#include <map>
#include <string>

class TextureManager
{
public:
	TextureManager(SDL_Renderer* renderer);
	~TextureManager();
	void ClearData();
	void AddTexture(const std::string& textureID, const char* filepath);
	SDL_Texture* GetTexture(const std::string& textureID);

private:
	std::map<std::string, SDL_Texture*> m_Textures;
	SDL_Renderer* m_Renderer;
};