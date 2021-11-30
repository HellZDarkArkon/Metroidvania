/// Metroidvania main.cpp ///

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "Game.h"


int main(int argc, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout<<"SDL Initialization failed: "<<SDL_GetError() << std::endl;
	}

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout<<"IMG_init initialization failed: " << SDL_GetError() << std::endl;

	RenderWindow window("game", 800, 600);
	Game g(window, "ASSETS/IMG/SPR/spr_metroidvania_col.png");

	 // Map map(Vector2i(13,11), "ASSETS/DATA/MAPS/testmap.txt");
	 g.loadMap(Vector2i(13,11), "ASSETS/DATA/MAPS/testmap.txt");
	 g.loadEntities(false);
	 	
	while(g.bRunning)
	{
		g.update(window);
	}

	window.CleanUp();
	SDL_Quit();


	return 0;
}