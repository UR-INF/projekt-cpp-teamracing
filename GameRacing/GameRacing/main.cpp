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


int main(int argc, char* args[])
{
	okno = SDL_CreateWindow("Gra", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
	ekran = SDL_GetWindowSurface(okno);

	klasa_fps fps;

	while (true)
	{
		fps.start();
		while (SDL_PollEvent(&zdarzenie))
		{
			if (zdarzenie.type == SDL_QUIT)
			{
				exit(0);
			}
		}

		SDL_UpdateWindowSurface(okno);

		fps.end();
	}
}

