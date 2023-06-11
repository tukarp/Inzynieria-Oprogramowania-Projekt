//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : Course.h
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#if !defined(_COURSE_H)
#define _COURSE_H

// Deklaracja zależności i bibliotek
#include <string>
#include <vector>
#include "Student.h"
#include "Lecturer.h"
#include "Material.h"
#include "VideoConference.h"

// Deklaracja klas
class Lecturer;
class Student;
class VideoConference;

// Deklaracja klasy Course
class Course {
public:
	Course(std::string name, Lecturer * lecturer);  // Konstruktor klasy Course przyjmujący nazwę kursu i wykładowcę prowadzącego kurs
    Course(std::string name, Lecturer * lecturer, std::string isVideoConferenceCreated);  // Konstruktor klasy Course przyjmujący nazwę kursu, wykładowcę prowadzącego kurs i informację o tym, czy wideokonferencja została utworzona
    std::string getName();  // Accessor pola name
    void setName(std::string name);  // Mutator pola name
	void addUser(Student * student);  // Metoda dodająca studenta do kursu
    void deleteUser(std::string login);  // Metoda usuwająca studenta z kursu
	void addMaterial(Material * material);  // Metoda dodająca materiał do kursu
    void deleteMaterial(std::string name);  // Metoda usuwająca materiał z kursu
	void createVideoConference(std::string name);  // Metoda tworząca wideokonferencję
	void endVideoConference();  // Metoda kończąca wideokonferencję
    void displayHeader(const std::string& name);  // Metoda wyświetlająca nagłówek
	void viewCoursePage();  // Metoda wyświetlająca stronę kursu
    void openStudentCourseMenu(Student * student);  // Metoda otwierająca menu kursu dla studenta
    void openLecturerCourseMenu(Lecturer * lecturer);  // Metoda otwierająca menu kursu dla wykładowcy
    void openMaterialsMenu(User * user);  // Metoda otwierająca menu materiałów
private:
	std::string name;  // Nazwa kursu
    Lecturer * lecturer;  // Wykładowca prowadzący kurs
    std::vector <Student *> students;  // Wektor studentów uczęszczających na kurs
	std::vector <Material *> materials;  // Wektor materiałów przypisanych do kursu
	VideoConference * videoConference;  // Wideokonferencja
};

#endif  //_COURSE_H
