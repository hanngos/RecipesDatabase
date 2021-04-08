#pragma once
#ifndef OPIS_H
#define OPIS_H
#include "Przepis.h"
#include <string>
using namespace std;

class Opis : public Przepis
{
	string opis;
public:
	void setValue() {};
	void setValue(string opis);
	string getValue();
};

#endif // !OPIS_H