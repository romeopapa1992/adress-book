#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikManager.logowanieUzytkownika();
    if(uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager= new AdresatManager(NAZWAPLIKUZADRESATAMI,uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikManager.wylogowanieUzytkownika();
    delete adresatManager;
    adresatManager = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatManager->dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatManager->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::wczytajAdresatowZPliku()
{
    adresatManager->wczytajAdresatowZPliku(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    return uzytkownikManager.czyUzytkownikJestZalogowany();
}
