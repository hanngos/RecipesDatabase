#include "Skladnik.h"

void Skladnik::setValue(string produkt)
{
    this->skladnik.first = produkt;
}

void Skladnik::setValue(int waga)
{
    this->skladnik.second = waga;
}

pair<string, int> Skladnik::getValue()
{
    return this->skladnik;
}