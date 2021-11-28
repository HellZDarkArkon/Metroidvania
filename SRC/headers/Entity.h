#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
	Entity(float pdX, float pdY, SDL_Texture* pTex, int PiX, int PiY);
	~Entity();

	SDL_Rect sdlGetRect();
	float fGetFloatX();
	float fGetFloatY();
	SDL_Texture* sdlGetTexp();

private:
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* Tex;
};