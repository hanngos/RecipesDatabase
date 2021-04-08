#pragma once
#ifndef WATKI_H
#define WATKI_H
#include <fstream>
#include <vector>
#include <json\json.h>
#include <typeinfo>
#include "Wyjatki.h"
#include "Obrazki.h"
#include "Przepis.h"
#include "Nazwa.h"
#include "Cena.h"
#include "Skladnik.h"
#include "Opis.h"
#include "Czas.h"
#include "Kategoria.h"
#include "Tekst.h"

using namespace std;

void json(vector<vector<Przepis*>>& przepisy, string kategoria, double minCena, double maxCena, int minCzas, int maxCzas);

void ladujobrazki(vector<Obrazek*>& obrazki, SDL_Renderer*& renderer);

#endif // !WATKI_H

