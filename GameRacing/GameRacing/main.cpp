#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

#include "fps.cpp"

SDL_Window* okno;
SDL_Surface* ekran;
SDL_Event zdarzenie;
SDL_Rect rect1, rect2;
const Uint8* keystate;


int main(int argc, char* args[])
{
	okno = SDL_CreateWindow("Gra", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	ekran = SDL_GetWindowSurface(okno);

	klasa_fps fps;
	SDL_Surface * droga = IMG_Load("doga.png");
	SDL_Surface * postac = IMG_Load("postac.png");

	int klatka = 0;

	float posY = 360;
	float velY = 0;

	while (true)
	{
		fps.start();
		klatka++;
		keystate = SDL_GetKeyboardState(NULL);

		while (SDL_PollEvent(&zdarzenie))
		{
			if (zdarzenie.type == SDL_QUIT)
			{
				exit(0);
			}
		}

		{//fizyka
			posY = posY + velY;
		}

		{//render
			{//t³o
				SDL_FillRect(ekran, NULL, NULL);
			}

			{//droga
				for (int loop = 0; loop < 8; loop++) {

					rect2.x = loop * 200 - (klatka * 8) % 200;
					rect2.y = 0;
					SDL_BlitSurface(droga, NULL, ekran, &rect2);
				}
			}
			{//postac
				rect2.x = 100;
				rect2.y = posY - 20;
				SDL_BlitSurface(postac, NULL, ekran, &rect2);
			}
			
		}

		SDL_UpdateWindowSurface(okno);
		fps.end();
	}
}

