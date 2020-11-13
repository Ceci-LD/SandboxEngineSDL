# SandboxEngineSDL

This project was hight level attempt at game engine development using the SDL2 library.
Although you can create some simple games with this engine, its purpose was for learning the basics.

What I learned
- Creating an Entity Component System with basic Transform and Sprite components
- Asset management
- Scene management
- Basic game development logic

Improvements
- Making the entity component system render components that need to be rendererd (i.e. inherit from some "Renderable" interface)
- Improve the input system as currently the polled SDL_Event is being propagated through to the scene where it will be handled.
- General memory management using smart pointers instead of raw pointers.
