#include <SDL.h>
#include <SDL_image.h>



using namespace std;

#include "fps.cpp"
#include "klasy.cpp"
#include <string>

SDL_Window * okno;
//SDL_Surface* ekran;
SDL_Renderer* render;
SDL_Event zdarzenie;
SDL_Rect rect1, rect2;

const Uint8* keystate;

SDL_Texture* loadTexture(std::string path) {

	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {

		printf("Nie załadowano obrazu %s  SDL_image error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(render, loadedSurface);
		if (newTexture == NULL) {
			printf("Nie załadowano tekstur %s  SDL error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}	
	return newTexture;
}



int main(int argc, char* args[])
{
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	okno = SDL_CreateWindow("Gra", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
	render = SDL_CreateRenderer(okno, -1, SDL_RENDERER_ACCELERATED);

	klasa_fps fps;
	SDL_Texture* droga = loadTexture("droga.bmp");
	SDL_Texture* postac = loadTexture("postac.bmp");

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

		{//sterowanie

			if (keystate[SDL_SCANCODE_DOWN]) {
				if(velY < 25){
					velY = velY + 0.6;
				}
			}
			if (keystate[SDL_SCANCODE_UP]) {
				if(velY > -25){
					velY = velY - 0.6;
				}
			}
			velY = velY * 0.9;

		}


	{//fizyka
		posY = posY + velY;

		if (posY < 100) {
			velY = velY + 1;
			velY = velY * 0.9;

		}
		if (posY > 620) {
			velY = velY - 1;
			velY = velY * 0.9;

		}
	}

	{//render
		{//tlo
			SDL_RenderClear(render);
		}

		{//droga
			for (int loop = 0; loop < 8; loop++) {

				rect2.x = loop * 200 - (klatka * 6) % 200;
				rect2.y = 0;
				rect2.w = 200;
				rect2.h = 720;
				SDL_RenderCopy(render, droga, NULL, &rect2);
			}
		}
		{//postac
			rect2.x = 100;
			rect2.y = posY - 20;
			rect2.w = 80;
			rect2.h = 40;

			SDL_RenderCopyEx(render,postac,NULL,&rect2,velY*8,NULL,SDL_FLIP_NONE);
		}

	}

	SDL_RenderPresent(render);
	fps.end();
}
}