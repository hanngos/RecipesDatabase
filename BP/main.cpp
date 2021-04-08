#include <iostream>
#include "BP.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>

using namespace std;

int main() {

	BP* bp = new BP();

	bp->init("Baza Przepisow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HIGHT);
	bp->run();
	bp->clean();

	return 0;
}