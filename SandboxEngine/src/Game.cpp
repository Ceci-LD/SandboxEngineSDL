#include "Game.h"
#include <iostream>

#include <glm/glm.hpp>

#include "../game/ExampleScene.h"
#include "../game/SplashScreen.h"

Game::Game(const WindowProps& props)
	: m_Props(props)
	, m_IsRunning(false)
{
}

Game::~Game()
{
}

bool Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cerr << "SDL Failed to initialize : " << SDL_GetError() << std::endl;
		return false;
	}

	//Window init
	m_Window = SDL_CreateWindow(
		m_Props.Title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 
		m_Props.Width,
		m_Props.Height,
		SDL_WINDOW_SHOWN);

	if (!m_Window)
	{
		std::cerr << "Window Failed to initialize : " << SDL_GetError() << std::endl;
		return false;
	}

	//Renderer init
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_Renderer)
	{
		std::cerr << "Renderer Failed to initialize : " << SDL_GetError() << std::endl;
		return false;
	}

	m_IsRunning = true;
	LoadScenes();
	return true;
}

void Game::Release()
{

}

void Game::LoadScenes()
{
	m_SceneManager.PushScene(new ExampleScene(m_Renderer, m_SceneManager));
	m_SceneManager.PushScene(new SplashScreen(m_Renderer, m_SceneManager));
}

void Game::ProcessInput()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT: 
			{
				m_IsRunning = false;
				break;
			}
			case SDL_KEYDOWN: 
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					m_IsRunning = false;

				break;
			}

			default:
				break;
		}

		m_SceneManager.GetCurrentScene()->PollEvents(event);
	}
}

void Game::Update(float time)
{
	//Update Scene
	m_SceneManager.GetCurrentScene()->UpdateScene(time);
}

void Game::Render()
{
	//Clear back buffer
	SDL_SetRenderDrawColor(m_Renderer, 51, 51, 51, 255);
	SDL_RenderClear(m_Renderer);

	//Render Scene
	m_SceneManager.GetCurrentScene()->RenderScene();

	//Swap front/back buffers
	SDL_RenderPresent(m_Renderer);
}

