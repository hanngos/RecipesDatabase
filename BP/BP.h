#ifndef BP_H
#define BP_H

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <json\json.h>
#include <vector>
#include <thread>
#include <iostream>
#include "Obrazki.h"
#include "Watki.h"
#include "Wyjatki.h"
#include "Tekst.h"
#define HIGHT 520
#define WIDTH 1000

class BP {
public:
    BP();
    ~BP();
    void init(const char* title, int xpos, int ypos, int width, int hight);
    void run();
    void render();
    void clean();
    void handleEvents();
    bool running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
    int xMouse, yMouse;

    enum class ekrany {BAZA, CENA, CZAS, ILE, PRZEPISY, PRZEPIS};
    ekrany ekran;
    enum obrazek { baza, naco, sniadanie, obiad, kolacja, cenaO, do10, do20, ponad20, czasO, do15, do30, ponad30, ileN, przepisyN, przepisN, powrot, nowy };
    
    string kategoria;
    double minCena, maxCena;
    int minCzas, maxCzas;
    int ile = 1;
    int ktory = 1;

    vector<Obrazek*> obrazki;
    vector <vector<Przepis*>> przepisy;
    Tekst* tekst;

};

#endif /// BP_H