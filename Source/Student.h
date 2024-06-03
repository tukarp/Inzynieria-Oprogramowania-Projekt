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

#include <string>
#include <vector>

#include "User.h"
#include "Course.h"

class Course;

/**
 * Klasa studenta
 */
class Student : public User {
    using User::User;
public:

    /**
     * Dodaje kurs do wektora kursów studenta
     *
     * @param course Kurs
     */
	void addCourse(Course * course);

    /**
     * Usuwa kurs z wektora kursów studenta
     *
     * @param courseName Nazwa kursu
     */
    void removeCourse(std::string courseName);

    /**
     * Zwraca rozmiar wektora kursów studenta
     *
     * @return Rozmiar wektora kursów studenta
     */
    int getCoursesSize();

    /**
     * Zwraca kurs z wektora kursów studenta o podanym indeksie
     *
     * @param courseIndex Indeks kursu
     *
     * @return Kurs
     */
    Course * getCourseAtIndex(int courseIndex);

    /**
     * Wyświetla kursy studenta
     */
    void printCourses();

private:

    /**
     * Wektor kursów studenta
     */
    std::vector <Course *> courses;
};

#endif  //_STUDENT_H