//
//
//
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : main.cpp
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#include <iostream>
#include "System.h"
#include "Kurs.h"
#include "Wideokonferencja.h"
#include "Uzytkownik.h"


using namespace std;

int main() {
	Uzytkownik *prowadzacy = new Prowadzacy("Marek", "Nowak", "mnowak123", "haslo123", "mnowak@gmail.com");
	System *system = new System("Uczelnia");
	system->dodajKurs(new Kurs("Programowanie", (Prowadzacy *)prowadzacy));
	system->getKursy().at(0)->utworzWideokonferencje("Wideokonferencja1");
	return 0;
}
