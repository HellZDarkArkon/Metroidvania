#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.h"

class RenderWindow
{
public:
	RenderWindow(const char* pStrTitle, int pIntWidth, int pIntHeight);
	~RenderWindow();

	void CleanUp();
	void Clear();
	void Render(Entity& pEntity);
	void Display();

	void RectXY(SDL_Rect pRect, int pRectX, int pRectY);
	void RectWH(SDL_Rect pRect, int pRectW, int pRectH);

	SDL_Texture* sdlLoadTexture(const char* pFilePath);

	SDL_Rect sdlGetSrcRect();
	SDL_Rect sdlGetDstRect();

	void sdlSetSrcRect(SDL_Rect pRect);
	void sdlSetDstRect(SDL_Rect pRect);
private:
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_Rect sRect, dRect;
	

};