#include <iostream>
#include <time.h>
#include <cstdlib>
#include <SDL.h>



class klasa_przeciwnik
{
public:
	
	float posX;
	float posY;
	
	
	Uint8 r, g, b;
	bool aktywny = true;

	void init()
	{
		posX = 1280;
		posY = 100 + ((rand () % 500)/85)*86+40;
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
	}

	void update(SDL_Texture* tekstura, SDL_Renderer* render,float postac_y)
	{
		
		if (aktywny == true)
		{
			posX = posX - 15;

			if (posX < 0)
			{
				aktywny = false;
			}


			SDL_Rect rect;
			rect.x = posX;
			rect.y = posY - 20;
			rect.w = 80;
			rect.h = 40;
			SDL_SetTextureColorMod(tekstura, r, g, b);
			SDL_RenderCopy(render, tekstura, NULL, &rect);

			//funkcja kolizji
			
			if (posX>120 && posX<160 && posY + 40>postac_y&& posY < postac_y + 40)
			{
				exit(0);
			}
		}
		
	}

};