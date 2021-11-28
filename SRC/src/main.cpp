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
		{Entity(Vector2f{0, 48}, collisionSheet, Vector2i{0, 1}, Vector2i{48, 48}), 
		 Entity(Vector2f{48, 48}, collisionSheet, Vector2i{1, 1}, Vector2i{48, 48}), 
		 Entity(Vector2f{96, 0}, collisionSheet, Vector2i{2, 2}, Vector2i{48, 48}),
		 Entity(Vector2f{144, 48}, collisionSheet, Vector2i{3, 1}, Vector2i{48, 48}),
		 Entity(Vector2f{192, 48}, collisionSheet, Vector2i{4, 1}, Vector2i{48, 48}),
		 Entity(Vector2f{240, 48}, collisionSheet, Vector2i{5, 1}, Vector2i{48, 48}),
		 Entity(Vector2f{288, 48}, collisionSheet, Vector2i{6, 1}, Vector2i{48, 48}),
		 Entity(Vector2f{336, 48}, collisionSheet, Vector2i{7, 1}, Vector2i{48, 48})
		};
	Map map(8, 8, "ASSETS/DATA/MAPS/testmap.txt");
	std::vector<Entity> eMap;
	int cntX = 0;
	int cntY = 0;
	for(int& i: map.iGetVecMap())
	{
		std::cout<<map.iGetVecMap().at(i);
		if(map.iGetVecMap().at(i) == 0xF)
		{
			cntY++;
			std::cout<<"0xFF"<<std::endl;
		}
		eMap.push_back(Entity(Vector2f(cntX*48,cntY*48), collisionSheet, Vector2i(map.iGetVecMap().at(i), 1), Vector2i(48, 48)));

		if(cntX < 7)
		{
			++cntX;
		}
		else if(cntX >= 7)
		{
			cntX = 0;
		}
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