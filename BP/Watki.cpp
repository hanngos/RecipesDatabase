#include "Watki.h"


void json(vector<vector<Przepis*>> &przepisy, string sKategoria, double minCena, double maxCena, int minCzas, int maxCzas)
{
    vector<Przepis*> przepis;
    Json::Value p;
    ifstream infile("bazaprzepisow.json", ifstream::binary);
    try {
        if (infile.good() == false) {
            throw WyjatekPlik();
        }
        else {
            infile >> p;
            infile.close();

            for (int i = 0; i < (int)p.size(); i++) {
                if (!sKategoria.compare(p[i]["Kategoria"].asString())) {
                    if (minCena < p[i]["Cena"].asDouble() && p[i]["Cena"].asDouble() <= maxCena) {
                        if (minCzas < p[i]["Czas"].asInt() && p[i]["Czas"].asInt() <= maxCzas) {
                            Nazwa* nazwa = new Nazwa();
                            Cena* cena = new Cena();
                            Czas* czas = new Czas();
                            Kategoria* kategoria = new Kategoria();
                            Opis* opis = new Opis();

                            nazwa->setValue(p[i]["Nazwa"].asString());
                            przepis.push_back(nazwa);
                            cena->setValue(p[i]["Cena"].asDouble());
                            przepis.push_back(cena);
                            czas->setValue(p[i]["Czas"].asInt());
                            przepis.push_back(czas);
                            kategoria->setValue(p[i]["Kategoria"].asString());
                            przepis.push_back(kategoria);
                            opis->setValue(p[i]["Opis"].asString());
                            przepis.push_back(opis);
                            for (int j = 0; j < (int)p[i]["Skladniki"].size(); j++) {
                                Skladnik* skladnik = new Skladnik();
                                skladnik->setValue(p[i]["Skladniki"][j]["produkt"].asString());
                                skladnik->setValue(p[i]["Skladniki"][j]["waga"].asInt());
                                przepis.push_back(skladnik);
                            }

                            przepisy.push_back(przepis);
                            przepis.clear();
                        }
                    }
                }
            }
        }
    }
    catch (WyjatekPlik p) {
        p.komunikat();
    }
}

void ladujobrazki(vector<Obrazek*>& obrazki, SDL_Renderer*& renderer)
{
    //BAZA
    Obrazek* baza = new Obrazek();
    baza->setSrc(0, 0, 466, 109);
    baza->setImage("baza.png", renderer);
    obrazki.push_back(baza);
    //NA CO
    Obrazek* naco = new Obrazek();
    naco->setSrc(0, 0, 358, 59);
    naco->setImage("naco.png", renderer);
    obrazki.push_back(naco);
    //ŒNIADANIE
    Obrazek* sniadanie = new Obrazek();
    sniadanie->setSrc(0, 0, 191, 73);
    sniadanie->setImage("sniadanie.png", renderer);
    obrazki.push_back(sniadanie);
    //OBIAD
    Obrazek* obiad = new Obrazek();
    obiad->setSrc(0, 0, 191, 73);
    obiad->setImage("obiad.png", renderer);
    obrazki.push_back(obiad);
    //KOLACJA
    Obrazek* kolacja = new Obrazek();
    kolacja->setSrc(0, 0, 191, 73);
    kolacja->setImage("kolacja.png", renderer);
    obrazki.push_back(kolacja);
    //CENA
    Obrazek* cena = new Obrazek();
    cena->setSrc(0, 0, 259, 80);
    cena->setImage("cena.png", renderer);
    obrazki.push_back(cena);
    //do 10
    Obrazek* do10 = new Obrazek();
    do10->setSrc(0, 0, 166, 64);
    do10->setImage("do10.png", renderer);
    obrazki.push_back(do10);
    //do 20
    Obrazek* do20 = new Obrazek();
    do20->setSrc(0, 0, 166, 64);
    do20->setImage("do20.png", renderer);
    obrazki.push_back(do20);
    //ponad 20
    Obrazek* ponad20 = new Obrazek();
    ponad20->setSrc(0, 0, 166, 64);
    ponad20->setImage("ponad20.png", renderer);
    obrazki.push_back(ponad20);
    //CZAS
    Obrazek* czas = new Obrazek();
    czas->setSrc(0, 0, 537, 80);
    czas->setImage("czas.png", renderer);
    obrazki.push_back(czas);
    //do 15
    Obrazek* do15 = new Obrazek();
    do15->setSrc(0, 0, 166, 64);
    do15->setImage("do15.png", renderer);
    obrazki.push_back(do15);
    //do 30
    Obrazek* do30 = new Obrazek();
    do30->setSrc(0, 0, 166, 64);
    do30->setImage("do30.png", renderer);
    obrazki.push_back(do30);
    //ponad 30
    Obrazek* ponad30 = new Obrazek();
    ponad30->setSrc(0, 0, 166, 64);
    ponad30->setImage("ponad30.png", renderer);
    obrazki.push_back(ponad30);
    //ILE
    Obrazek* ile = new Obrazek();
    ile->setSrc(0, 0, 380, 80);
    ile->setImage("ile.png", renderer);
    obrazki.push_back(ile);
    //PRZEPISY
    Obrazek* przepisy = new Obrazek();
    przepisy->setSrc(0, 0, 233, 80);
    przepisy->setImage("przepisy.png", renderer);
    obrazki.push_back(przepisy);
    //PRZEPIS
    Obrazek* przepis = new Obrazek();
    przepis->setSrc(0, 0, 380, 80);
    przepis->setImage("przepis.png", renderer);
    obrazki.push_back(przepis);
    //POWRÓT
    Obrazek* powrot = new Obrazek();
    powrot->setSrc(0, 0, 135, 45);
    powrot->setImage("powrot.png", renderer);
    obrazki.push_back(powrot);
    //NOWY PRZEPIS
    Obrazek* nowy = new Obrazek();
    nowy->setSrc(0, 0, 135, 45);
    nowy->setImage("nowy.png", renderer);
    obrazki.push_back(nowy);

}
