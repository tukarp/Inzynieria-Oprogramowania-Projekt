//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Inżynieria Oprogramowania - Projekt
//  @ File Name : Uzytkownik.h
//  @ Date : 10.06.2023
//  @ Author : Tomasz Wnuk, Bartosz Szynkaruk, Mikołaj Hasiec
//
//

#if !defined(_UZYTKOWNIK_H)
#define _UZYTKOWNIK_H

#include <string>

class Uzytkownik {
public:
	Uzytkownik(std::string imie, std::string nazwisko, std::string login, std::string haslo, std::string email);
    std::string getImie();
    void setImie(std::string imie);
    std::string getNazwisko();
    void setNazwisko(std::string nazwisko);
    std::string getLogin();
    void setLogin(std::string login);
    std::string getHaslo();
    void setHaslo(std::string haslo);
    std::string getEmail();
    void setEmail(std::string email);
private:
    std::string imie;
    std::string nazwisko;
    std::string login;
    std::string haslo;
    std::string email;
};

#endif  //_UZYTKOWNIK_H
