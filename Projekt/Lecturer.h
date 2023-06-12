//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : System Obsługi Studiów
//  @ File Name : Lecturer.h
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
// 

#if !defined(_LECTURER_H)
#define _LECTURER_H

// Deklaracja zależności i bibliotek
#include <string>
#include <vector>
#include "User.h"
#include "Course.h"

// Deklaracja klas
class Course;

// Deklaracja klasy Lecturer dziedziczącej po klasie User
class Lecturer : public User {
	using User::User;  // Dziedziczenie konstruktorów klasy User
public:
	void addCourse(Course * course);  // Metoda dodająca kurs do wektora kursów wykładowcy
	void removeCourse(std::string courseName);  // Metoda usuwająca kurs z wektora kursów wykładowcy
    int getCoursesSize();  // Akcesor rozmiaru wektora kursów wykładowcy
    Course * getCourseAtIndex(int courseIndex);  // Metoda zwracająca kurs z wektora kursów wykładowcy o podanym indeksie
    void printCourses();  // Metoda wyświetlająca kursy wykładowcy
private:
	std::vector <Course *> courses;  // Wektor kursów
};

#endif  //_LECTURER_H
