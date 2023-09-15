#include "UzytkownikManager.h"

void UzytkownikManager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Wpisz login nowego uzytkownika: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Wpisz haslo nowego uzytkownika: ";
    cin >> haslo;
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
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikManager::wypiszWszystkichUzytkownikow()
{
for (int i = 0; i < uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkownikManager::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikManager::logowanieUzytkownika()
{
    string login, haslo;
    cout << "Podaj login: ";
    cin >> login;
    cout << "Podaj haslo: ";
    cin >> haslo;

    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            if (uzytkownicy[i].pobierzHaslo() == haslo)
            {
                idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                cout << endl << "Zalogowales sie." << endl << endl;
                system("pause");
                return;
            }
            else
            {
                for (int iloscProb = 2; iloscProb > 0; iloscProb--)
                {
                    cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                    cin >> haslo;

                    if (uzytkownicy[i].pobierzHaslo() == haslo)
                    {
                        idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                        cout << endl << "Zalogowales sie." << endl << endl;
                        system("pause");
                        return;
                    }
                }
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
                return;
            }
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
}

void UzytkownikManager::zmianaHasla()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            plikZUzytkownikami.aktualizujHasloUzytkownika(uzytkownicy[i]); // Aktualizuj has³o w pliku
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie udalo sie zmienic hasla." << endl << endl;
    system("pause");
}

void UzytkownikManager::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
    cout << "Nacisnij dowolny przycisk, aby sie wylogowac." << endl;
    system("pause");
    cout << "Wylogowano pomyslnie." << endl;
}


