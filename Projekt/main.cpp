//
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : main.cpp
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

// Deklaracja zależności i bibliotek
#include "System.h"

// Funkcja main
int main() {
    // Utworzenie obiektu systemu
    System system = System("System Obslugi Studiow");
    // Uruchomienie systemu
    system.boot();

    // Zmienna przechowująca wybór użytkownika
    std::string userInput;

    // Wyświetl opcje
    std::cout << "Wybierz opcje:" << "\n";
    std::cout << "1. System Obslugi Studiow dla Studentow" << "\n";
    std::cout << "2. System Obslugi Studiow dla Wykladowcow" << "\n";

    // Pętla wyboru wersji systemu
    while(true) {
        // Pobierz wybór użytkownika
        std::cin >> userInput;
        // Jeżeli użytkownik wybrał opcję 1
        if(userInput == "1") {
            // Wywołaj metodę systemu studenta
            system.studentSystem();
            // Jeżeli użytkownik wybrał opcję 2
        } else if(userInput == "2") {
            // Wywołaj metodę systemu wykładowcy
            system.lecturerSystem();
            // Jeżeli użytkownik wybrał inną opcję
        } else {
            std::cout << "Niepoprawna opcja!" << "\n";
        }
    }

    return 0;
}
