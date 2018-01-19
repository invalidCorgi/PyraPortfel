//
// Created by wojtekreg on 15.01.18.
//

#include "Kontrakt.h"

Kontrakt::Kontrakt(std::string opis, double wartosc, int czasTrwania) : Aktywa(opis, wartosc) {
    setCzasTrwania(czasTrwania);
}

void Kontrakt::setCzasTrwania(int czasTrwania) {
    if(czasTrwania>0) {
        this->czasTrwania = czasTrwania;
    } else{
        throw std::string("czas trwania musi byc wiekszy od zera");
    }
}

void Kontrakt::wyswietlInformacje() {
    std::cout << "1: Opis: " << getOpis() << std::endl;
    std::cout << "2: Wartosc: " << getWartosc() << std::endl;
    std::cout << "3: Czas trwania [miesiace]: " << czasTrwania << std::endl;
}

double Kontrakt::wartoscWMiesiacu(int miesiac) {
    if(miesiac<0){
        throw std::string("miesiac musi byc liczba naturalna");
    }
    if(miesiac < czasTrwania){
        return 0;
    } else{
        return getWartosc();
    }
}

void Kontrakt::edytuj() {
    char wybor;
    std::string daneWejsciowe;
    do{
        try {
            wyswietlInformacje();
            std::cout << "Wybierz ktore pole chcesz zmodyfikowac (4 aby wyjsc z edycji): ";
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
                    std::cout << "Wprowadz liczbe od 1 do 4" << std::endl;
                    break;
            }
        }
        catch (std::string &string){
            std::cout << string << std::endl;
        }
    }while(wybor != '4');
}

std::string Kontrakt::serializuj() {
    std::string string = "";

    string += "2";
    string += "\n";
    string += Aktywa::serializuj();
    string += std::to_string(czasTrwania);
    string += "\n";

    return string;
}
