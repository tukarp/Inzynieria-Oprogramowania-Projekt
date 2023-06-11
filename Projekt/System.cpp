//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : System.cpp
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

// Deklaracja zależności i bibliotek
#include <iostream>
#include <fstream>
#include <sstream>
#include "System.h"

// Logo systemu
const std::string logo = R"(
  ___         _                ___  _       _           _   ___ _           _ _
 / __|_  _ __| |_ ___ _ __    / _ \| |__ __| |_  _ __ _(_) / __| |_ _  _ __| (_)_____ __ __
 \__ \ || (_-<  _/ -_) '  \  | (_) | '_ (_-< | || / _` | | \__ \  _| || / _` | / _ \ V  V /
 |___/\_, /__/\__\___|_|_|_|  \___/|_.__/__/_|\_,_\__, |_| |___/\__|\_,_\__,_|_\___/\_/\_/
      |__/                                        |___/
)";

// Ścieżka do pliku z kursami
const std::string coursesFilePath = "P:\\Zadania\\C++\\Inzynieria-Oprogramowania-Projekt\\Projekt\\courses.csv"; ;/*"courses.txt";*/

// Ścieżka do pliku z użytkownikami
const std::string usersFilePath = "P:\\Zadania\\C++\\Inzynieria-Oprogramowania-Projekt\\Projekt\\users.csv"; /*"users.txt";*/

// Konstruktor klasy System
System::System(std::string name) {
    this->name = name;
}

// Akcesor nazwy systemu
std::string System::getName() {
    return name;
}

// Metoda wyświetlająca nagłówek
void System::displayHeader(const std::string& name) {
    const int totalWidth = 90;  // Szerokość całego wyświetlanego napisu
    const int nameWidth = name.length();  // Szerokość nazwy kursu
    const int paddingWidth = (totalWidth - nameWidth) / 2;  // Szerokość wypełnienia
    // Wyświetl nagłówek
    std::cout << "==========================================================================================\n";
    std::cout << std::string(paddingWidth, ' ') << name << "\n";
    std::cout << "==========================================================================================\n";
}

// Metoda autoryzująca użytkownika
bool System::authentication(User * user, std::string login, std::string password) {
    // Dla każdego użytkownika w wektorze users
    for(int i = 0; i < users.size(); i++) {
        // Jeżeli login i hasło użytkownika zgadzają się ze znalezionym użytkownikiem
        if(users[i]->getLogin() == login && users[i]->getPassword() == password) {
            // Ustaw dane użytkownika
            user->setLogin(users[i]->getLogin());  // Ustaw login użytkownika
            user->setPassword(users[i]->getPassword());  // Ustaw hasło użytkownika
            user->setFirstName(users[i]->getFirstName());  // Ustaw imię użytkownika
            user->setLastName(users[i]->getLastName());  // Ustaw nazwisko użytkownika
            user->setEmail(users[i]->getEmail());  // Ustaw email użytkownika

            // Zwróć prawdę
            return true;
        }
    }
    // Jeżeli nie znaleziono użytkownika, zwróć fałsz
    return false;
}

// Metoda logująca użytkownika
void System::login(User * user) {
    // Zadeklaruj zmienne przechowujące login i hasło użytkownika
    std::string loginUzytkownika;
    std::string hasloUzytkownika;

    // Wyświetl nagłówek logowania
    displayHeader("Logowanie");

    // Zaloguj użytkownika
    std::cout << "Login: ";         // Wyświetl informacje o podaniu loginu
    std::cin >> loginUzytkownika;   // Pobierz login od użytkownika

    std::cout << "Haslo: ";         // Wyświetl informacje o podaniu hasła
    std::cin >> hasloUzytkownika;   // Pobierz hasło od użytkownika

    // Jeżeli autoryzacja użytkownika przebiegła pomyślnie
    if(authentication(user, loginUzytkownika, hasloUzytkownika)) {
        // Wyświetl nagłówek o zalogowaniu
        displayHeader("Zalogowano");
        // Zakończ działanie metody logowania
        return;
    // W przeciwnym wypadku
    } else {
        // Wyświetl informacje o niepoprawnym loginie lub haśle
        std::cout << "Niepoprawny login lub haslo!" << "\n";
        // Wywołaj metodę rejestracji użytkownika
        registerUser(user);
    }
}

// Metoda rejestrująca użytkownika
void System::registerUser(User * user) {
    // Utwórz zmienną przechowującą wybór użytkownika
    std::string userInput;

    // Wyświetl nagłówek rejestracji
    displayHeader("Rejestracja");

    // Zarejestruj użytkownika
    std::cout << "Login: ";         // Wyświetl informacje o podaniu loginu
    std::cin >> userInput;          // Pobierz login od użytkownika
    user->setLogin(userInput);      // Ustaw login użytkownika

    std::cout << "Haslo: ";         // Wyświetl informacje o podaniu hasła
    std::cin >> userInput;          // Pobierz hasło od użytkownika
    user->setPassword(userInput);   // Ustaw hasło użytkownika

    std::cout << "Imie: ";          // Wyświetl informacje o podaniu imienia
    std::cin >> userInput;          // Pobierz imię od użytkownika
    user->setFirstName(userInput);  // Ustaw imię użytkownika

    std::cout << "Nazwisko: ";      // Wyświetl informacje o podaniu nazwiska
    std::cin >> userInput;          // Pobierz nazwisko od użytkownika
    user->setLastName(userInput);   // Ustaw nazwisko użytkownika

    std::cout << "Email: ";         // Wyświetl informacje o podaniu emaila
    std::cin >> userInput;          // Pobierz email od użytkownika
    user->setEmail(userInput);      // Ustaw email użytkownika

    // Dodaj użytkownika do wektora użytkowników
    users.push_back(user);
    // Zapisz użytkownika do pliku użytkowników w formacie CSV
    saveUsersToCSV(usersFilePath);
}

// Metoda dodająca kurs do wektora kursów
void System::addCourse(Course * course) {
    // Dodaj kurs do wektora kursów
    courses.push_back(course);
}

// Akcesor rozmiaru wektora kursów
int System::getCoursesSize() {
    // Zwróć rozmiar wektora kursów
    return courses.size();
}

// Metoda wyświetlająca kursy
void System::printCourses() {
    // Wyświetl nazwy kursów
    displayHeader("Kursy");

    // Dla każdego kursu w wektorze kursów
    for(int i = 0; i < courses.size(); i++) {
        // Wyświetl numer kursu i nazwę kursu
        std::cout << i + 1 << ". " << courses[i]->getName() << "\n";
    }
}

// Metoda usuwająca kurs z systemu
void System::deleteCourse(std::string courseName) {
    // Przeszuakj wektor kursów
    for(int i = 0; i < courses.size(); i++) {
        // Jeżeli nazwa kursu jest równa nazwie kursu podanej jako argument
        if(courses[i]->getName() == courseName) {
            // Usuń kurs z wektora kursów
            courses.erase(courses.begin() + i);
        }
    }
}

// Metoda usuwająca kurs z systemu
void System::deleteUser(std::string login) {
    // Przeszukaj wektor użytkowników
    for(int i = 0; i < users.size(); i++) {
        // Jeżeli login użytkownika jest równy loginowi podanemu jako argument
        if(users[i]->getLogin() == login) {
            // Usuń użytkownika z wektora użytkowników
            users.erase(users.begin() + i);
        }
    }
}

// Metoda wczytująca użytkowników z pliku CSV
void System::loadUsersFromCSV(const std::string& fileName) {
    // Utwórz zmienne do odczytu danych z pliku
    std::ifstream file(fileName);   // Utwórz strumień plikowy
    std::string line;                  // Utwórz zmienną przechowującą linię z pliku

    // Jeżeli nie udało się otworzyć pliku
    if(!file.is_open()) {
        // Wyświetl informacje o błędzie
        std::cout << "Blad podczas otwierania pliku: " << fileName << std::endl;
        // Zakończ działanie metody
        return;
    }

    // Dla każdej linii w pliku
    while(std::getline(file, line)) {
        // Utwórz zmienne przechowujące dane użytkownika
        std::string imie, nazwisko, login, haslo, email;
        // Pobierz linię z pliku
        std::stringstream ss(line);
        // Jeżeli udało się pobrać dane użytkownika z podanym formatowaniem
        if((std::getline(ss, imie, ' ') &&
            std::getline(ss, nazwisko, ',') &&
            std::getline(ss, login, ',')) &&
            std::getline(ss, haslo, ',') &&
            std::getline(ss, email, ',')) {
                // Dodaj użytkownika do wektora użytkowników
                users.push_back(new User(imie, nazwisko, login, haslo, email));
        }
    }
    // Zamknij plik
    file.close();
}

// Metoda zapisująca użytkowników do pliku CSV
void System::saveUsersToCSV(const std::string& fileName) {
    // Otwórz plik do zapisu
    std::ofstream file(fileName);

    // Jeżeli nie udało się otworzyć pliku
    if (!file.is_open()) {
        // Wyświetl informacje o błędzie
        std::cout << "Blad podczas otwierania pliku: " << fileName << std::endl;
        // Zakończ działanie metody
        return;
    }

    // Dla każdego użytkownika w wektorze użytkowników
    for(const auto& user : users) {
        // Zapisz dane użytkownika do pliku w formacie CSV
        file << user->getFirstName() << " " << user->getLastName() << "," << user->getLogin() << "," << user->getPassword() << "," << user->getEmail() << ",\n";
    }

    // Zamknij plik
    file.close();
}

// Metoda wczytująca kursy z pliku CSV
void System::loadCoursesFromCSV(const std::string& fileName) {
    // Utwórz zmienne do odczytu danych z pliku
    std::ifstream file(fileName);   // Utwórz strumień plikowy
    std::string line;                  // Utwórz zmienną przechowującą linię z pliku

    // Jeżeli nie udało się otworzyć pliku
    if(!file.is_open()) {
        // Wyświetl informacje o błędzie
        std::cout << "Blad podczas otwierania pliku: " << fileName << std::endl;
        // Zakończ działanie metody
        return;
    }

    // Dla każdej linii w pliku
    while(std::getline(file, line)) {
        // Utwórz zmienne przechowujące dane kursu
        std::string courseName, lecturerFirstName, lecturerLastName, isVideoConferenceCreated;
        // Pobierz linię z pliku
        std::stringstream ss(line);
        // Jeżeli udało się pobrać dane kursu z podanym formatowaniem
        if(std::getline(ss, courseName, ',') && std::getline(ss, lecturerFirstName, ' ') &&
            std::getline(ss, lecturerLastName, ',') && std::getline(ss, isVideoConferenceCreated, ',')) {
                // Dodaj kurs do wektora kursów
                courses.push_back(new Course(courseName, new Lecturer(lecturerFirstName, lecturerLastName), isVideoConferenceCreated));
        }
    }
    // Zamknij plik
    file.close();
}

// Metoda zapisująca kursy do pliku CSV
void System::saveCoursesToCSV(const std::string& fileName) {
    // Otwórz plik do zapisu
    std::ofstream file(fileName);

    // Jeżeli nie udało się otworzyć pliku
    if(!file.is_open()) {
        // Wyświetl informacje o błędzie
        std::cout << "Blad podczas otwierania pliku: " << fileName << std::endl;
        // Zakończ działanie metody
        return;
    }

    // Dla każdego kursu w wektorze kursów
    for(const auto& course : courses) {
        // Zapisz dane kursu do pliku w formacie CSV
        file << course->getName() << "," << course->getLecturer()->getFirstName() << " " << course->getLecturer()->getLastName() << "," << 0 << ",\n";
    }

    // Zamknij plik
    file.close();
}

// Metoda uruchamiająca system
void System::boot() {
    // Wczytaj dane z plików CSV
    loadUsersFromCSV(usersFilePath);  // Wczytaj użytkowników
    loadCoursesFromCSV(coursesFilePath);  // Wczytaj kursy

    // Wyświetl logo systemu
    std::cout << "============================================================================================\n";
    std::cout << "============================================================================================\n";
    std::cout << "============================================================================================\n";
    std::cout << logo << "\n";
    std::cout << "============================================================================================\n";
    std::cout << "============================================================================================\n";
    std::cout << "============================================================================================\n";
}

// Metoda uruchamiająca system w wersji studenckiej
void System::studentSystem() {
    // Utwórz zmienną przechowującą dane użytkownika
    std::string userInput;

    // Utwórz nowego studenta
    Student * student = new Student();

    // Wywołaj metodę logowania
    login(student);

    // Pętla do wyboru opcji systemu studenta
    while(true) {
        // Wyświetl opcje
        std::cout << "Wybierz opcje:" << "\n";
        std::cout << "1. Kursy" << "\n";
        std::cout << "2. Wyswietl swoj profil" << "\n";
        std::cout << "3. Wyloguj sie" << "\n";

        // Pobierz wybór użytkownika
        std::cin >> userInput;

        // Wykonaj akcję w zależności od wyboru użytkownika
        // Jeżeli użytkownik wybrał opcję 1
        if(userInput == "1") {
            // Wywołaj metodę menu kursów studenta
            studentCourseMenu(student);
        // Jeżeli użytkownik wybrał opcję 2
        } else if(userInput == "2") {
        // Wyświetl profil użytkownika
            student->printUser();
        // Jeżeli użytkownik wybrał opcję 3
        } else if(userInput == "3") {
            // Zakończ działanie programu
            exit(0);
        // W przeciwnym wypadku
        } else {
            // Wyświetl komunikat o niepoprawnym wyborze
            std::cout << "Niepoprawna opcja!\n";
        }
    }
}

// Metoda uruchamiająca system w werjsi wykładowcy
void System::lecturerSystem() {
    // Utwórz zmienną przechowującą dane użytkownika
    std::string userInput;

    // Utwórz nowego wykładowcę
    Lecturer * lecturer = new Lecturer();

    // Wywołaj metodę logowania
    login(lecturer);

    // Pętla do wyboru opcji systemu studenta
    while(true) {
        // Wyświetl opcje
        std::cout << "Wybierz opcje:" << "\n";
        std::cout << "1. Kursy" << "\n";
        std::cout << "2. Wyswietl swoj profil" << "\n";
        std::cout << "3. Wyloguj sie" << "\n";

        // Pobierz wybór użytkownika
        std::cin >> userInput;

        // Wykonaj akcję w zależności od wyboru użytkownika
        // Jeżeli użytkownik wybrał opcję 1
        if(userInput == "1") {
            // Wywołaj metodę menu kursów studenta
            lecturerCourseMenu(lecturer);
            // Jeżeli użytkownik wybrał opcję 2
        } else if(userInput == "2") {
            // Wyświetl profil użytkownika
            lecturer->printUser();
            // Jeżeli użytkownik wybrał opcję 3
        } else if(userInput == "3") {
            // Zakończ działanie programu
            exit(0);
            // W przeciwnym wypadku
        } else {
            // Wyświetl komunikat o niepoprawnym wyborze
            std::cout << "Niepoprawna opcja!" << "\n";
        }
    }
}

// Metoda otwierająca menu kursów dla studenta
void System::studentCourseMenu(Student * student) {
    // Utwórz zmienną przechowującą dane użytkownika
    std::string userInput;

    // Pętla do wyboru opcji systemu studenta
    while(true) {
        // Wyświetl nagłówek menu kursów
        displayHeader("Menu Kursow");

        // Wyświetl opcje
        std:: cout << "Wybierz opcje:" << "\n";
        std:: cout << "1. Wybierz ze swoich kursow" << "\n";
        std:: cout << "2. Zapisz sie do kursu" << "\n";
        std:: cout << "3. Wypisz sie z kursu" << "\n";
        std:: cout << "4. Wyswietl swoje kursy" << "\n";
        std:: cout << "5. Wyswietl wszystkie kursy" << "\n";
        std:: cout << "6. Wroc" << "\n";

        // Pobierz wybór użytkownika
        std::cin >> userInput;

        // Wykonaj akcję w zależności od wyboru użytkownika
        // Jeżeli użytkownik wybrał opcję 1
        if(userInput == "1") {
            // Wyświetl kursy studenta
            student->printCourses();
            // Wyświetl opcję powrotu
            std::cout << student->getCoursesSize() + 1 << ". Wroc" << "\n";

            std::cout << "Wybierz kurs: ";  // Wyświetl komunikat o wyborze kursu
            std::cin >> userInput;  // Pobierz wybór użytkownika

            // Jeżeli wybrany kurs istnieje
            if(std::stoi(userInput) - 1 < student->getCoursesSize()) {
                // Wywołaj menu kursu studenta o podanym indeksie
                student->getCourseAtIndex(std::stoi(userInput) - 1)->openStudentCourseMenu(student);
            // W przeciwnym wypadku
            } else if(std::stoi(userInput) - 1  == student->getCoursesSize()) {
                // Nic nie wyświetlaj, ponieważ użytkownik wraca do menu kursów
            // W przeciwnym wypadku
            } else {
                // Wyświetl komunikat o niepoprawnym wyborze
                std::cout << "Podany kurs nie istnieje!" << "\n";
            }
        // Jeżeli użytkownik wybrał opcję 2
        } else if(userInput == "2") {
            // TODO W TYM MIEJSCU ZROBIC ZE UZYTKOWNIKOWI WYSWIETLAJA SIE TYLKO KURSY KTORYCH NIE MA DODANYCH

            // Wyświetl wszystkie kursy
            printCourses();
            // Wyświetl opcję powrotu
            std::cout << getCoursesSize() + 1 << ". Wroc" << "\n";

            // Wyświetl komunikat o wyborze kursu
            std::cout << "Wybierz kurs: ";
            // Pobierz wybór użytkownika
            std::cin >> userInput;

            // Jeżeli wybrany kurs istnieje
            if(std::stoi(userInput) - 1 < getCoursesSize()) {
                // Dodaj kurs do kursów studenta
                student->addCourse(courses[std::stoi(userInput) - 1]);
                // Dodaj studenta do uczestników kursu
                courses[std::stoi(userInput) - 1]->addUser(student);
            // Jeżeli użytkownik wybrał opcję powrotu
            } else if(std::stoi(userInput) - 1 == getCoursesSize()) {
                // Nic nie wyświetlaj, ponieważ użytkownik wraca do menu kursów
            // W przeciwnym wypadku
            } else {
                // Wyświetl komunikat o niepoprawnym wyborze
                std::cout << "Podany kurs nie istnieje!" << "\n";
            }
        // Jeżeli użytkownik wybrał opcję 3
        } else if(userInput == "3") {
            // Wyświetl kursy studenta
            student->printCourses();
            // Wyświetl opcję powrotu
            std::cout << student->getCoursesSize() + 1 << ". Wroc" << "\n";

            // Wyświetl komunikat o wyborze kursu
            std::cout << "Wybierz kurs: ";
            // Pobierz wybór użytkownika
            std::cin >> userInput;

            // Jeżeli wybrany kurs istnieje
            if(std::stoi(userInput) - 1 < student->getCoursesSize()) {
                // Usuń kurs z kursów studenta
                student->deleteCourse(courses[std::stoi(userInput) - 1]->getName());
                // Usuń studenta z uczestników kursu
                courses[std::stoi(userInput) - 1]->deleteUser(student->getLogin());
            // Jeżeli użytkownik wybrał opcję powrotu
            } else if(std::stoi(userInput) - 1 == student->getCoursesSize()) {
                // Nic nie wyświetlaj, ponieważ użytkownik wraca do menu kursów
            } else {
                // Wyświetl komunikat o niepoprawnym wyborze
                std::cout << "Podany kurs nie istnieje!" << "\n";
            }
        // Jeżeli użytkownik wybrał opcję 4
        } else if(userInput == "4") {
            // Wyświetl kursy studenta
            student->printCourses();
        // Jeżeli użytkownik wybrał opcję 5
        } else if(userInput == "5") {
            // Wyświetl wszystkie kursy
            printCourses();
        // Jeżeli użytkownik wybrał opcję 6
        } else if(userInput == "6") {
            // Wyświetl komunikat o opuszczeniu menu kursów
            std::cout << "Opusciles menu kursow!" << "\n";
            // Wyjdź z pętli
            break;
        // W przeciwnym wypadku
        } else {
            // Wyświetl komunikat o niepoprawnym wyborze
            std::cout << "Niepoprawna opcja!" << "\n";
        }
    }
}

// Metoda otwierająca menu kursów dla wykładowcy
void System::lecturerCourseMenu(Lecturer * lecturer) {
    // Utwórz zmienną przechowującą dane użytkownika
    std::string userInput;

    // Pętla do wyboru opcji systemu wykładowcy
    while(true) {
        // Wyświetl nagłówek menu kursów
        displayHeader("Menu Kursow");

        // Wyświetl opcje
        std:: cout << "Wybierz opcje:" << "\n";
        std:: cout << "1. Wybierz ze swoich kursow" << "\n";
        std:: cout << "2. Utworz kurs" << "\n";
        std:: cout << "3. Zamknij kurs" << "\n";
        std:: cout << "4. Wyswietl swoje kursy" << "\n";
        std:: cout << "5. Wyswietl wszystkie kursy" << "\n";
        std:: cout << "6. Wroc" << "\n";

        // Pobierz wybór użytkownika
        std::cin >> userInput;

        // Wykonaj akcję w zależności od wyboru użytkownika
        // Jeżeli użytkownik wybrał opcję 1
        if(userInput == "1") {
            // Wyświetl kursy wykładowcy
            lecturer->printCourses();
            // Wyświetl opcję powrotu
            std::cout << lecturer->getCoursesSize() + 1 << ". Wroc" << "\n";

            std::cout << "Wybierz kurs: ";  // Wyświetl komunikat o wyborze kursu
            std::cin >> userInput;  // Pobierz wybór użytkownika

            // Jeżeli wybrany kurs istnieje
            if(std::stoi(userInput) - 1 < lecturer->getCoursesSize()) {
                // Wywołaj menu kursu wykładowcy o podanym indeksie
                lecturer->getCourseAtIndex(std::stoi(userInput) - 1)->openLecturerCourseMenu(lecturer);
            // Jeżeli użytkownik wybrał opcję powrotu
            } else if(std::stoi(userInput) - 1 == lecturer->getCoursesSize()) {
                // Nic nie wyświetlaj, ponieważ użytkownik wraca do menu kursów
            // W przeciwnym wypadku
            } else {
                // Wyświetl komunikat o niepoprawnym wyborze
                std::cout << "Podany kurs nie istnieje!" << "\n";
            }
        // Jeżeli użytkownik wybrał opcję 2
        } else if(userInput == "2") {
            // Wyświetl komunikat o podaniu nazwy kursu
            std::cout << "Podaj nazwe kursu: ";
            // Pobierz nazwę kursu
            std::cin >> userInput;

            // Utwórz nowy kurs o podanej nazwie i wykładowcy
            Course * newCourse = new Course(userInput, lecturer);
            // Dodaj kurs do listy kursów systemu
            addCourse(newCourse);
            // Dodaj kurs do listy kursów wykładowcy
            lecturer->addCourse(newCourse);
            // Zapisz kurs do pliku kursów w formacie CSV
            saveCoursesToCSV(coursesFilePath);

            // Wyświetl komunikat o utworzeniu kursu
            std::cout << "Kurs zostal utworzony!" << "\n";
        // Jeżeli użytkownik wybrał opcję 3
        } else if(userInput == "3") {
            // Wyświetl kursy wykładowcy
            lecturer->printCourses();
            // Wyświetl opcję powrotu
            std::cout << lecturer->getCoursesSize() + 1 << ". Wroc" << "\n";

            // Wyświetl komunikat o wyborze kursu
            std::cout << "Wybierz kurs: ";
            // Pobierz wybór użytkownika
            std::cin >> userInput;

            // Jeżeli wybrany kurs istnieje
            if(std::stoi(userInput) - 1 < lecturer->getCoursesSize()) {
                for(int i = 0; i < lecturer->getCoursesSize(); i++) {
                    if(lecturer->getCourseAtIndex(i)->getName() == lecturer->getCourseAtIndex(std::stoi(userInput) - 1)->getName()) {
                        // Usuń kurs z listy kursów wykładowcy
                        lecturer->deleteCourse(lecturer->getCourseAtIndex(i)->getName());
                        // Usuń kurs z listy kursów systemu
                        deleteCourse(lecturer->getCourseAtIndex(i)->getName());
                        // Wyświetl komunikat o usunięciu kursu
                        std::cout << "Kurs zostal zamkniety!" << "\n";
                    }
                }  // Jeżeli użytkownik wybrał opcję powrotu
            } else if(std::stoi(userInput) - 1 == lecturer->getCoursesSize()) {
                // Nic nie wyświetlaj, ponieważ użytkownik wraca do menu kursów
            } else {
                // Wyświetl komunikat o niepoprawnym wyborze
                std::cout << "Podany kurs nie istnieje!" << "\n";
            }
        // Jeżeli użytkownik wybrał opcję 4
        } else if(userInput == "4") {
            // Wyświetl kursy wykładowcy
            lecturer->printCourses();
        // Jeżeli użytkownik wybrał opcję 5
        } else if(userInput == "5") {
            // Wyświetl wszystkie kursy
            printCourses();
        // Jeżeli użytkownik wybrał opcję 6
        } else if(userInput == "6") {
            // Wyświetl komunikat o opuszczeniu menu kursów
            std::cout << "Opusciles menu kursow!" << "\n";
            // Wyjdź z pętli
            break;
        // W przeciwnym wypadku
        } else {
            // Wyświetl komunikat o niepoprawnym wyborze
            std::cout << "Niepoprawna opcja!" << "\n";
        }
    }
}
