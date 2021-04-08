#include "Wyjatki.h"

void WyjatekSDL::komunikat()
{
		cout << "Zgloszono wyjatek!!! SDL Error: " << SDL_GetError() << endl;
}

void WyjatekTTF::komunikat()
{
	cout << "Zgloszono wyjatek!!! TTF Error: " << TTF_GetError() << endl;
}

void WyjatekPlik::komunikat()
{
	cout << "Nie udalo sie otworzyc pliku" << endl;
}
