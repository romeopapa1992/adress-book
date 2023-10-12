#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H
#include <vector>
#include "Adresat.h"
#include "PlikZAdresatami.h"

class AdresatManager
{
    int idZalogowanegoUzytkownika;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
public:

    AdresatManager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void podajIdZalogowanegoUzytkownika(int noweId);
};

#endif
