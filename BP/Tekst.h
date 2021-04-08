#pragma once
#ifndef TEKST_H
#define TEKST_H
#include "ObiektGraficzny.h"
#include <SDL_ttf.h>

class Tekst : public ObiektGraficzny {
public:
    void rysuj(SDL_Renderer* renderer, const char* text, int x, int y, Uint8 r, Uint8 g, Uint8 b);
};

#endif // !TEKST_H

