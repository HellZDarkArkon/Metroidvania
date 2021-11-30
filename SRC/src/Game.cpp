#include "Game.h"

Game::Game(RenderWindow w, const char* strTex) : bRunning(true)
{

	tex = w.sdlLoadTexture(strTex);
}

Game::~Game()
{

}

void Game::handleEvents()
{
	static SDL_Event ev;

	while(SDL_PollEvent(&ev));
	{
		switch(ev.type)
		{
			case SDL_QUIT :
				bRunning = false;
				break;
			default:
				break;
		}
	}
}

void Game::update(RenderWindow w)
{
	handleEvents();

		w.Clear();

		for(Entity& e : eMap)
		{
			w.Render(e);
		}

		for(Entity& e : eMob)
		{
			w.Render(e);
		}

		w.Display();
}

void Game::loadMap(Vector2i size, const char* strMap)
{
	Map map(size, strMap);
	Vector2i cnt = {0,0};
	// Map map(Vector2i(13,11), "ASSETS/DATA/MAPS/testmap.txt");

	for(int i = 0; i < map.iGetVecMap().size(); i++)
	{
		cnt.x = i % (map.iGetMapSize().x + 1);
		cnt.y = i / (map.iGetMapSize().x + 1);

			eMap.push_back(Entity(Vector2f(cnt.x*48,cnt.y*48), tex, Vector2i(map.iGetVecMap().at(i), 1), Vector2i(48, 48)));
	}
}

void Game::loadEntities(bool doubler)
{
	eMob.push_back(Entity(Vector2f(((6))*48, (6)*48), getTex(), Vector2i(2,2), Vector2i(48,48)));
	eMob.push_back(Entity(Vector2f(((2))*48, (4)*48), getTex(), Vector2i(3,1), Vector2i(48,48)));
	eMob.push_back(Entity(Vector2f(((7))*48, (3)*48), getTex(), Vector2i(3,1), Vector2i(48,48)));
	eMob.push_back(Entity(Vector2f(((7))*48, (1)*48), getTex(), Vector2i(3,1), Vector2i(48,48)));
}

SDL_Texture* Game::getTex()
{
	return tex;
}

std::vector<Entity> Game::getVec(int choice)
{
	switch(choice)
	{
		case 1:
			return eMob;
			break;
		case 2:
			return eMap;
			break;
		default:
			break;
	}
}