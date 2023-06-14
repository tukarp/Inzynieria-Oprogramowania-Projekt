//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : System Obsługi Studiów
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

// Ścieżka do pliku csv z kursami
const std::string coursesFilePath = "courses.csv";

// Ścieżka do pliku csv z użytkownikami
const std::string usersFilePath = "users.csv";

// Konstruktor klasy System
System::System(std::string name) {
    this->name = name;
}

// Akcesor nazwy systemu
std::string System::getName() {
    return name;
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
    std::cout << "[========================================================================================]\n";
    std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Logowanie~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    std::cout << "[========================================================================================]\n";

    // Zaloguj użytkownika
    std::cout << "| Login: ";         // Wyświetl informacje o podaniu loginu
    std::cin >> loginUzytkownika;   // Pobierz login od użytkownika

    std::cout << "| Haslo: ";         // Wyświetl informacje o podaniu hasła
    std::cin >> hasloUzytkownika;   // Pobierz hasło od użytkownika

    // Jeżeli autoryzacja użytkownika przebiegła pomyślnie
    if(authentication(user, loginUzytkownika, hasloUzytkownika)) {
        // Wyświetl nagłówek o zalogowaniu
        std::cout << "[========================================================================================]\n";
        std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Zalogowano~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        std::cout << "[========================================================================================]\n";
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
    std::cout << "[========================================================================================]\n";
    std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Rejestracja~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    std::cout << "[========================================================================================]\n";

    // Zarejestruj użytkownika
    std::cout << "| Login: ";         // Wyświetl informacje o podaniu loginu
    std::cin >> userInput;          // Pobierz login od użytkownika
    user->setLogin(userInput);      // Ustaw login użytkownika

    std::cout << "| Haslo: ";         // Wyświetl informacje o podaniu hasła
    std::cin >> userInput;          // Pobierz hasło od użytkownika
    user->setPassword(userInput);   // Ustaw hasło użytkownika

    std::cout << "| Imie: ";          // Wyświetl informacje o podaniu imienia
    std::cin >> userInput;          // Pobierz imię od użytkownika
    user->setFirstName(userInput);  // Ustaw imię użytkownika

    std::cout << "| Nazwisko: ";      // Wyświetl informacje o podaniu nazwiska
    std::cin >> userInput;          // Pobierz nazwisko od użytkownika
    user->setLastName(userInput);   // Ustaw nazwisko użytkownika

    std::cout << "| Email: ";         // Wyświetl informacje o podaniu emaila
    std::cin >> userInput;          // Pobierz email od użytkownika
    user->setEmail(userInput);      // Ustaw email użytkownika

    // Dodaj użytkownika do wektora użytkowników
    users.push_back(user);
    // Zapisz użytkownika do pliku użytkowników w formacie CSV
    saveUsersToCSV(usersFilePath);
}

// Metoda usuwająca użytkownika z systemu
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
    std::cout << "[========================================================================================]\n";
    std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Kursy~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    std::cout << "[========================================================================================]\n";

    // Dla każdego kursu w wektorze kursów
    for(int i = 0; i < courses.size(); i++) {
        // Wyświetl numer kursu i nazwę kursu
        std::cout << "| " << i + 1 << ". " << courses[i]->getName() << "\n";
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
    std::vector<std::string> participants;  // Utwórz wektor uczestników kursu
    std::ifstream file(fileName);  // Utwórz strumień plikowy
    Course * newCourse;  // Utwórz wskaźnik na nowy kurs
    std::string line;  // Utwórz zmienną przechowującą linię z pliku

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
            // Utwórz nowy kurs
            newCourse = new Course(courseName, new Lecturer(lecturerFirstName, lecturerLastName), isVideoConferenceCreated);
            // Dodaj kurs do wektora kursów
            courses.push_back(newCourse);

            // Odczytaj uczestników kursu
            std::string participant;
            while(std::getline(ss, participant, ',')) {
                // Usuń początkową i końcową spację z imienia i nazwiska uczestnika
                participant = participant.substr(0, participant.length());

                // Podziel imię i nazwisko uczestnika
                std::istringstream participantISS(participant);
                std::string participantFirstName, participantLastName;
                // Jeżeli udało się pobrać imię i nazwisko uczestnika
                if(std::getline(participantISS, participantFirstName, ' ') &&
                        std::getline(participantISS, participantLastName, ',')) {
                    // Dodaj uczestnika do wektora uczestników kursu
                    newCourse->addStudent(new Student(participantFirstName, participantLastName));
                }
            }
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
    for(int i = 0; i < courses.size(); i++) {
        // Zapisz dane kursu do pliku w formacie CSV
        file << courses[i]->getName() << "," << courses[i]->getLecturer()->getFirstName() << " " << courses[i]->getLecturer()->getLastName() << "," << 0 << ",";
        for(int j = 0; j < courses[i]->getStudentsSize(); j++) {
            // Zapisz dane uczestników kursu do pliku w formacie CSV
            file << courses[i]->getStudentAtIndex(j)->getFirstName() << " " << courses[i]->getStudentAtIndex(j)->getLastName() << ",";
        }
        // Dodaj znak nowej linii do pliku CSV
        file << "\n";
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
        // Wyświetl stronę główną systemu studenta
        std::cout << "[========================================================================================]\n";
        std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Strona glowna~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        std::cout << "|========================================================================================|\n";
        std::cout << "| 1. Kursy                                                                               |\n";
        std::cout << "| 2. Wyswietl swoj profil                                                                |\n";
        std::cout << "| 3. Wyloguj sie                                                                         |\n";
        std::cout << "[========================================================================================]\n";

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

    // Pętla do wyboru opcji systemu wykładowcy
    while(true) {
        // Wyświetl stronę główną systemu wykładowcy
        std::cout << "[========================================================================================]\n";
        std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Strona glowna~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        std::cout << "|========================================================================================|\n";
        std::cout << "| 1. Kursy                                                                               |\n";
        std::cout << "| 2. Wyswietl swoj profil                                                                |\n";
        std::cout << "| 3. Wyloguj sie                                                                         |\n";
        std::cout << "[========================================================================================]\n";

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
        // Wyświetl menu kursów studenta
        std::cout << "[========================================================================================]\n";
        std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Menu Kursow~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        std::cout << "|========================================================================================|\n";
        std::cout << "| 1. Wybierz ze swoich kursow                                                            |\n";
        std::cout << "| 2. Zapisz sie do kursu                                                                 |\n";
        std::cout << "| 3. Wypisz sie z kursu                                                                  |\n";
        std::cout << "| 4. Wyswietl swoje kursy                                                                |\n";
        std::cout << "| 5. Wyswietl wszystkie kursy                                                            |\n";
        std::cout << "| 6. Wroc                                                                                |\n";
        std::cout << "[========================================================================================]\n";

        // Pobierz wybór użytkownika
        std::cin >> userInput;

        // Wykonaj akcję w zależności od wyboru użytkownika
        // Jeżeli użytkownik wybrał opcję 1
        if(userInput == "1") {
            // Wyświetl kursy studenta
            student->printCourses();
            // Wyświetl opcję powrotu
            std::cout << "| " << student->getCoursesSize() + 1 << ". Wroc" << "\n";
            std::cout << "[========================================================================================]\n";

            std::cout << "Wybierz kurs: ";  // Wyświetl komunikat o wyborze kursu
            std::cin >> userInput;  // Pobierz wybór użytkownika

            // Jeżeli wybrany kurs istnieje
            if(std::stoi(userInput) - 1 < student->getCoursesSize()) {
                // Wywołaj menu kursu studenta o podanym indeksie
                student->getCourseAtIndex(std::stoi(userInput) - 1)->openStudentCourseMenu(student);
            // W przeciwnym wypadku
            } else if(std::stoi(userInput) - 1  == student->getCoursesSize()) {
                // Wyświetl komunikat o opuszczeniu menu kursów
                std::cout << "Wyszedles z menu kursow!" << "\n";
            // W przeciwnym wypadku
            } else {
                // Wyświetl komunikat o niepoprawnym wyborze
                std::cout << "Podany kurs nie istnieje!" << "\n";
            }
        // Jeżeli użytkownik wybrał opcję 2
        } else if(userInput == "2") {
            // Wyświetl wszystkie kursy
            printCourses();
            // Wyświetl opcję powrotu
            std::cout << "| " << getCoursesSize() + 1 << ". Wroc" << "\n";
            std::cout << "[========================================================================================]\n";

            // Wyświetl komunikat o wyborze kursu
            std::cout << "Wybierz kurs: ";
            // Pobierz wybór użytkownika
            std::cin >> userInput;

            // Jeżeli wybrany kurs istnieje
            if(std::stoi(userInput) - 1 < getCoursesSize()) {
                // Przejdź przez wszystkie kursy studenta
                for(int i = 0; i < student->getCoursesSize(); i++) {
                    // Jeżeli student jest już zapisany na dany kurs
                    if(student->getCourseAtIndex(i)->getName() == courses[std::stoi(userInput) - 1]->getName()) {
                        // Wyświetl komunikat o tym, że student jest już zapisany na ten kurs
                        std::cout << "Juz jestes zapisany na ten kurs!" << "\n";
                        // Zakończ pętlę
                        return;
                    }
                }
                // Dodaj kurs do kursów studenta
                student->addCourse(courses[std::stoi(userInput) - 1]);
                // Dodaj studenta do uczestników kursu
                courses[std::stoi(userInput) - 1]->addStudent(student);
                // Zapisz studenta do pliku kursów w formacie CSV
                saveCoursesToCSV(coursesFilePath);
            // Jeżeli użytkownik wybrał opcję powrotu
            } else if(std::stoi(userInput) - 1 == getCoursesSize()) {
                // Wyświetl komunikat o opuszczeniu menu kursów
                std::cout << "Wyszedles z menu kursow!" << "\n";
            // W przeciwnym wypadku
            } else {
                // Wyświetl komunikat o niepoprawnym wyborze
                std::cout << "Podany kurs nie istnieje!" << "\n";
            }
        // Jeżeli użytkownik wybrał opcję 3
        } else if(userInput == "3") {
            // Utwórz zmienną przechowującą nazwe kursu do usunięcia
            std::string courseToDeleteName = "";

            // Wyświetl kursy studenta
            student->printCourses();
            // Wyświetl opcję powrotu
            std::cout << "| " << student->getCoursesSize() + 1 << ". Wroc" << "\n";
            std::cout << "[========================================================================================]\n";

            // Wyświetl komunikat o wyborze kursu
            std::cout << "Wybierz kurs: ";
            // Pobierz wybór użytkownika
            std::cin >> userInput;

            // Jeżeli wybrany kurs istnieje
            if(std::stoi(userInput) - 1 < student->getCoursesSize()) {
                // Przejdz przez wszystkie kursy wykładowcy
                for(int i = 0; i < student->getCoursesSize(); i++) {
                    // Jeżeli nazwa kursu o podanym indeksie jest taka sama jak nazwa kursu o podanym indeksie
                    if(student->getCourseAtIndex(i)->getName() == student->getCourseAtIndex(std::stoi(userInput) - 1)->getName()) {
                        // Ustaw zmienną przechowującą nazwe kursu do usunięcia na nazwę kursu o podanym indeksie
                        std::string courseToDeleteName = student->getCourseAtIndex(i)->getName();
                        // Przejdz przez wszystkie kursy systemu
                        for(int j = 0; j < courses.size(); j++) {
                            // Jeżeli nazwa kursu o podanym indeksie jest taka sama jak nazwa kursu do usunięcia
                            if(courses[j]->getName() == courseToDeleteName) {
                                // Usuń studenta z listy uczestników kursu
                                courses[j]->removeStudent(student->getLogin());
                                // Usuń kurs z listy kursów studenta
                                student->removeCourse(courseToDeleteName);
                                // Wyświetl komunikat wyjścia z kursu
                                std::cout << "Wyszedles z kursu " << courses[j]->getName() << "!" << "\n";
                            }
                        }
                    }
                }
            // Jeżeli użytkownik wybrał opcję powrotu
            } else if(std::stoi(userInput) - 1 == student->getCoursesSize()) {
                // Wyświetl komunikat o opuszczeniu menu kursów
                std::cout << "Wyszedles z menu kursow!" << "\n";
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
            std::cout << "Wyszedles z menu kursow!" << "\n";
            // Zakończ pętlę
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
        // Wyświetl menu kursów wykładowcy
        std::cout << "[========================================================================================]\n";
        std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Menu Kursow~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        std::cout << "|========================================================================================|\n";
        std::cout << "| 1. Wybierz ze swoich kursow                                                            |\n";
        std::cout << "| 2. Utworz kurs                                                                         |\n";
        std::cout << "| 3. Zamknij kurs                                                                        |\n";
        std::cout << "| 4. Wyswietl swoje kursy                                                                |\n";
        std::cout << "| 5. Wyswietl wszystkie kursy                                                            |\n";
        std::cout << "| 6. Wroc                                                                                |\n";
        std::cout << "[========================================================================================]\n";

        // Pobierz wybór użytkownika
        std::cin >> userInput;

        // Wykonaj akcję w zależności od wyboru użytkownika
        // Jeżeli użytkownik wybrał opcję 1
        if(userInput == "1") {
            // Wyświetl kursy wykładowcy
            lecturer->printCourses();
            // Wyświetl opcję powrotu
            std::cout << "| " << lecturer->getCoursesSize() + 1 << ". Wroc" << "\n";
            std::cout << "[========================================================================================]\n";

            std::cout << "Wybierz kurs: ";  // Wyświetl komunikat o wyborze kursu
            std::cin >> userInput;  // Pobierz wybór użytkownika

            // Jeżeli wybrany kurs istnieje
            if(std::stoi(userInput) - 1 < lecturer->getCoursesSize()) {
                // Wywołaj menu kursu wykładowcy o podanym indeksie
                lecturer->getCourseAtIndex(std::stoi(userInput) - 1)->openLecturerCourseMenu(lecturer);
            // Jeżeli użytkownik wybrał opcję powrotu
            } else if(std::stoi(userInput) - 1 == lecturer->getCoursesSize()) {
                // Wyświetl komunikat o opuszczeniu menu kursów
                std::cout << "Wyszedles z menu kursow!" << "\n";
            // W przeciwnym wypadku
            } else {
                // Wyświetl komunikat o niepoprawnym wyborze
                std::cout << "Podany kurs nie istnieje!" << "\n";
            }
        // Jeżeli użytkownik wybrał opcję 2
        } else if(userInput == "2") {
            // Utwórz zmienną przechowującą linie tekstu
            std::string inputLine;
            // Zresetuj zmienną przechowującą dane użytkownika
            userInput = "";

            // Wyświetl komunikat o podaniu nazwy kursu
            std::cout << "Podaj nazwe kursu: ";
            // Pobierz nazwę kursu
            while(std::getline(std::cin, inputLine)) {
                // Dodaj linię tekstu do zmiennej przechowującej dane użytkownika
                userInput += inputLine;
                if(inputLine.find(' ') != std::string::npos) {
                    // Jeżeli w linii tekstu znajduje się spacja, zakończ pobieranie
                    break;
                }
            }

            // Przejdź przez wszystkie kursy
            for(int i = 0; i < courses.size(); i++) {
                // Jeżeli nazwa kursu jest taka sama jak nazwa kursu do utworzenia
                if(courses[i]->getName() == userInput) {
                    // Wyświetl komunikat o istnieniu kursu
                    std::cout << "Kurs o podanej nazwie juz istnieje!" << "\n";
                    // Wyjdź z pętli
                    return;
                }
            }

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
            // Utwórz zmienną przechowującą nazwe kursu do usunięcia
            std::string courseToDeleteName = "";

            // Wyświetl kursy wykładowcy
            lecturer->printCourses();
            // Wyświetl opcję powrotu
            std::cout << "| " << lecturer->getCoursesSize() + 1 << ". Wroc" << "\n";
            std::cout << "[========================================================================================]\n";

            // Wyświetl komunikat o wyborze kursu
            std::cout << "Wybierz kurs: ";
            // Pobierz wybór użytkownika
            std::cin >> userInput;

            // Jeżeli wybrany kurs istnieje
            if(std::stoi(userInput) - 1 < lecturer->getCoursesSize()) {
                // Przejdz przez wszystkie kursy wykładowcy
                for(int i = 0; i < lecturer->getCoursesSize(); i++) {
                    // Jeżeli nazwa kursu o podanym indeksie jest taka sama jak nazwa kursu o podanym indeksie
                    if(lecturer->getCourseAtIndex(i)->getName() == lecturer->getCourseAtIndex(std::stoi(userInput) - 1)->getName()) {
                        // Ustaw zmienną przechowującą nazwe kursu do usunięcia na nazwę kursu o podanym indeksie
                        std::string courseToDeleteName = lecturer->getCourseAtIndex(i)->getName();
                        // Przejdz przez wszystkie kursy systemu
                        for(int j = 0; j < courses.size(); j++) {
                            // Jeżeli nazwa kursu o podanym indeksie jest taka sama jak nazwa kursu do usunięcia
                            if(courses[j]->getName() == courseToDeleteName) {
                                // Usuń kurs z listy kursów systemu
                                courses.erase(courses.begin() + j);
                                // Zapisz kursy do pliku kursów w formacie CSV
                                saveCoursesToCSV(coursesFilePath);
                                // Usuń kurs z listy kursów wykładowcy
                                lecturer->removeCourse(courseToDeleteName);
                                // Wyświetl komunikat o usunięciu kursu
                                std::cout << "Kurs " << courseToDeleteName << " zostal zamkniety!" << "\n";
                            }
                        }
                    }
                }
            // Jeżeli użytkownik wybrał opcję powrotu
            } else if(std::stoi(userInput) - 1 == lecturer->getCoursesSize()) {
                // Wyświetl komunikat o opuszczeniu menu kursów
                std::cout << "Wyszedles z menu kursow!" << "\n";
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
            std::cout << "Wyszedles z menu kursow!" << "\n";
            // Wyjdź z pętli
            break;
        // W przeciwnym wypadku
        } else {
            // Wyświetl komunikat o niepoprawnym wyborze
            std::cout << "Niepoprawna opcja!" << "\n";
        }
    }
}
