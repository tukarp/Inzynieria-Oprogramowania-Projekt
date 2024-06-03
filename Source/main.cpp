//
//
//  @ Project : System Obsługi Studiów
//  @ File Name : main.cpp
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#include "System.h"

int main() {
    System system = System("System Obslugi Studiow");
    system.boot();

    std::string userInput;
    std::cout << "Wybierz opcje:" << "\n";
    std::cout << "1. System Obslugi Studiow dla Studentow" << "\n";
    std::cout << "2. System Obslugi Studiow dla Wykladowcow" << "\n";

    while (true) {
        std::cin >> userInput;
        if (userInput == "1") {
            system.studentSystem();
            break;
        } else if (userInput == "2") {
            system.lecturerSystem();
            break;
        } else {
            std::cout << "Niepoprawny opcja" << "\n";
        }
    }

    return 0;
}
