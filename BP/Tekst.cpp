#include "Tekst.h"

void Tekst::rysuj(SDL_Renderer*renderer,const char* text, int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
    TTF_Font* font = TTF_OpenFont("arial.ttf", 25);
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Color color = { r, g, b, 255 };
    SDL_Rect rec;
    surface = TTF_RenderText_Solid(font, text, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    rec.x = x;
    rec.y = y;
    rec.w = surface->w;
    rec.h = surface->h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &rec);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}
