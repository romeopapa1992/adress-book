# include "Adresat.h"

void Adresat::ustawIdAdresata(int noweIdAdresata)
{
    if (noweIdAdresata >= 0)
        {
            idAdresata = noweIdAdresata;
        }
}

void Adresat::ustawIdUzytkownika(int noweIdUzytkownika)
{
    if (noweIdUzytkownika >= 0)
        {
            idUzytkownika = noweIdUzytkownika;
        }
}
void Adresat::ustawImie(string noweImie)
{
    imie = noweImie;
}

void Adresat::ustawNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}

void Adresat::ustawNumerTelefonu(string nowyNumerTelefonu)
{
    numerTelefonu = nowyNumerTelefonu;
}

void Adresat::ustawEmail(string nowyEmail)
{
    email = nowyEmail;
}

void Adresat::ustawAdres(string nowyAdres)
{
    adres = nowyAdres;
}

int Adresat::wczytajIdAdresata()
{
    return idAdresata;
}

int Adresat::wczytajIdUzytkownika()
{

    return idUzytkownika;
}

string Adresat::wczytajImie()
{
    return imie;
}

string Adresat::wczytajNazwisko()
{
    return nazwisko;
}

string Adresat::wczytajNumerTelefonu()
{
    return numerTelefonu;
}

string Adresat::wczytajEmail()
{
    return email;
}

string Adresat::wczytajAdres()
{
    return adres;
}
