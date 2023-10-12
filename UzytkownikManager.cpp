#include "UzytkownikManager.h"


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

void UzytkownikManager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
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
    for(int i =0;i<uzytkownicy.size();i++)
    {
        if(uzytkownicy[i].pobierzLogin()==login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikManager::wypiszWszystkichUzytkownikow()
{
    for(int i =0;i<uzytkownicy.size();i++)
    {
       cout<<uzytkownicy[i].pobierzId()<<endl;
       cout<<uzytkownicy[i].pobierzLogin()<<endl;
       cout<<uzytkownicy[i].pobierzHaslo()<<endl;
    }
}

void UzytkownikManager::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikManager::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    auto itr = uzytkownicy.begin();
    for (; itr != uzytkownicy.end(); itr++)
    {
        if (itr->pobierzLogin() == login)
        {
            idZalogowanegoUzytkownika = itr->pobierzId();
            break;
        }
    }

    if (itr == uzytkownicy.end())
    {
        cout << endl << "Nie ma u¿ytkownika z takim loginem" << endl << endl;
        system("pause");
        return;
    }

    int iloscProb = 3;
    for (; iloscProb > 0; iloscProb--)
    {
        cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
        haslo = MetodyPomocnicze::wczytajLinie();

        if (itr->pobierzHaslo() == haslo)
        {
            cout << endl << "Zalogowales sie." << endl << endl;
            system("pause");
            return;
        }
    }

    if (iloscProb == 0)
        cout << "Wprowadzono 3 razy bledne haslo." << endl;
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

int UzytkownikManager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

bool UzytkownikManager::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika>0)
        return true;
    else {
        return false;
    }
}


