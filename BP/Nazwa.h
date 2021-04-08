#pragma once
#ifndef NAZWA_H
#define NAZWA_H
#include "Przepis.h"
#include <string>
using namespace std;

class Nazwa : public Przepis
{
    string nazwa;
public:
    void setValue() {};
    void setValue(string nazwa);
    string getValue();

};

#endif // !NAZWA_H