#include <iostream>
#include <fstream>
#include <SDL.h>
#undef main
using namespace std;

int main(int argc, char* argv[])
{
	//SDL_SetMainReady();
	//SDL_SetError(SDL_ENABLE);
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	SDL_Window* window = NULL;
	window  = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	
	if (window == NULL) {
		SDL_Quit();
		cout << "could not create window" << SDL_GetError() << endl;
		return 1;
	}
	
	SDL_DestroyWindow(window);
	return 0;
}