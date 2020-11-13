#pragma once

#include <SDL2/SDL.h>

//Components should inherit from Renderable and Collidable
//in order to optimize the ECS a little bit better

class Entity;
class Component
{
public:
	Entity* owner;
	virtual ~Component() {}
	virtual void Init() {}
	virtual void Update(float time) {}
	virtual void Render(SDL_Renderer* renderer) {}
};