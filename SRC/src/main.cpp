/// Metroidvania main.cpp ///

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "Entity.h"


int main(int argc, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout<<"SDL Initialization failed: "<<SDL_GetError() << std::endl;
	}

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout<<"IMG_init initialization failed: " << SDL_GetError() << std::endl;

	RenderWindow window("game", 800, 600);
	SDL_Texture* collisionSheet = window.sdlLoadTexture("ASSETS/IMG/SPR/spr_metroidvania_col.png");
	Entity collisionTypes[7] = 
		{Entity(0x00, 0x60, collisionSheet, 0, 1), 
		 Entity(0x20, 0x40, collisionSheet, 1, 2), 
		 Entity(0x40, 0x60, collisionSheet, 2, 1),
		 Entity(0x60, 0x60, collisionSheet, 3, 1),
		 Entity(0x80, 0x60, collisionSheet, 4, 1),
		 Entity(0xA0, 0x60, collisionSheet, 5, 1),
		 Entity(0xC0, 0x60, collisionSheet, 6, 1)
		};

	bool bRunning = true;
	SDL_Event event;

	while(bRunning)
	{
		 while(SDL_PollEvent(&event))
		 {
		 	if(event.type == SDL_QUIT)
		 		bRunning = false;
		 }

		 window.Clear();


		 for(int i = 0; i<7; i++)
		 {
		 	window.Render(collisionTypes[i]);
		 }
		 window.Display();

	}

	window.CleanUp();
	SDL_Quit();


	return 0;
}