#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int idAdresata;
    int idUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;

public:
   Adresat (int idAdresata = 0, int idUzytkownika = 0, string imie = "", string nazwisko = "", string numerTelefonu = "", string email = "", string adres = "")
    {
        this->idAdresata = idAdresata;
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;
    };
    void ustawIdAdresata(int noweIdAdresata);
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);

    int wczytajIdAdresata();
    int wczytajIdUzytkownika();
    string wczytajImie();
    string wczytajNazwisko();
    string wczytajNumerTelefonu();
    string wczytajEmail();
    string wczytajAdres();

};
#endif
