//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : System Obsługi Studiów
//  @ File Name : System.h
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#if !defined(_SYSTEM_H)
#define _SYSTEM_H

#include <string>
#include <vector>

#include "User.h"
#include "Course.h"

/*
 * Klasa systemu obsługi studiów
 */
class System {
public:

    /*
     * Konstruktor
     *
     * @param name Nazwa systemu
     */
    System(std::string name);

    /*
     * Zwraca nazwę systemu
     *
     * @return Nazwa systemu
     */
    std::string getName();

    /*
     * Autoryzuje użytkownika
     *
     * @param user Użytkownik
     * @param login Login
     * @param password Hasło
     *
     * @return Czy autoryzacja się powiodła
     */
    bool authentication(User * user, std::string login, std::string password);

    /*
     * Loguje użytkownika
     *
     * @param user Użytkownik
     */
    void login(User * user);

    /*
     * Rejestruje użytkownika
     *
     * @param user Użytkownik
     */
    void registerUser(User * user);

    /*
     * Usuwa użytkownika z wektora użytkowników
     *
     * @param login Login
     */
    void deleteUser(std::string login);

    /*
     * Dodaje kurs do wektora kursów
     *
     * @param course Kurs
     */
    void addCourse(Course * course);

    /*
     * Zwraca rozmiar wektora kursów
     *
     * @return Rozmiar wektora kursów
     */
    int getCoursesSize();

    /*
     * Wyświetla kursy
     */
    void printCourses();

    /*
     * Usuwa kurs z systemu
     *
     * @param courseName Nazwa kursu
     */
    void deleteCourse(std::string courseName);

    /*
     * Uruchamia system
     */
    void boot();

    /*
     * Uruchamia system w wersji studenckiej
     */
    void studentSystem();

    /*
     * Uruchamia system w wersji wykładowcy
     */
    void lecturerSystem();

    /*
     * Otwiera menu kursów dla studenta
     *
     * @param student Student
     */
    void studentCourseMenu(Student * student);

    /*
     * Otwiera menu kursów dla wykładowcy
     *
     * @param lecturer Wykładowca
     */
    void lecturerCourseMenu(Lecturer * lecturer);

    /*
     * Wczytuje użytkowników z pliku CSV
     *
     * @param fileName Nazwa pliku
     */
    void loadUsersFromCSV(const std::string& fileName);

    /*
     * Zapisuje użytkowników do pliku CSV
     *
     * @param fileName Nazwa pliku
     */
    void saveUsersToCSV(const std::string& fileName);

    /*
     * Wczytuje kursy z pliku CSV
     *
     * @param fileName Nazwa pliku
     */
    void loadCoursesFromCSV(const std::string& fileName);

    /*
     * Zapisuje kursy do pliku CSV
     *
     * @param fileName Nazwa pliku
     */
    void saveCoursesToCSV(const std::string& fileName);

private:

    /*
     * Nazwa systemu
     */
    std::string name;

    /*
     * Wektor kursów
     */
    std::vector <Course *> courses;

    /*
     * Wektor użytkowników
     */
    std::vector <User *> users;
};

#endif  //_SYSTEM_H