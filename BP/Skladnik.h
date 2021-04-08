#pragma once
#ifndef SKLADNIK_H
#define SKLADNIK_H
#include "Przepis.h"
#include <string>
#include <map>
using namespace std;

class Skladnik : public Przepis
{
    pair<string, int> skladnik;
public:
    void setValue() {};
    void setValue(string produkt);
    void setValue(int waga);
    pair<string, int> getValue();
};

#endif // !SKLADNIK_H



