#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H
#include <vector>
#include "Adresat.h"
#include "PlikZAdresatami.h"

class AdresatManager
{
    const int IDZALOGOWANEGOUZYTKOWNIKA;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
public:
    AdresatManager(string nazwaPlikuZAdresatami,int idZalogowanegoUzytkownika)
        :plikZAdresatami(nazwaPlikuZAdresatami),IDZALOGOWANEGOUZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(IDZALOGOWANEGOUZYTKOWNIKA);
    }
    void dodajAdresata();
    Adresat podajDaneNowegoAdresata();
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    void wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
};

#endif
