//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : System Obsługi Studiów
//  @ File Name : VideoConference.cpp
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#include "VideoConference.h"

VideoConference::VideoConference(std::string name, Lecturer * lecturer) {
	this->name = name;
	this->lecturer = lecturer;
}

void VideoConference::addStudent(Student * student) {
	students.push_back(student);
}

void VideoConference::removeStudent(std::string login) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->getLogin() == login) {
			students.erase(students.begin() + i);
			break;
		}
	}
}

void VideoConference::openStudentVideoConferenceMenu(Student * student) {
    std::string userInput;

	while (true) {
        std::cout << "[========================================================================================]\n";
        std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Menu Wideokonferencji~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        std::cout << "[========================================================================================]\n";
        std::cout << "| 1. Wyswietl uczestnikow                                                                |\n";
        std::cout << "| 2. Wyjdz z wideokonferencji                                                            |\n";
        std::cout << "[========================================================================================]\n";

		std::cin >> userInput;
        switch (std::stoi(userInput)) {
            case 1:
                std::cout << "[========================================================================================]\n";
                std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Uczestnicy Wideokonferencji~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
                std::cout << "[========================================================================================]\n";
                std::cout << "| Wykladowca: " << lecturer->getFirstName() << " " << lecturer->getLastName() << "\n";

                if (!students.empty()) {
                    for (int i = 0; i < students.size(); i++) {
                        std::cout << "| " << i + 1 << ". " << students.at(i)->getFirstName() << " " << students.at(i)->getLastName() << "\n";
                    }
                } else {
                    std::cout << "Brak uczestnikow!" << "\n";
                }
                break;
            case 2:
                for (int i = 0; i < students.size(); i++) {
                    if (students[i] == student) {
                        removeStudent(student->getLogin());
                        std::cout << "Wyjscie z wideokonferencji!" << "\n";
                        break;
                    }
                }
                return;
            default:
                std::cout << "Niepoprawna opcja!" << "\n";
                break;
        }
	}
}

void VideoConference::openLecturerVideoConferenceMenu(Lecturer * lecturer) {
    std::string userInput;

    while (true) {
        std::cout << "[========================================================================================]\n";
        std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Menu Wideokonferencji~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        std::cout << "[========================================================================================]\n";
        std::cout << "| 1. Wyswietl uczestnikow                                                                |\n";
        std::cout << "| 2. Zakoncz wideokonferencje                                                            |\n";
        std::cout << "[========================================================================================]\n";

        std::cin >> userInput;
        switch (std::stoi(userInput)) {
            case 1:
                std::cout << "[========================================================================================]\n";
                std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Uczestnicy Wideokonferencji~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
                std::cout << "[========================================================================================]\n";
                std::cout << "| Wykladowca: " << lecturer->getFirstName() << " " << lecturer->getLastName() << "\n";

                if (!students.empty()) {
                    for (int i = 0; i < students.size(); i++) {
                        std::cout << "| " << i + 1 << ". " << students.at(i)->getFirstName() << " " << students.at(i)->getLastName() << "\n";
                    }
                } else {
                    std::cout << "Brak uczestnikow!" << "\n";
                }
                break;
            case 2:
                for (int i = 0; i < students.size(); i++) {
                    removeStudent(students[i]->getLogin());
                }
                std::cout << "Zakonczono wideokonferencje!" << "\n";
                return;
            default:
                std::cout << "Niepoprawna opcja!" << "\n";
                break;
        }
    }
}