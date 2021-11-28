#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Math.h>

class Entity
{
public:
	Entity(Vector2f pfPos, SDL_Texture* pTex, Vector2i piPos, Vector2i piSize);
	~Entity();
	Vector2f& getfPos() {return fPos;}
	Vector2i& getiSize() {return iSize;}
	Vector2i& getiPos() {return iPos;}
	// float fGetFloatX();
	// float fGetFloatY();
	// float fGetFloatW();
	// float fGetFloatH();
	SDL_Rect sdlGetDstRect();
	SDL_Rect sdlGetSrcRect();
	SDL_Texture* sdlGetTexp();

private:
	// float x, y, w, h;
	Vector2f fPos;
	Vector2i iPos; 
	Vector2i iSize;
	SDL_Rect currentFrame, srcFrame;
	SDL_Texture* Tex;
};