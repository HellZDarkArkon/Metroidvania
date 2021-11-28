#include "Entity.h"

Entity::Entity(Vector2f pfPos, SDL_Texture* pTex, Vector2i piPos, Vector2i piSize) : fPos(pfPos), iSize(piSize), iPos(piPos), Tex(pTex)
{
	srcFrame.x = 32*piPos.x;
	srcFrame.y = 0;
	srcFrame.w = 32;
	srcFrame.h = 32;

	currentFrame.x = pfPos.x;
	currentFrame.y = pfPos.y;
	currentFrame.w = piSize.x;
	currentFrame.h = piSize.y*piPos.y;
}

Entity::~Entity()
{

}

SDL_Rect Entity::sdlGetDstRect()
{
	return currentFrame;
}

SDL_Rect Entity::sdlGetSrcRect()
{
	return srcFrame;
}

SDL_Texture* Entity::sdlGetTexp()
{
	return Tex;
}

// float Entity::fGetFloatX()
// {
// 	return x;
// }

// float Entity::fGetFloatY()
// {
// 	return y;
// }

// float Entity::fGetFloatW()
// {
// 	return w;
// }

// float Entity::fGetFloatH()
// {
// 	return h;
// }