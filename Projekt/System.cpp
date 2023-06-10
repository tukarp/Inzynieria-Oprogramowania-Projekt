//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : System.cpp
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "System.h"

System::System(std::string nazwa) {
    this->nazwa = nazwa;
}

std::string System::getNazwa() {
    return nazwa;
}

void System::login(Uzytkownik * uzytkownik) {
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::cout << "--------------------------------------Logowanie----------------------------------------\n";
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::string loginUzytkownika;
    std::string hasloUzytkownika;

    std::cout << "Login: ";
    std::cin >> loginUzytkownika;

    std::cout << "Haslo: ";
    std::cin >> hasloUzytkownika;

    for(int i = 0; i < uzytkownicy.size(); i++) {
        if(uzytkownicy[i]->getLogin() == loginUzytkownika && uzytkownicy[i]->getHaslo() == hasloUzytkownika) {
            std::cout << "Zalogowano pomyslnie!\n";
            return;
        }
    }
    std::cout << "Niepoprawny login lub haslo!\n";
    rejestracja(uzytkownik);
}

void System::rejestracja(Uzytkownik * uzytkownik) {
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::cout << "-------------------------------------Rejestracja---------------------------------------\n";
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::string userInput;

    std::cout << "Login: ";
    std::cin >> userInput;
    uzytkownik->setLogin(userInput);

    std::cout << "Haslo: ";
    std::cin >> userInput;
    uzytkownik->setHaslo(userInput);

    std::cout << "Imie: ";
    std::cin >> userInput;
    uzytkownik->setImie(userInput);

    std::cout << "Nazwisko: ";
    std::cin >> userInput;
    uzytkownik->setNazwisko(userInput);

    std::cout << "Email: ";
    std::cin >> userInput;
    uzytkownik->setEmail(userInput);
}

void System::dodajKurs(Kurs * kurs) {
    kursy.push_back(kurs);
}

void System::usunKurs(std::string nazwa) {
    for(int i = 0; i < kursy.size(); i++) {
        if(kursy[i]->getNazwa() == nazwa) {
            kursy.erase(kursy.begin() + i);
        }
    }
}

void System::usunUzytkownika(std::string login) {
    for(int i = 0; i < uzytkownicy.size(); i++) {
        if(uzytkownicy[i]->getLogin() == login) {
            uzytkownicy.erase(uzytkownicy.begin() + i);
        }
    }
}

void System::printKursy() {
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::cout << "---------------------------------------Kursy-------------------------------------------\n";
    std::cout << "---------------------------------------------------------------------------------------\n";
    for(int i = 0; i < kursy.size(); i++) {
        std::cout << i + 1 << "." << kursy[i]->getNazwa() << "\n";
    }
}

void System::printUzytkownik(Uzytkownik * uzytkownik) {
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::cout << "--------------------------------------Uzytkownik---------------------------------------\n";
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::string ukryteHasloUzytkownika = uzytkownik->getHaslo();
    ukryteHasloUzytkownika.replace(0, ukryteHasloUzytkownika.length(), ukryteHasloUzytkownika.length(), '*');
    std::cout << "Login: " << uzytkownik->getLogin() << "\n";
    std::cout << "Haslo: " << ukryteHasloUzytkownika << "\n";
    std::cout << "Imie: " << uzytkownik->getImie() << "\n";
    std::cout << "Nazwisko: " << uzytkownik->getNazwisko() << "\n";
    std::cout << "Email: " << uzytkownik->getEmail() << "\n";
}

void System::wczytajUzytkownikow(const std::string& fileName) {
    std::ifstream file(fileName);

    if(!file.is_open()) {
        std::cout << "Nie mozna otworzyc pliku: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string imie, nazwisko, login, haslo, email;
        if((std::getline(ss, imie, ' ') &&
            std::getline(ss, nazwisko, ',') &&
            std::getline(ss, login, ',')) &&
            std::getline(ss, haslo, ',') &&
            std::getline(ss, email, ',')) {
                uzytkownicy.push_back(new Uzytkownik(imie, nazwisko, login, haslo, email));
        }
    }
    file.close();
}

void System::wczytajKursy(const std::string& fileName) {
    std::ifstream file(fileName);

    if(!file.is_open()) {
        std::cout << "Nie mozna otworzyc pliku: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string nazwaKursu, imieProwadzacego, nazwiskoProwadzacego;
        if(std::getline(ss, nazwaKursu, ',') && std::getline(ss, imieProwadzacego, ' ') && std::getline(ss, nazwiskoProwadzacego, ' ')) {
            kursy.push_back(new Kurs(nazwaKursu, new Prowadzacy(imieProwadzacego, nazwiskoProwadzacego)));
        }
    }
    file.close();
}

void System::boot() {
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::cout << "--------------------------------" << getNazwa() << "-----------------------------------\n";
    std::cout << "---------------------------------------------------------------------------------------\n";
    wczytajKursy("P:\\Zadania\\C++\\Inzynieria-Oprogramowania-Projekt\\Projekt\\kursy.csv");
    wczytajUzytkownikow("P:\\Zadania\\C++\\Inzynieria-Oprogramowania-Projekt\\Projekt\\uzytkownicy.csv");
    std::string userInput;

    get


    std::cout << "Kim jestes:\n";
    std::cout << "1.Student\n";
    std::cout << "2.Prowadzacy\n";
    while(true) {
        std::cin >> userInput;
        if(userInput == "1" || userInput == "Student" || userInput == "student") {
            bootStudent();
        } else if(userInput == "2" || userInput == "Prowadzacy" || userInput == "prowadzacy") {
            bootProwadzacy();
        } else {
            std::cout << "Niepoprawna opcja!\n";
        }
    }
}

void System::bootStudent() {
    Student * student = new Student("", "", "", "", "");
    login(student);
    std::string userInput;
    while(true) {
        std::cout << "Wybierz opcje:\n";
        std::cout << "1. Kursy\n";
        std::cout << "2. Wyswietl swoj profil\n";
        std::cout << "3. Wyloguj sie\n";
        std::cin >> userInput;
        if(userInput == "1") {
            obslugaKursowStudenta(student);
        } else if(userInput == "2") {
            printUzytkownik(student);
        } else if(userInput == "3") {
            exit(0);
        } else {
            std::cout << "Niepoprawna opcja!\n";
        }
    }
}

void System::bootProwadzacy() {
    Prowadzacy * prowadzacy = new Prowadzacy("", "", "", "", "");
    login(prowadzacy);
    std::string userInput;
    while(true) {
        std::cout << "Wybierz opcje:\n";
        std::cout << "1. Kursy\n";
        std::cout << "2. Wyswietl swoj profil\n";
        std::cout << "3. Wyloguj sie\n";
        std::cin >> userInput;
        if(userInput == "1") {
            obslugaKursowProwadzacego(prowadzacy);
        } else if(userInput == "2") {
            printUzytkownik( prowadzacy);
        } else if(userInput == "3") {
            exit(0);
        } else {
            std::cout << "Niepoprawna opcja!\n";
        }
    }
}

void System::obslugaKursowStudenta(Student * student) {
    std::string userInput;
    while(true) {
        std:: cout << "Wybierz opcje:\n";
        std:: cout << "1. Wejdz do kursu\n";
        std:: cout << "2. Zapisz sie na kurs\n";
        std:: cout << "3. Wypisz sie z kursu\n";
        std:: cout << "4. Wyswietl swoje kursy\n";
        std:: cout << "5. Wyswietl wszystkie kursy\n";
        std:: cout << "6. Wroc\n";
        std::cin >> userInput;

        if(userInput == "1") {
            student->printKursy();
            std::cout << "Wybierz kurs: ";
            std::cin >> userInput;
            if(std::stoi(userInput) - 1 < student->getKursySize()) {
                student->getKurs(std::stoi(userInput) - 1)->wyswietlStroneKursu();
            } else {
                std::cout << "Ten kurs nie istnieje!\n";
                break;
            }
        } else if(userInput == "2") {
            printKursy();
            std::cout << "Wybierz kurs: ";
            std::cin >> userInput;
            if(std::stoi(userInput) - 1 < student->getKursySize()) {
                student->dodajKurs(kursy[std::stoi(userInput) - 1]);
            } else {
                std::cout << "Ten kurs nie istnieje!\n";
                break;
            }
        } else if(userInput == "3") {
            student->printKursy();
            std::cout << "Wybierz kurs: ";
            std::cin >> userInput;
            if(std::stoi(userInput) - 1 < student->getKursySize()) {
                student->usunKurs(kursy[std::stoi(userInput) - 1]->getNazwa());
            } else {
                std::cout << "Ten kurs nie istnieje!\n";
                break;
            }
        } else if(userInput == "4") {
            student->printKursy();
        } else if(userInput == "5") {
            printKursy();
        } else if(userInput == "6") {
            break;
        } else {
            std::cout << "Niepoprawna opcja!\n";
        }
    }
}

void System::obslugaKursowProwadzacego(Prowadzacy * prowadzacy) {
    std::string userInput;
    while (true) {
        std::cout << "Wybierz opcje:\n";
        std::cout << "1. Wejdz do kursu\n";
        std::cout << "2. Zapisz sie na kurs\n";
        std::cout << "3. Wypisz sie z kursu\n";
        std::cout << "4. Wyswietl swoje kursy\n";
        std::cout << "5. Wyswietl wszystkie kursy\n";
        std::cout << "6. Wroc\n";
        std::cin >> userInput;

        if (userInput == "1") {
            prowadzacy->printKursy();
            std::cout << "Wybierz kurs: ";
            std::cin >> userInput;
            if (std::stoi(userInput) - 1 < prowadzacy->getKursySize()) {
                prowadzacy->getKurs(std::stoi(userInput) - 1)->wyswietlStroneKursu();
            } else {
                std::cout << "Ten kurs nie istnieje!\n";
                break;
            }
        } else if (userInput == "2") {
            printKursy();
            std::cout << "Wybierz kurs: ";
            std::cin >> userInput;
            if (std::stoi(userInput) - 1 < prowadzacy->getKursySize()) {
                prowadzacy->dodajKurs(kursy[std::stoi(userInput) - 1]);
            } else {
                std::cout << "Ten kurs nie istnieje!\n";
                break;
            }
        } else if (userInput == "3") {
            prowadzacy->printKursy();
            std::cout << "Wybierz kurs: ";
            std::cin >> userInput;
            if (std::stoi(userInput) - 1 < prowadzacy->getKursySize()) {
                prowadzacy->usunKurs(kursy[std::stoi(userInput) - 1]->getNazwa());
            } else {
                std::cout << "Ten kurs nie istnieje!\n";
                break;
            }
        } else if (userInput == "4") {
            prowadzacy->printKursy();
        } else if (userInput == "5") {
            printKursy();
        } else if (userInput == "6") {
            break;
        } else {
            std::cout << "Niepoprawna opcja!\n";
        }
    }
}
