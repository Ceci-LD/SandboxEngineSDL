#pragma once

#include "Scene/SceneManager.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string>

struct WindowProps
{
	std::string Title;
	unsigned int Width;
	unsigned int Height;

	WindowProps(const std::string& title = "Sandbox Engine", 
				unsigned int width = 1280, 
				unsigned int height = 720)
		: Title(title), Width(width), Height(height) {}
};

class Game
{
public:
	Game(const WindowProps& props = WindowProps());
	~Game();

	bool Init();
	void Release();

	void ProcessInput();
	void Update(float time);
	void Render();

	void LoadScenes();

	inline bool const IsRunning() const { return m_IsRunning; }

private:
	SceneManager m_SceneManager;

private:
	WindowProps m_Props;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	bool m_IsRunning;

	bool loaded = false;
};
