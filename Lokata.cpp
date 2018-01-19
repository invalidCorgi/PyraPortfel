//
// Created by wojtekreg on 15.01.18.
//

#include "Lokata.h"

Lokata::Lokata(std::string opis, double wartosc, double oprocentowanie, int czasTrwania) : Aktywa(opis, wartosc){
    setOprocentowanie(oprocentowanie);
    setCzasTrwania(czasTrwania);
}

void Lokata::setOprocentowanie(double oprocentowanie) {
    if(oprocentowanie>=0) {
        this->oprocentowanie = oprocentowanie;
    } else{
        throw std::string("oprocentowanie nie moze byc ujemne");
    }
}

void Lokata::setCzasTrwania(int czasTrwania) {
    if(czasTrwania>0) {
        this->czasTrwania = czasTrwania;
    } else{
        throw std::string("czas trwania musi byc wiekszy od zera");
    }
}

void Lokata::wyswietlInformacje() {
    std::cout << "1: Opis: " << getOpis() << std::endl;
    std::cout << "2: Aktualna wartosc: " << getWartosc() << std::endl;
    std::cout << "3: Oprocentowanie: " << oprocentowanie << "%" << std::endl;
    std::cout << "4: Czas trwania [miesiace]: " << czasTrwania << std::endl;
}

double Lokata::wartoscWMiesiacu(int miesiac) {
    if(miesiac<0){
        throw std::string("miesiac musi byc liczba naturalna");
    }
    if(miesiac == 0){
        return getWartosc();
    }
    double tempWartosc = getWartosc();
    for (int i = 1; i <= miesiac && i<=czasTrwania; ++i) {
        tempWartosc *= (100 + (oprocentowanie / 12)) / 100;
    }
    return tempWartosc;
}

void Lokata::edytuj() {
    char wybor;
    std::string daneWejsciowe;
    do{
        try {
            wyswietlInformacje();
            std::cout << "Wybierz ktore pole chcesz zmodyfikowac (5 aby wyjsc z edycji): ";
            std::cin >> wybor;
            switch (wybor) {
                case '1':
                    std::cout << "Wprowadz nowy opis:" << std::endl;
                    std::cin >> daneWejsciowe;
                    setOpis(daneWejsciowe);
                    break;
                case '2':
                    double wartosc;
                    std::cout << "Wprowadz nowa wartosc:" << std::endl;
                    std::cin >> daneWejsciowe;
                    try {
                        wartosc = std::stod(daneWejsciowe);
                    }
                    catch(...){
                        throw std::string("Wpisz liczbe");
                    }
                    setWartosc(wartosc);
                    break;
                case '3':
                    double oprocentowanie;
                    std::cout << "Wprowadz nowe oprocentowanie [%]:" << std::endl;
                    std::cin >> daneWejsciowe;
                    try{
                        oprocentowanie = std::stod(daneWejsciowe);
                    }
                    catch(...){
                        throw std::string("Wpisz liczbe");
                    }
                    setOprocentowanie(oprocentowanie);
                    break;
                case '4':
                    int czasTrwania;
                    std::cout << "Wprowadz nowy czas trwania [miesiace]:" << std::endl;
                    std::cin >> daneWejsciowe;
                    try{
                        czasTrwania = std::stoi(daneWejsciowe);
                    }
                    catch(...){
                        throw std::string("Wpisz liczbe");
                    }
                    setCzasTrwania(czasTrwania);
                    break;
                default:
                    std::cout << "Wprowadz liczbe od 1 do 5" << std::endl;
                    break;
            }
        }
        catch (std::string &string){
            std::cout << string << std::endl;
        }
    }while(wybor!='5');
}

std::string Lokata::serializuj() {
    std::string string = "";

    string += "3";
    string += "\n";
    string += Aktywa::serializuj();
    string += std::to_string(oprocentowanie);
    string += "\n";
    string += std::to_string(czasTrwania);
    string += "\n";

    return string;
}
