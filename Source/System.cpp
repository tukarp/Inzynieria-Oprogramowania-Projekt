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

#include <iostream>
#include <fstream>
#include <sstream>

#include "System.h"

const std::string logo = R"(
  ___         _                ___  _       _           _   ___ _           _ _
 / __|_  _ __| |_ ___ _ __    / _ \| |__ __| |_  _ __ _(_) / __| |_ _  _ __| (_)_____ __ __
 \__ \ || (_-<  _/ -_) '  \  | (_) | '_ (_-< | || / _` | | \__ \  _| || / _` | / _ \ V  V /
 |___/\_, /__/\__\___|_|_|_|  \___/|_.__/__/_|\_,_\__, |_| |___/\__|\_,_\__,_|_\___/\_/\_/
      |__/                                        |___/
)";

const std::string coursesFilePath = "courses.csv";
const std::string usersFilePath = "users.csv";

System::System(std::string name) {
    this->name = name;
}

std::string System::getName() {
    return name;
}

bool System::authentication(User * user, std::string login, std::string password) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getLogin() == login && users[i]->getPassword() == password) {
            user->setLogin(users[i]->getLogin());
            user->setPassword(users[i]->getPassword());
            user->setFirstName(users[i]->getFirstName());
            user->setLastName(users[i]->getLastName());
            user->setEmail(users[i]->getEmail());
            return true;
        }
    }
    return false;
}

void System::login(User * user) {
    std::string loginUzytkownika;
    std::string hasloUzytkownika;
    std::cout << "[========================================================================================]\n";
    std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Logowanie~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    std::cout << "[========================================================================================]\n";
    std::cout << "| Login: ";
    std::cin >> loginUzytkownika;
    std::cout << "| Haslo: ";
    std::cin >> hasloUzytkownika;

    if (authentication(user, loginUzytkownika, hasloUzytkownika)) {
        std::cout << "[========================================================================================]\n";
        std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Zalogowano~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        std::cout << "[========================================================================================]\n";
        return;
    } else {
        std::cout << "Niepoprawny login lub haslo!" << "\n";
        registerUser(user);
    }
}

void System::registerUser(User * user) {
    std::string userInput;
    std::cout << "[========================================================================================]\n";
    std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Rejestracja~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    std::cout << "[========================================================================================]\n";

    std::cout << "| Login: ";
    std::cin >> userInput;
    user->setLogin(userInput);

    std::cout << "| Haslo: ";
    std::cin >> userInput;
    user->setPassword(userInput);

    std::cout << "| Imie: ";
    std::cin >> userInput;
    user->setFirstName(userInput);

    std::cout << "| Nazwisko: ";
    std::cin >> userInput;
    user->setLastName(userInput);

    std::cout << "| Email: ";
    std::cin >> userInput;
    user->setEmail(userInput);

    users.push_back(user);
    saveUsersToCSV(usersFilePath);
}

void System::deleteUser(std::string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getLogin() == login) {
            users.erase(users.begin() + i);
        }
    }
}

void System::addCourse(Course * course) {
    courses.push_back(course);
}

int System::getCoursesSize() {
    return courses.size();
}

void System::printCourses() {
    std::cout << "[========================================================================================]\n";
    std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Kursy~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    std::cout << "[========================================================================================]\n";
    for (int i = 0; i < courses.size(); i++) {
        std::cout << "| " << i + 1 << ". " << courses[i]->getName() << "\n";
    }
}

void System::deleteCourse(std::string courseName) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i]->getName() == courseName) {
            courses.erase(courses.begin() + i);
        }
    }
}

void System::loadUsersFromCSV(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Blad podczas otwierania pliku: " << fileName << std::endl;
        return;
    }

    while(std::getline(file, line)) {
        std::string imie, nazwisko, login, haslo, email;
        std::stringstream ss(line);
        if((std::getline(ss, imie, ' ') &&
            std::getline(ss, nazwisko, ',') &&
            std::getline(ss, login, ',')) &&
            std::getline(ss, haslo, ',') &&
            std::getline(ss, email, ',')) {
                users.push_back(new User(imie, nazwisko, login, haslo, email));
        }
    }

    file.close();
}

void System::saveUsersToCSV(const std::string& fileName) {
    std::ofstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Blad podczas otwierania pliku: " << fileName << std::endl;
        return;
    }

    for (const auto& user : users) {
        file << user->getFirstName() << " " << user->getLastName() << "," << user->getLogin() << "," << user->getPassword() << "," << user->getEmail() << ",\n";
    }

    file.close();
}

void System::loadCoursesFromCSV(const std::string& fileName) {
    std::vector<std::string> participants;
    std::ifstream file(fileName);
    Course * newCourse;
    std::string line;

    if (!file.is_open()) {
        std::cout << "Blad podczas otwierania pliku: " << fileName << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        std::string courseName, lecturerFirstName, lecturerLastName, isVideoConferenceCreated;
        std::stringstream ss(line);

        if (std::getline(ss, courseName, ',') && std::getline(ss, lecturerFirstName, ' ') &&
                std::getline(ss, lecturerLastName, ',') && std::getline(ss, isVideoConferenceCreated, ',')) {
            newCourse = new Course(courseName, new Lecturer(lecturerFirstName, lecturerLastName), isVideoConferenceCreated);
            courses.push_back(newCourse);

            std::string participant;
            while (std::getline(ss, participant, ',')) {
                participant = participant.substr(0, participant.length());
                std::istringstream participantISS(participant);
                std::string participantFirstName, participantLastName;

                if (std::getline(participantISS, participantFirstName, ' ') &&
                        std::getline(participantISS, participantLastName, ',')) {
                    newCourse->addStudent(new Student(participantFirstName, participantLastName));
                }
            }
        }
    }

    file.close();
}

void System::saveCoursesToCSV(const std::string& fileName) {
    std::ofstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Blad podczas otwierania pliku: " << fileName << std::endl;
        return;
    }

    for (int i = 0; i < courses.size(); i++) {
        file << courses[i]->getName() << "," << courses[i]->getLecturer()->getFirstName() << " " << courses[i]->getLecturer()->getLastName() << "," << 0 << ",";
        for (int j = 0; j < courses[i]->getStudentsSize(); j++) {
            file << courses[i]->getStudentAtIndex(j)->getFirstName() << " " << courses[i]->getStudentAtIndex(j)->getLastName() << ",";
        }
        file << "\n";
    }

    file.close();
}

void System::boot() {
    loadUsersFromCSV(usersFilePath);
    loadCoursesFromCSV(coursesFilePath);
    std::cout << "============================================================================================\n";
    std::cout << "============================================================================================\n";
    std::cout << "============================================================================================\n";
    std::cout << logo << "\n";
    std::cout << "============================================================================================\n";
    std::cout << "============================================================================================\n";
    std::cout << "============================================================================================\n";
}

void System::studentSystem() {
    std::string userInput;

    Student * student = new Student();
    login(student);

    while (true) {
        std::cout << "[========================================================================================]\n";
        std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Strona glowna~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        std::cout << "|========================================================================================|\n";
        std::cout << "| 1. Kursy                                                                               |\n";
        std::cout << "| 2. Wyswietl swoj profil                                                                |\n";
        std::cout << "| 3. Wyloguj sie                                                                         |\n";
        std::cout << "[========================================================================================]\n";

        std::cin >> userInput;
        switch (stoi(userInput)) {
            case 1:
                studentCourseMenu(student);
                break;
            case 2:
                student->printUser();
                break;
            case 3:
                exit(0);
            default:
                std::cout << "Niepoprawna opcja!" << "\n";
                break;
        }
    }
}

void System::lecturerSystem() {
    std::string userInput;

    Lecturer * lecturer = new Lecturer();
    login(lecturer);

    while (true) {
        std::cout << "[========================================================================================]\n";
        std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Strona glowna~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        std::cout << "|========================================================================================|\n";
        std::cout << "| 1. Kursy                                                                               |\n";
        std::cout << "| 2. Wyswietl swoj profil                                                                |\n";
        std::cout << "| 3. Wyloguj sie                                                                         |\n";
        std::cout << "[========================================================================================]\n";

        std::cin >> userInput;
        switch (stoi(userInput)) {
            case 1:
                lecturerCourseMenu(lecturer);
                break;
            case 2:
                lecturer->printUser();
                break;
            case 3:
                exit(0);
            default:
                std::cout << "Niepoprawna opcja!" << "\n";
                break;
        }
    }
}

void System::studentCourseMenu(Student * student) {
    std::string userInput;

    while (true) {
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

        std::string courseName;
        std::string courseToDeleteName;
        std::cin >> userInput;
        switch (stoi(userInput)) {
            case 1:
                student->printCourses();
                std::cout << "| " << student->getCoursesSize() + 1 << ". Wroc" << "\n";
                std::cout << "[========================================================================================]\n";

                std::cout << "Wybierz kurs: ";
                std::cin >> userInput;

                if (std::stoi(userInput) - 1 < student->getCoursesSize()) {
                    student->getCourseAtIndex(std::stoi(userInput) - 1)->openStudentCourseMenu(student);
                } else if (std::stoi(userInput) - 1 == student->getCoursesSize()) {
                    std::cout << "Wyszedles z menu kursow!" << "\n";
                } else {
                    std::cout << "Podany kurs nie istnieje!" << "\n";
                }
                break;
            case 2:
                printCourses();
                std::cout << "| " << getCoursesSize() + 1 << ". Wroc" << "\n";
                std::cout << "[========================================================================================]\n";

                std::cout << "Wybierz kurs: ";
                std::cin >> userInput;

                if (std::stoi(userInput) - 1 < getCoursesSize()) {
                    for (int i = 0; i < student->getCoursesSize(); i++) {
                        if (student->getCourseAtIndex(i)->getName() == courses[std::stoi(userInput) - 1]->getName()) {
                            std::cout << "Juz jestes zapisany na ten kurs!" << "\n";
                            return;
                        }
                    }
                    student->addCourse(courses[std::stoi(userInput) - 1]);
                    courses[std::stoi(userInput) - 1]->addStudent(student);
                    saveCoursesToCSV(coursesFilePath);
                } else if (std::stoi(userInput) - 1 == getCoursesSize()) {
                    std::cout << "Wyszedles z menu kursow!" << "\n";
                } else {
                    std::cout << "Podany kurs nie istnieje!" << "\n";
                }
                break;
            case 3:
                courseToDeleteName = "";
                student->printCourses();
                std::cout << "| " << student->getCoursesSize() + 1 << ". Wroc" << "\n";
                std::cout << "[========================================================================================]\n";

                std::cout << "Wybierz kurs: ";
                std::cin >> userInput;
                if (std::stoi(userInput) - 1 < student->getCoursesSize()) {
                    for (int i = 0; i < student->getCoursesSize(); i++) {
                        if (student->getCourseAtIndex(i)->getName() == student->getCourseAtIndex(std::stoi(userInput) - 1)->getName()) {
                            std::string courseToDeleteName = student->getCourseAtIndex(i)->getName();
                            for (int j = 0; j < courses.size(); j++) {
                                if (courses[j]->getName() == courseToDeleteName) {
                                    courses[j]->removeStudent(student->getLogin());
                                    student->removeCourse(courseToDeleteName);
                                    std::cout << "Wyszedles z kursu " << courses[j]->getName() << "!" << "\n";
                                }
                            }
                        }
                    }
                } else if (std::stoi(userInput) - 1 == student->getCoursesSize()) {
                    std::cout << "Wyszedles z menu kursow!" << "\n";
                } else {
                    std::cout << "Podany kurs nie istnieje!" << "\n";
                }
                break;
            case 4:
                student->printCourses();
                break;
            case 5:
                printCourses();
                break;
            case 6:
                std::cout << "Wyszedles z menu kursow!" << "\n";
                return;
            default:
                std::cout << "Niepoprawna opcja!" << "\n";
                break;
        }
    }
}

void System::lecturerCourseMenu(Lecturer * lecturer) {
    std::string userInput;

    while (true) {
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

        std::string inputLine;
        std::string courseName;
        std::string courseToDeleteName;
        Course * newCourse;
        std::cin >> userInput;
        switch (stoi(userInput)) {
            case 1:
                lecturer->printCourses();
                std::cout << "| " << lecturer->getCoursesSize() + 1 << ". Wroc" << "\n";
                std::cout << "[========================================================================================]\n";

                std::cout << "Wybierz kurs: ";
                std::cin >> userInput;

                if (std::stoi(userInput) - 1 < lecturer->getCoursesSize()) {
                    lecturer->getCourseAtIndex(std::stoi(userInput) - 1)->openLecturerCourseMenu(lecturer);
                } else if (std::stoi(userInput) - 1 == lecturer->getCoursesSize()) {
                    std::cout << "Wyszedles z menu kursow!" << "\n";
                } else {
                    std::cout << "Podany kurs nie istnieje!" << "\n";
                }
                break;
            case 2:
                userInput = "";
                std::cout << "Podaj nazwe kursu: ";
                while (std::getline(std::cin, inputLine)) {
                    userInput += inputLine;
                    if (inputLine.find(' ') != std::string::npos) {
                        break;
                    }
                }

                for (int i = 0; i < courses.size(); i++) {
                    if (courses[i]->getName() == userInput) {
                        std::cout << "Kurs o podanej nazwie juz istnieje!" << "\n";
                        return;
                    }
                }

                newCourse = new Course(userInput, lecturer);
                addCourse(newCourse);
                lecturer->addCourse(newCourse);
                saveCoursesToCSV(coursesFilePath);
                std::cout << "Kurs zostal utworzony!" << "\n";
                break;
            case 3:
                lecturer->printCourses();
                std::cout << "| " << lecturer->getCoursesSize() + 1 << ". Wroc" << "\n";
                std::cout << "[========================================================================================]\n";

                std::cout << "Wybierz kurs: ";
                std::cin >> userInput;
                if(std::stoi(userInput) - 1 < lecturer->getCoursesSize()) {
                    for (int i = 0; i < lecturer->getCoursesSize(); i++) {
                        if (lecturer->getCourseAtIndex(i)->getName() == lecturer->getCourseAtIndex(std::stoi(userInput) - 1)->getName()) {
                            std::string courseToDeleteName = lecturer->getCourseAtIndex(i)->getName();
                            for (int j = 0; j < courses.size(); j++) {
                                if (courses[j]->getName() == courseToDeleteName) {
                                    courses.erase(courses.begin() + j);
                                    saveCoursesToCSV(coursesFilePath);
                                    lecturer->removeCourse(courseToDeleteName);
                                    std::cout << "Kurs " << courseToDeleteName << " zostal zamkniety!" << "\n";
                                }
                            }
                        }
                    }
                } 
                break;
            case 4:
                lecturer->printCourses();
                break;
            case 5:
                printCourses();
                break;
            case 6:
                std::cout << "Wyszedles z menu kursow!" << "\n";
                return;
            default:
                std::cout << "Niepoprawna opcja!" << "\n";
                break;
        }
    }
}
