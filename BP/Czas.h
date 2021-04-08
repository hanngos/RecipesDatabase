#pragma once
#ifndef CZAS_H
#define CZAS_H
#include "Przepis.h"

class Czas : public Przepis
{
	int czas;
public:
	void setValue() {};
	void setValue(int cena);
	int getValue();
};

#endif // !CZAS_H