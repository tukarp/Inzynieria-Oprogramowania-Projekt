//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : Kurs.h
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#if !defined(_KURS_H)
#define _KURS_H

#include <string>
#include <vector>
#include "Student.h"
#include "Prowadzacy.h"
#include "Material.h"
#include "Wideokonferencja.h"
class Prowadzacy;
class Student;
class Wideokonferencja;
class Kurs {
public:
	Kurs(std::string nazwa, Prowadzacy *prowadzacy);
	std::string getNazwa();
	void dodajUczestnika(Student *student);
	void dodajMaterial(Material *material);
	void utworzWideokonferencje(std::string nazwa);
	void usunMaterial(std::string nazwa);
	void zakonczWideokonferencje();
	void usunUczestnika(std::string login);
private:
	std::string nazwa;
	std::vector <Material *> materialy;
	std::vector <Student *> uczestincy;
	Prowadzacy *prowadzacy;
	Wideokonferencja *wideokonferencja;
};

#endif  //_KURS_H
