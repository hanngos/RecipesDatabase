#pragma once
#ifndef OBIEKTGRAFICZNY_H
#define OBIEKTGRAFICZNY
#include "SDL.h"

class ObiektGraficzny {
public:
	virtual void rysuj(SDL_Renderer*renderer) = 0;
};

#endif // !OBIEKTGRAFICZNY_H

