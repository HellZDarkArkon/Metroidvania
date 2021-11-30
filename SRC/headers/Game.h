#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "RenderWindow.h"
#include "Entity.h"
#include "Map.h"
#include "Math.h"

class Game
{
public:
	Game(RenderWindow w, const char* strTex);
	~Game();

	void handleEvents();
	void update(RenderWindow w);
	void loadMap(Vector2i size, const char* strMap);
	void loadEntities(bool doubler);

	SDL_Texture* getTex();
	std::vector<Entity> getVec(int choice);
	bool bRunning = true;

private:

	SDL_Texture* tex;	
	std::vector<Entity> eMap, eMob;
	

};