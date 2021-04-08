#pragma once
#ifndef KATEGORIA_H
#define KATEGORIA_H
#include "Przepis.h"
#include <string>
using namespace std;

class Kategoria : public Przepis
{
	string kategoria;
public:
	void setValue() {};
	void setValue(string kategoria);
	string getValue();
};

#endif // !KATEGORIA_H