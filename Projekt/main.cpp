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

    return 0;
}
