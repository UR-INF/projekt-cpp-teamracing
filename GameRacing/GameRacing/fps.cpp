#include <SDL.h>


class klasa_fps
{
public:

	int poczatek;
	int koniec;
	int roznica;
	float delay;
	int klatka = 0;
	int fps = 60;
	void start()
	{
		poczatek = SDL_GetTicks();
	}

	void end()
	{
		koniec = SDL_GetTicks();
		roznica = koniec - poczatek;
		delay = (1000.0 / (float)fps) - roznica;
		if (delay > 0)
		{
			SDL_Delay(delay);
		}
	}
};
