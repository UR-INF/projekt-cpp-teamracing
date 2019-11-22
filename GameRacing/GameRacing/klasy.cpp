#include <iostream>
#include <SDL.h>



class klasa_przeciwnik
{
public:
	
	float posX;
	float posY;
	float predkosc;
	


	void init()
	{
		posX = 1280;
		posY = 100 + ((rand () % 520)/85)*86+40;
	}

	void update(SDL_Texture* tekstura, SDL_Renderer* render)
	{

		posX = posX - 10;

		SDL_Rect rect;
		rect.x = posX;
		rect.y = posY - 20;
		rect.w = 80;
		rect.h = 40;
		SDL_RenderCopy(render,tekstura, NULL, &rect);
	}

};