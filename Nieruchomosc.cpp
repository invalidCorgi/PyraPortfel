//
// Created by wojtekreg on 15.01.18.
//

#include "Nieruchomosc.h"

Nieruchomosc::Nieruchomosc(std::string opis, double wartosc, double miesiecznaZmianaWartosci, double miesiecznyCzynsz) : Aktywa(opis, wartosc){
    setMiesiecznaZmianaWartosci(miesiecznaZmianaWartosci);
    this->miesiecznyCzynsz = miesiecznyCzynsz;
}

void Nieruchomosc::setMiesiecznaZmianaWartosci(double miesiecznaZmianaWartosci) {
    this->miesiecznaZmianaWartosci = miesiecznaZmianaWartosci;
}

void Nieruchomosc::setMiesiecznyCzynsz(double miesiecznyCzynsz) {
    if(miesiecznyCzynsz>=0) {
        this->miesiecznyCzynsz = miesiecznyCzynsz;
    } else{
        throw std::string("czynsz nie moze byc ujemny");
    }
}

void Nieruchomosc::wyswietlInformacje() {
    std::cout << "1: Opis: " << getOpis() << std::endl;
    std::cout << "2: Aktualna wartosc: " << getWartosc() << std::endl;
    std::cout << "3: Miesieczna zmiana wartosci: " << miesiecznaZmianaWartosci<< std::endl;
    std::cout << "4: Miesieczny czynsz: " << miesiecznyCzynsz<< std::endl;
}

double Nieruchomosc::wartoscWMiesiacu(int miesiac) {
    if(miesiac<0){
        throw std::string("miesiac musi byc liczba naturalna");
    }
    if(miesiac == 0){
        return getWartosc();
    }
    double tempWartosc = getWartosc();
    for (int i = 1; i <= miesiac; ++i) {
        tempWartosc += miesiecznaZmianaWartosci;
        tempWartosc += miesiecznyCzynsz;
    }
    return tempWartosc;
}

void Nieruchomosc::edytuj() {
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
                    double miesiecznaZmianaWartosci;
                    std::cout << "Wprowadz nowa szacowana miesieczna zmiane wartosci:" << std::endl;
                    std::cin >> daneWejsciowe;
                    try{
                        miesiecznaZmianaWartosci = std::stod(daneWejsciowe);
                    }
                    catch(...){
                        throw std::string("Wpisz liczbe");
                    }
                    setMiesiecznaZmianaWartosci(miesiecznaZmianaWartosci);
                    break;
                case '4':
                    double miesiecznyCzynsz;
                    std::cout << "Wprowadz nowy miesieczny czynsz:" << std::endl;
                    std::cin >> daneWejsciowe;
                    try{
                        miesiecznyCzynsz = std::stod(daneWejsciowe);
                    }
                    catch(...){
                        throw std::string("Wpisz liczbe");
                    }
                    setMiesiecznyCzynsz(miesiecznyCzynsz);
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

std::string Nieruchomosc::serializuj() {
    std::string string = "";

    string += "4";
    string += "\n";
    string += Aktywa::serializuj();
    string += std::to_string(miesiecznaZmianaWartosci);
    string += "\n";
    string += std::to_string(miesiecznyCzynsz);
    string += "\n";

    return string;
}
