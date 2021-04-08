#pragma once
#ifndef CENA_H
#define CENA_H
#include "Przepis.h"

class Cena : public Przepis
{
    double cena;
public:
    void setValue() {};
    void setValue(double cena);
    double getValue();
};

#endif // !CENA_H