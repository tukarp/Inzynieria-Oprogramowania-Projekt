//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : Prowadzacy.h
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#if !defined(_PROWADZACY_H)
#define _PROWADZACY_H

#include <string>
#include <vector>
#include "Uzytkownik.h"
#include "Kurs.h"

class Kurs;
class Prowadzacy : public Uzytkownik {
	using Uzytkownik::Uzytkownik;
public:
	void dodajKurs(Kurs *kurs);
	void usunKurs(std::string nazwa);
private:
	std::vector <Kurs *> kursy;
};

#endif  //_PROWADZACY_H
