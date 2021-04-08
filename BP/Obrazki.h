#pragma once
#ifndef OBRAZKI_H
#define OBRAZKI_H
#include "ObiektGraficzny.h"
#include <SDL.h>
#include <string>
#include <SDL_image.h>
using namespace std;


class Obrazek : public ObiektGraficzny{
private:
	SDL_Rect src;
	SDL_Texture* tex;
public:
	SDL_Rect dest;
	Obrazek();
	SDL_Rect getDest() const;
	SDL_Rect getSrc() const;
	SDL_Texture* getTex() const;
	void setDest(int x, int y);
	void setSrc(int x, int y, int w, int h);
	void setImage(string filename, SDL_Renderer* renderer);
	void rysuj(SDL_Renderer* renderer);

};

#endif // !OBRAZKI_H

