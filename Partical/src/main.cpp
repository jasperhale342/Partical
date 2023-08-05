#include <iostream>
#include <fstream>
#include <SDL.h>
#include "screen.h"
#include "Swarm.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#undef main
using namespace std;
using namespace particle;

int main(int argc, char* argv[])
{
	srand(time(NULL));

	Screen screen;

	if (!screen.init()) {
		cout << "error initializing SDL" << endl;
	}

	Swarm swarm;

	int max = 0;
	while (true) {

		int elapsed = SDL_GetTicks();
		//screen.clear();
		swarm.update(elapsed);
		unsigned char green = (1 + sin(elapsed * 0.001)) * 128;
		unsigned char red = (1 + sin(elapsed * 0.002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.003)) * 128;

		const Particle* const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLE; i++) {
			Particle particle = pParticles[i];
			
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y  * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();
		screen.update();

		if (!screen.processEvents()) {
			break;
		}
		
	}

	screen.close();
	return 0;
}