/// Metroidvania main.cpp ///

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "Entity.h"
#include "Utils.h"
#include "Map.h"


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

	std::vector<Entity> entities = 
		{
			Entity(Vector2f(((6)+1)*48, (6)*48), collisionSheet, Vector2i(2,2),Vector2i(48,48)),
			Entity(Vector2f(((2)+1)*48, (4)*48), collisionSheet, Vector2i(3,1), Vector2i(48,48)),
			Entity(Vector2f(((7)+1)*48, (3)*48), collisionSheet, Vector2i(3,1), Vector2i(48,48)),
			Entity(Vector2f(((7)+1)*48, (1)*48), collisionSheet, Vector2i(3,1), Vector2i(48,48))
		};
	 Map map(14, 11, "ASSETS/DATA/MAPS/testmap.txt");
	 std::vector<Entity> eMap;
	 int cntX = 0;
	 int cntY = 0;
	 std::cout<<std::endl;
	 for(int i = 0; i < map.iGetVecMap().size(); i++)
	 {
	 	cntX = i % map.iGetMapX();
	 	cntY = i / map.iGetMapX();
	 	// if(map.iGetVecMap().at(i) == 0xFF)
	 	// {
	 	// 	++i;
	 	// }
	 	// else
	 	// {
	 		std::cout<<(cntX)<<" ";
	 		std::cout<<(cntY)<<std::endl;
	 		cntX++;

	 		eMap.push_back(Entity(Vector2f(cntX*48,cntY*48), collisionSheet, Vector2i(map.iGetVecMap().at(i), 1), Vector2i(48, 48)));
	 	// }
	 	
	}

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

		 for(Entity& e : eMap)
		 {
		 	window.Render(e);
		 }

		 for(Entity& e : entities)
		 {
		 	window.Render(e);
		 }





		 window.Display();
	}

	window.CleanUp();
	SDL_Quit();


	return 0;
}