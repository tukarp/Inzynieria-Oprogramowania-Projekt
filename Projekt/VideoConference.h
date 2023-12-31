//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : System Obsługi Studiów
//  @ File Name : VideoConference.h
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#if !defined(_VIDEOCONFERENCE_H)
#define _VIDEOCONFERENCE_H

// Deklaracja zależności i bibliotek
#include <iostream>
#include <string>
#include <vector>
#include "Lecturer.h"
#include "Student.h"

// Deklaracja klas
class Lecturer;
class Student;

// Deklaracja klasy VideoConference
class VideoConference {
public:
	VideoConference(std::string name, Lecturer * lecturer);  // Konstruktor
	void addStudent(Student * student);  // Metoda dodająca studenta do wideokonferencji
	void removeStudent(std::string login);  // Metoda usuwająca studenta z wideokonferencji
	void openStudentVideoConferenceMenu(Student * student);  // Metoda otwierająca menu wideokonferencji dla studenta
	void openLecturerVideoConferenceMenu(Lecturer * lecturer);  // Metoda otwierająca menu wideokonferencji dla wykładowcy
private:
	std::string name;  // Nazwa wideokonferencji
	Lecturer * lecturer;  // Wykładowca prowadzący wideokonferencję
	std::vector <Student *> students;  // Wektor studentów uczestniczących w wideokonferencji
};

#endif  //_VIDEOCONFERENCE_H
