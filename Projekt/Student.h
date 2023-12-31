//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : System Obsługi Studiów
//  @ File Name : Student.h
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#if !defined(_STUDENT_H)
#define _STUDENT_H

// Deklaracja zależności i bibliotek
#include <string>
#include <vector>
#include "User.h"
#include "Course.h"

// Deklaracja klas
class Course;

// Deklaracja klasy Student dziedziczącej po klasie User
class Student : public User {
    using User::User;  // Dziedziczenie konstruktorów klasy User
public:
	void addCourse(Course * course);  // Metoda dodająca kurs do wektora kursów studenta
    void removeCourse(std::string courseName);  // Metoda usuwająca kurs z wektora kursów studenta
    int getCoursesSize();  // Akcesor rozmiaru wektora kursów studenta
    Course * getCourseAtIndex(int courseIndex); // Metoda zwracająca kurs z wektora kursów studenta o podanym indeksie
    void printCourses();  // Metoda wyświetlająca kursy studenta
private:
    std::vector <Course *> courses;  // Wektor kursów
};

#endif  //_STUDENT_H
