#include "Entity.h"

Entity::Entity(float pdX, float pdY, SDL_Texture* pTex, int PiX, int PiY) : x(pdX), y(pdY), Tex(pTex)
{
	currentFrame.x = 32 * PiX;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32*PiY;
}

Entity::~Entity()
{

}

SDL_Rect Entity::sdlGetRect()
{
	return currentFrame;
}

SDL_Texture* Entity::sdlGetTexp()
{
	return Tex;
}

float Entity::fGetFloatX()
{
	return x;
}

float Entity::fGetFloatY()
{
	return y;
}