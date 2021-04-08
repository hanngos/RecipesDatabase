#include "BP.h"

using namespace std;

BP::BP() {
}

BP::~BP() {
}

void BP::init(const char* title, int xpos, int ypos, int width, int height) {
    try {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            throw WyjatekSDL();
            isRunning = false;
        }
        else {
            if (TTF_Init() < 0) throw WyjatekTTF();
            window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);

            if (!window) {
                throw WyjatekSDL();
                isRunning = false;
            }

            renderer = SDL_CreateRenderer(window, -1, 0);

            if (renderer) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            else {
                throw WyjatekSDL();
                isRunning = false;
            }
            isRunning = true;

            thread zaladujobrazki(ladujobrazki, ref(obrazki), ref(renderer));
            zaladujobrazki.join();

            ekran = ekrany::BAZA;
        }
    }
    catch (WyjatekTTF w) {
        w.komunikat();
    }
    catch (WyjatekSDL w) {
        w.komunikat();
    }
}

void BP::run()
{
    render();
    while (isRunning) {
        handleEvents();
    }
}

void BP::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {

        switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_DOWN:
                switch (ekran) {
                case ekrany::ILE:
                    if (ile > 1) {
                        ile--;
                    }
                    render();
                    break;
                case ekrany::PRZEPISY:
                    if (ktory > 1) {
                        ktory--;
                    }
                    przepisy.clear();
                    render();
                    break;
                }
                break;
            case SDLK_UP:
                switch (ekran) {
                case ekrany::ILE:
                    ile++;
                    render();
                    break;
                case ekrany::PRZEPISY:
                    if (ktory <= (przepisy.size()-1)) {
                        ktory++;
                    }
                    przepisy.clear();
                    render();
                    break;
                }
                break;
            case SDLK_RETURN:
                switch (ekran){
                case ekrany::ILE:
                    ekran = ekrany::PRZEPISY;
                    render();
                    break;
                case ekrany::PRZEPISY:
                    if (!przepisy.empty()) {
                        ekran = ekrany::PRZEPIS;
                    }
                    render();
                    break;
                }
                break;
            case SDLK_ESCAPE:
                isRunning = false;
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button) {
            case SDL_BUTTON_LEFT:
                switch (ekran) {
                case ekrany::BAZA:
                    if (xMouse > obrazki[sniadanie]->dest.x && xMouse < obrazki[sniadanie]->dest.x + obrazki[sniadanie]->dest.w && yMouse > obrazki[sniadanie]->dest.y && yMouse < obrazki[sniadanie]->dest.y + obrazki[sniadanie]->dest.h) {
                        kategoria = "sniadanie";
                        ekran = ekrany::CENA;
                    }
                    else if (xMouse > obrazki[obiad]->dest.x && xMouse < obrazki[obiad]->dest.x + obrazki[obiad]->dest.w && yMouse > obrazki[obiad]->dest.y && yMouse < obrazki[obiad]->dest.y + obrazki[obiad]->dest.h) {
                        kategoria = "obiad";
                        ekran = ekrany::CENA;
                    }
                    else if (xMouse > obrazki[kolacja]->dest.x && xMouse < obrazki[kolacja]->dest.x + obrazki[kolacja]->dest.w && yMouse > obrazki[kolacja]->dest.y && yMouse < obrazki[kolacja]->dest.y + obrazki[kolacja]->dest.h) {
                        kategoria = "kolacja";
                        ekran = ekrany::CENA;
                    }
                    break;
                case ekrany::CENA:
                    if (xMouse > obrazki[do10]->dest.x && xMouse < obrazki[do10]->dest.x + obrazki[do10]->dest.w && yMouse > obrazki[do10]->dest.y && yMouse < obrazki[do10]->dest.y + obrazki[do10]->dest.h) {
                        minCena = 0;
                        maxCena = 10;
                        ekran = ekrany::CZAS;
                    }
                    else if (xMouse > obrazki[do20]->dest.x && xMouse < obrazki[do20]->dest.x + obrazki[do20]->dest.w && yMouse > obrazki[do20]->dest.y && yMouse < obrazki[do20]->dest.y + obrazki[do20]->dest.h) {
                        minCena = 10;
                        maxCena = 20;
                        ekran = ekrany::CZAS;
                    }
                    else if (xMouse > obrazki[ponad20]->dest.x && xMouse < obrazki[ponad20]->dest.x + obrazki[ponad20]->dest.w && yMouse > obrazki[ponad20]->dest.y && yMouse < obrazki[ponad20]->dest.y + obrazki[ponad20]->dest.h) {
                        minCena = 20;
                        maxCena = INFINITY;
                        ekran = ekrany::CZAS;
                    }
                    break;
                case ekrany::CZAS:
                    if (xMouse > obrazki[do15]->dest.x && xMouse < obrazki[do15]->dest.x + obrazki[do15]->dest.w && yMouse > obrazki[do15]->dest.y && yMouse < obrazki[do15]->dest.y + obrazki[do15]->dest.h) {
                        minCzas = 0;
                        maxCzas = 15;
                        ekran = ekrany::ILE;
                    }
                    else if (xMouse > obrazki[do30]->dest.x && xMouse < obrazki[do30]->dest.x + obrazki[do30]->dest.w && yMouse > obrazki[do30]->dest.y && yMouse < obrazki[do30]->dest.y + obrazki[do30]->dest.h) {
                        minCzas = 15;
                        maxCzas = 30;
                        ekran = ekrany::ILE;
                    }
                    else if (xMouse > obrazki[ponad30]->dest.x && xMouse < obrazki[ponad30]->dest.x + obrazki[ponad30]->dest.w && yMouse > obrazki[ponad30]->dest.y && yMouse < obrazki[ponad30]->dest.y + obrazki[ponad30]->dest.h) {
                        minCzas = 30;
                        maxCzas = INFINITY;
                        ekran = ekrany::ILE;
                    }
                    break;
                case ekrany::PRZEPISY:
                    if (xMouse > obrazki[nowy]->dest.x && xMouse < obrazki[nowy]->dest.x + obrazki[nowy]->dest.w && yMouse > obrazki[nowy]->dest.y && yMouse < obrazki[nowy]->dest.y + obrazki[nowy]->dest.h) {
                        ekran = ekrany::BAZA;
                        przepisy.clear();
                        ile = 1;
                        ktory = 1;
                    }
                    przepisy.clear();
                    break;
                case ekrany::PRZEPIS:
                    if (xMouse > obrazki[powrot]->dest.x && xMouse < obrazki[powrot]->dest.x + obrazki[powrot]->dest.w && yMouse > obrazki[powrot]->dest.y && yMouse < obrazki[powrot]->dest.y + obrazki[powrot]->dest.h) {
                        ekran = ekrany::PRZEPISY;
                        przepisy.clear();
                    }
                    else if (xMouse > obrazki[nowy]->dest.x && xMouse < obrazki[nowy]->dest.x + obrazki[nowy]->dest.w && yMouse > obrazki[nowy]->dest.y && yMouse < obrazki[nowy]->dest.y + obrazki[nowy]->dest.h) {
                        ekran = ekrany::BAZA;
                        przepisy.clear();
                        ile = 1;
                        ktory = 1;
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
            render();
        default:
            break;
        }
        SDL_GetMouseState(&xMouse, &yMouse);
    }
}

void BP::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    switch (ekran) {
    case ekrany::BAZA:
        obrazki[baza]->setDest(WIDTH / 2 - 233, 10);
        obrazki[baza]->rysuj(renderer);
        obrazki[naco]->setDest(WIDTH / 2 - 179, 120);
        obrazki[naco]->rysuj(renderer);
        obrazki[sniadanie]->setDest(WIDTH / 2 - 95, 190);
        obrazki[sniadanie]->rysuj(renderer);
        obrazki[obiad]->setDest(WIDTH / 2 - 95, 270);
        obrazki[obiad]->rysuj(renderer);
        obrazki[kolacja]->setDest(WIDTH / 2 - 95, 350);
        obrazki[kolacja]->rysuj(renderer);
        break;
    case ekrany::CENA:
        obrazki[cenaO]->setDest(WIDTH / 2 - 129, 10);
        obrazki[cenaO]->rysuj(renderer);
        obrazki[do10]->setDest(WIDTH / 2 - 83, 150);
        obrazki[do10]->rysuj(renderer);
        obrazki[do20]->setDest(WIDTH / 2 - 83, 220);
        obrazki[do20]->rysuj(renderer);
        obrazki[ponad20]->setDest(WIDTH / 2 - 83, 290);
        obrazki[ponad20]->rysuj(renderer);
        tekst->rysuj(renderer, "*dla jednej osoby!", 40, 350, 0, 0, 0);
        break;
    case ekrany::CZAS:
        obrazki[czasO]->setDest(WIDTH / 2 - 268, 10);
        obrazki[czasO]->rysuj(renderer);
        obrazki[do15]->setDest(WIDTH / 2 - 83, 150);
        obrazki[do15]->rysuj(renderer);
        obrazki[do30]->setDest(WIDTH / 2 - 83, 220);
        obrazki[do30]->rysuj(renderer);
        obrazki[ponad30]->setDest(WIDTH / 2 - 83, 290);
        obrazki[ponad30]->rysuj(renderer);
        break;
    case ekrany::ILE:
        obrazki[ileN]->setDest(WIDTH / 2 - 190, 10);
        obrazki[ileN]->rysuj(renderer);
        tekst->rysuj(renderer, ("Liczba osob:  " + to_string(ile)).c_str(), WIDTH/2, 260, 0, 0, 0);
        tekst->rysuj(renderer, "Liczbe osob mozesz zmienic za pomoca strzalek!", 40, 130, 0, 0, 0);
        tekst->rysuj(renderer, "Strzalka w gore zwieksza liczbe osob", 40, 160, 0, 0, 0);
        tekst->rysuj(renderer, "Strzalka w dol zmniejsza liczbe osob", 40, 190, 0, 0, 0);
        tekst->rysuj(renderer, "Kliknij ENTER, aby zatwierdzic!", 40, 220, 0, 0, 0);
        break;
    case ekrany::PRZEPISY:

        json(ref(przepisy), kategoria, minCena, maxCena, minCzas, maxCzas);

        if (przepisy.empty()) {
            tekst->rysuj(renderer, "Ups, nie mamy takiego przepisu! :(", 50, 100, 0, 0, 0);
        }
        else {
            for (int j = 0; j < (int)przepisy.size(); j++) {
                Nazwa* nazwa = dynamic_cast<Nazwa*>(przepisy[j][0]);
                tekst->rysuj(renderer, (to_string(j + 1) + ". " + nazwa->getValue()).c_str(), 50, 100 + j * 20, 0, 0, 0);
            }
            tekst->rysuj(renderer, ("Numer przepisu: " + to_string(ktory)).c_str(), 600, 100, 0, 0, 0);
        }
        obrazki[przepisyN]->setDest(WIDTH / 2 - 116, 10);
        obrazki[przepisyN]->rysuj(renderer);
        obrazki[nowy]->setDest(WIDTH / 2, 455);
        obrazki[nowy]->rysuj(renderer);
        break;
    case ekrany::PRZEPIS:
        obrazki[przepisN]->setDest(WIDTH / 2 - 190, 10);
        obrazki[przepisN]->rysuj(renderer);
        
        for (int j = 0; j < (int)przepisy[ktory - 1].size(); j++) {
            if (typeid(*przepisy[ktory - 1][j]) == typeid(Nazwa)) {
                Nazwa* i = dynamic_cast<Nazwa*>(przepisy[ktory - 1][j]);
                tekst->rysuj(renderer, ("NAZWA: " + i->getValue()).c_str(), 10, 100 + j * 20, 0, 0, 0);
            }
            else if (typeid(*przepisy[ktory - 1][j]) == typeid(Cena)) {
                Cena* i = dynamic_cast<Cena*>(przepisy[ktory - 1][j]);
                tekst->rysuj(renderer, ("CENA: " + to_string(ile * i->getValue()) + " zl").c_str(), 10, 100 + j * 20, 0, 0, 0);
            }
            else if (typeid(*przepisy[ktory - 1][j]) == typeid(Czas)) {
                Czas* i = dynamic_cast<Czas*>(przepisy[ktory - 1][j]);
                tekst->rysuj(renderer, ("CZAS: " + to_string(i->getValue()) + " min").c_str(), 10, 100 + j * 20, 0, 0, 0);
            }
            else if (typeid(*przepisy[ktory - 1][j]) == typeid(Kategoria)) {
                Kategoria* i = dynamic_cast<Kategoria*>(przepisy[ktory - 1][j]);
                tekst->rysuj(renderer, ("KATEGORIA: " + i->getValue()).c_str(), 10, 100 + j * 20, 0, 0, 0);
            }
            else if (typeid(*przepisy[ktory - 1][j]) == typeid(Skladnik)) {
                tekst->rysuj(renderer, "SKLADNIKI: ", 10, 180, 0, 0, 0);
                Skladnik* i = dynamic_cast<Skladnik*>(przepisy[ktory - 1][j]);
                tekst->rysuj(renderer, (i->getValue().first + ", " + to_string(ile * i->getValue().second) + " g").c_str(), 10, 100 + j * 20, 0, 0, 0);
            }
            else if (typeid(*przepisy[ktory - 1][j]) == typeid(Opis)) {
                Opis* i = dynamic_cast<Opis*>(przepisy[ktory - 1][j]);
                Obrazek* opis = new Obrazek();
                opis->setSrc(0, 0, 600, 335);
                opis->setImage(i->getValue(), renderer);
                opis->setDest(370, 130);
                opis->rysuj(renderer);
            }
        }
        obrazki[powrot]->setDest(WIDTH / 2 + 180, 455);
        obrazki[powrot]->rysuj(renderer);
        obrazki[nowy]->setDest(WIDTH / 2, 455);
        obrazki[nowy]->rysuj(renderer);
        break;
    default:
        break;
    }

    SDL_RenderPresent(renderer);
}

void BP::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
}
