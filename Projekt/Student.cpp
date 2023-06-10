//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : Student.cpp
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#include "Student.h"

void Student::dodajKurs(Kurs *kurs) {
	kursy.push_back(kurs);
}

void Student::usunKurs(std::string nazwa) {
	for (int i = 0; i < kursy.size(); i++) {
		if (kursy[i]->getNazwa() == nazwa) {
			kursy.erase(kursy.begin() + i);
		}
	}
}

Kurs * Student::getKurs(int index) {
    return kursy[index];
}

void Student::printKursy() {
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::cout << "-----------------------------------Twoje Kursy-----------------------------------------\n";
    std::cout << "---------------------------------------------------------------------------------------\n";
    for(int i = 0; i < kursy.size(); i++) {
        std::cout << kursy[i]->getNazwa() << "\n";
    }
}
