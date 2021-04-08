#include "Obrazki.h"

Obrazek::Obrazek(){
	dest = getDest();
	src = getSrc();
}

SDL_Rect Obrazek::getDest() const{
	return dest;
}

SDL_Rect Obrazek::getSrc() const{
	return src;
}

SDL_Texture* Obrazek::getTex() const
{
	return tex;
}

void Obrazek::setDest(int x, int y){
	dest.x = x;
	dest.y = y;
	dest.w = this->src.w;
	dest.h = this->src.h;
}

void Obrazek::setSrc(int x, int y, int w, int h){
	src.x = x;
	src.y = y;
	src.w = w;
	src.h = h;
}

void Obrazek::setImage(string filename, SDL_Renderer* renderer){
	SDL_Surface* surf = IMG_Load(filename.c_str());
	tex = SDL_CreateTextureFromSurface(renderer, surf);
}

void Obrazek::rysuj(SDL_Renderer* renderer){
	SDL_RenderCopyEx(renderer, this->getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}
