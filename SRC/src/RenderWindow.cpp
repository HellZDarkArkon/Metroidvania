#include <iostream>

#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* pStrTitle, int pIntWidth, int pIntHeight) : window(NULL), render(NULL)
{
	window = SDL_CreateWindow(pStrTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, pIntWidth, pIntHeight, SDL_WINDOW_SHOWN);

	if(window == NULL)
	{
		std::cout<<"Window failed to initialize: "<<SDL_GetError()<<std::endl;
	}

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

RenderWindow::~RenderWindow()
{

}

SDL_Texture* RenderWindow::sdlLoadTexture(const char* pFilePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(render, pFilePath);

	if(texture == NULL)
	{
		std::cout<<"Failed to load texture. Error: "<<SDL_GetError()<<std::endl;
	}

	return texture;
}

void RenderWindow::CleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::Clear()
{
	SDL_RenderClear(render);
}

void RenderWindow::Render(Entity& pEntity)
{
	sRect = pEntity.sdlGetRect();
	dRect.x = pEntity.fGetFloatX();
	dRect.y = pEntity.fGetFloatY();
	dRect.w = pEntity.sdlGetRect().w;
	dRect.h = pEntity.sdlGetRect().h;
	SDL_RenderCopy(render, pEntity.sdlGetTexp(), &sRect, &dRect);
}

void RenderWindow::Display()
{
	SDL_RenderPresent(render);
}

void RenderWindow::RectXY(SDL_Rect pRect, int pRectX, int pRectY)
{
	pRect.x = pRectX;
	pRect.y = pRectY;
}

void RenderWindow::RectWH(SDL_Rect pRect, int pRectW, int pRectH)
{
	pRect.w = pRectW;
	pRect.h = pRectH;
}

SDL_Rect RenderWindow::sdlGetSrcRect()
{
	return sRect;
}

SDL_Rect RenderWindow::sdlGetDstRect()
{
	return dRect;
}

void RenderWindow::sdlSetSrcRect(SDL_Rect pRect)
{
	sRect = pRect;
}

void RenderWindow::sdlSetDstRect(SDL_Rect pRect)
{
	dRect = pRect;
}