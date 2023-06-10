//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : Kurs.cpp
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#include <iostream>
#include "Kurs.h"

Kurs::Kurs(std::string nazwa, Prowadzacy * prowadzacy) {
	this->nazwa = nazwa;
	this->prowadzacy = prowadzacy;
}

std::string Kurs::getNazwa() {
	return nazwa;
}

void Kurs::dodajUczestnika(Student *student) {
	uczestincy.push_back(student);
}

void Kurs::usunUczestnika(std::string login) {
	for (int i = 0; i < uczestincy.size(); i++) {
		if (uczestincy[i]->getLogin() == login) {
			uczestincy.erase(uczestincy.begin() + i);
		}
	}
}

void Kurs::dodajMaterial(Material *material) {
	materialy.push_back(material);
}

void Kurs::usunMaterial(std::string nazwa) {
	for (int i = 0; i < materialy.size(); i++) {
		if (materialy[i]->getNazwa() == nazwa) {
			materialy.erase(materialy.begin() + i);
		}
	}
}

void Kurs::utworzWideokonferencje(std::string nazwa) {
	this->nazwa = nazwa;
}

void Kurs::zakonczWideokonferencje() {
	std::cout << "Zakonczono wideokonferencje\n";
	wideokonferencja = nullptr;
}

void Kurs::wyswietlStroneKursu() {
	std::cout << "---------------------------------------------------------------------------------------\n";
	std::cout << "--------------------------" << getNazwa() << "---------------------------------------\n";
	std::cout << "---------------------------------------------------------------------------------------\n";
	std::cout << "Prowadzacy: " << prowadzacy->getImie() << " " << prowadzacy->getNazwisko() << "\n";
	std::cout << "Uczestnicy: \n";
	for (int i = 0; i < uczestincy.size(); i++) {
		std::cout << i + 1 << ". " << uczestincy[i]->getImie() << " " << uczestincy[i]->getNazwisko() << "\n";
	}
}

void Kurs::otworzMenuStudenta(Uzytkownik *uzytkownik) {
	while (true) {
		std::string userInput;
		std::cout << "Jestes na stronie kursu: " << this->nazwa << "\n";
		std::cout << "Wybierz opcje:\n";
		std::cout << "1. Wyswietl strone kursu\n";
		std::cout << "2. Otworz materialy\n";
		std::cout << "3. Dolacz do wideokonferencji\n";
		std::cout << "4. Wroc\n";
		std::cin >> userInput;

		if (userInput == "1") {
			wyswietlStroneKursu();
		} else if (userInput == "2") {
			for (int i = 0; i < materialy.size(); i++) {
				std::cout << i << ". " << materialy.at(i)->getNazwa() << "\n";
			}
			std::cin >> userInput;
			if (std::stoi(userInput) > 0 && std::stoi(userInput) < materialy.size()) {
				materialy.at(std::stoi(userInput))->otworzMenu();
			} else {
				std::cout << "Niepoprawna opcja";
			}
		} else if (userInput == "3") {
			if (wideokonferencja != nullptr) {
				wideokonferencja->dodajUczestnika((Student *)uzytkownik);
				wideokonferencja->otworzMenuStudenta(uzytkownik);
			} else {
				std::cout << "Wideokonferencja nie jest utworzona";
			}
		} else if (userInput == "4") {
			break;
		} else {
			std::cout << "Niepoprawna opcja!\n";
		}
	}
}

void Kurs::otworzMenuProwadzacego(Uzytkownik *uzytkownik) {
	while (true) {
		std::string userInput;
		std::cout << "Jestes na stronie kursu: " << this->nazwa << "\n";
		std::cout << "Wybierz opcje:\n";
		std::cout << "1. Wyswietl strone kursu\n";
		std::cout << "2. Otworz materialy\n";
		std::cout << "3. Utworz wideokonferencje\n";
		std::cin >> userInput;

		if (userInput == "1") {
			wyswietlStroneKursu();
		} else if (userInput == "2") {
			for (int i = 0; i < materialy.size(); i++) {
				std::cout << i << ". " << materialy.at(i)->getNazwa() << "\n";
			}
			std::cin >> userInput;
			if (std::stoi(userInput) > 0 && std::stoi(userInput) < materialy.size()) {
				materialy.at(std::stoi(userInput))->otworzMenu();
			} else {
				std::cout << "Niepoprawna opcja";
			}
		} else if (userInput == "3") {
			if (wideokonferencja == nullptr) {
				wideokonferencja = new Wideokonferencja("Wideokonferencja",
				(Prowadzacy *)uzytkownik);
				wideokonferencja->otworzMenuProwadzacego(uzytkownik);
			} else {
				std::cout << "Wideokonferencja nie jest utworzona";
			}
		} else if (userInput == "4") {
			break;
		} else {
			std::cout << "Niepoprawna opcja!\n";
		}
	}
}
