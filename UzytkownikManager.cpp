#include "UzytkownikManager.h"

int UzytkownikManager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikManager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UzytkownikManager::wypiszWszystkichUzytkownikow()
{
    for(vector <Uzytkownik> :: size_type i = 0; i <uzytkownicy.size();i++)
    {
       cout<<uzytkownicy[i].pobierzId()<<endl;
       cout<<uzytkownicy[i].pobierzLogin()<<endl;
       cout<<uzytkownicy[i].pobierzHaslo()<<endl;
    }
}

void UzytkownikManager::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    int iloscProb = 3;
    string loginUzytkownika, hasloUzytkownika;

    cout << endl << "Podaj login: ";
    loginUzytkownika = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik> :: size_type i =0; i < uzytkownicy.size(); i++)
        {
        if (uzytkownicy[i].pobierzLogin() == loginUzytkownika)
        {
            while (iloscProb > 0) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                hasloUzytkownika = MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == hasloUzytkownika)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    system("pause");
                    return;
                }
                iloscProb--;
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            idZalogowanegoUzytkownika = 0;
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
}

void UzytkownikManager::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikManager::wylogowanieUzytkownika()
{
    if (idZalogowanegoUzytkownika==0)
        cout<<"Nikt nie jest zalogowany"<<endl;
    else {
        vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
        while (itr != uzytkownicy.end())
        {
            if (itr -> pobierzId() == idZalogowanegoUzytkownika)
                break;
            itr++;
        }
        cout<<"Uzytkownik: "<<itr->pobierzLogin()<<", wylogowany."<<endl;
        idZalogowanegoUzytkownika=0;
        system("pause");
    }
}

bool UzytkownikManager::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
    {
        return false;
    }
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout <<"Podaj login: ";
        login = MetodyPomocnicze::wczytajLinie();
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    haslo = MetodyPomocnicze::wczytajLinie();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikManager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikManager::czyIstniejeLogin(string login)
{
    for(vector <Uzytkownik> :: size_type i =0; i < uzytkownicy.size();i++)
    {
        if(uzytkownicy[i].pobierzLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
