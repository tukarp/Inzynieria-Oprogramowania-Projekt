//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : Material.cpp
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#include "Material.h"

Material::Material(std::string nazwa, int rozmiar, Uzytkownik *dodanyPrzez) {
	this->nazwa = nazwa;
	this->rozmiar = rozmiar;
	this->dodanyPrzez = dodanyPrzez;
}

std::string Material::getNazwa() {
	return nazwa;
}

int Material::getRozmiar() {
	return rozmiar;
}

Uzytkownik *Material::getDodanyPrzez() {
	return dodanyPrzez;
}

void Material::printData() {
	std::cout << "Nazwa: " << this->nazwa << "\n" <<
		"Rozmiar: " << this->rozmiar << "\n" <<
		"Dodany przez: " << this->dodanyPrzez << "\n";
}

void Material::otworzMenu() {
	while (true) {
		std::string userInput;
		std::cout << "Material: " << this->nazwa << "\n";
		std::cout << "Wybierz opcje:\n";
		std::cout << "1. Wyswietl dane\n";
		std::cout << "2. Pobierz plik\n";
		std::cout << "3. Wroc\n";
		std::cin >> userInput;
		if (userInput == "1") {
			this->printData();
		} else if (userInput == "2") {
			loadingBar();
		} else if (userInput == "3") {
			break;
		} else {
			std::cout << "Niepoprawna opcja!\n";
		}
	}
}

void Material::loadingBar() {
	int barWidth = 70;
	int duration = 100;
	int total = 10;

	for (int i = 0; i < total; ++i) {
		std::cout << "[";
		int progress = (barWidth * i) / total;
		for (int j = 0; j < barWidth; ++j) {
			if (j < progress) {
				std::cout << "=";
			} else if (j == progress) {
				std::cout << ">";
			} else {
				std::cout << " ";
			}
		}
		std::cout << "] " << int((float(i) / total) * 100.0) << "%\r";
		std::cout.flush();

		std::this_thread::sleep_for(std::chrono::milliseconds(duration));
	}

	std::cout << std::endl;
	std::cout << "Pobrano plik";
}
