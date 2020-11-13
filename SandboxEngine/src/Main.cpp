#include <iostream>

#include "Game.h"

int main(int argc, char** argv) 
{
	Game* game = new Game();

	Uint32 lastFrameTime = 0;
	float fps = 60;

	if (game->Init())
	{
		while (game->IsRunning())
		{
			while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastFrameTime + 1000 / fps));
			float dt = (SDL_GetTicks() - lastFrameTime) / 1000.0f;
			dt = (dt > 0.05f) ? 0.05f : dt;
			lastFrameTime = SDL_GetTicks();

			game->ProcessInput();
			game->Update(dt);
			game->Render();
		}
	}
	game->Release();

	return 0;
}
