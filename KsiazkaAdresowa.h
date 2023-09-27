#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>
#include "UzytkownikManager.h"
#include "AdresatManager.h"

class KsiazkaAdresowa
{

    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    const string NAZWAPLIKUZADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami,string nazwaPlikuZAdresatami):
        uzytkownikManager(nazwaPlikuZUzytkownikami),NAZWAPLIKUZADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatManager = NULL;
    }
    ~KsiazkaAdresowa()
    {
        delete adresatManager;
        adresatManager = NULL;
    }
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZPliku();
    bool czyUzytkownikJestZalogowany();
};

#endif
