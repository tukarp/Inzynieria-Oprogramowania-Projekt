//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : System Obsługi Studiów
//  @ File Name : User.cpp
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

// Deklaracja zależności i bibliotek
#include <iostream>
#include "User.h"

// Konstruktor klasy User z polami firstName, lastName, login, password i email
User::User(std::string firstName, std::string lastName, std::string login, std::string password, std::string email) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->login = login;
	this->password = password;
	this->email = email;
}

// Konstruktor klasy User z polami firstName i lastName
User::User(std::string firstName, std::string lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
}

// Pusty konstruktor klasy User
User::User() {}

// Akcesor pola firstName
std::string User::getFirstName() {
    return firstName;
}

// Mutator pola firstName
void User::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

// Akcesor pola lastName
std::string User::getLastName() {
	return lastName;
}

// Mutator pola lastName
void User::setLastName(std::string lastName) {
	this->lastName = lastName;
}

// Akcesor pola login
std::string User::getLogin() {
	return login;
}

// Mutator pola login
void User::setLogin(std::string login) {
	this->login = login;
}

// Akcesor pola password
std::string User::getPassword() {
	return password;
}

// Mutator pola password
void User::setPassword(std::string password) {
	this->password = password;
}

// Akcesor pola email
std::string User::getEmail() {
	return email;
}

// Mutator pola email
void User::setEmail(std::string email) {
	this->email = email;
}

// Metoda wyświetlająca dane użytkownika
void User::printUser() {
    // Utwórz zmienne do wyświetlenia nagłówka danych użytkownika
    const std::string headerName = "Uzytkownik";  // Nazwa nagłówka
    const int totalWidth = 90;  // Szerokość całego wyświetlanego napisu
    const int nameWidth = headerName.length();  // Szerokość nazwy kursu
    const int paddingWidth = (totalWidth - nameWidth) / 2;  // Szerokość wypełnienia
    std::string hiddenUserPassword = getPassword();  // Utwórz ukrytą kopię hasła użytkownika

    // Zamień każdy znak hasła na znak '*'
    hiddenUserPassword.replace(0, hiddenUserPassword.length(), hiddenUserPassword.length(), '*');

    // Wyświetl nagłówek danych użytkownika
    std::cout << "[========================================================================================]\n";
    std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Uzytkownik~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    std::cout << "|========================================================================================|\n";
    // Wyświetl dane użytkownika
    std::cout << "| Login: " << getLogin() << "\n";  // Wyświetl login użytkownika
    std::cout << "| Haslo: " << hiddenUserPassword << "\n";  // Wyświetl ukryte hasło użytkownika
    std::cout << "| Imie: " << getFirstName() << "\n";  // Wyświetl imię użytkownika
    std::cout << "| Nazwisko: " << getLastName() << "\n";  // Wyświetl nazwisko użytkownika
    std::cout << "| Email: " << getEmail() << "\n";  // Wyświetl email użytkownika
    std::cout << "[========================================================================================]\n";
}
