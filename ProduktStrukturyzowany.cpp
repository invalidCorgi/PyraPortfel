//
// Created by wojtekreg on 15.01.18.
//

#include "ProduktStrukturyzowany.h"

ProduktStrukturyzowany::ProduktStrukturyzowany(std::string opis, double wartosc, int czasTrwania, double udzialWZyskach,
                                               double maksymalnyZysk) : Aktywa(opis, wartosc){
    setCzasTrwania(czasTrwania);
    setUdzialWZyskach(udzialWZyskach);
    setMaksymalnyZysk(maksymalnyZysk);
}

void ProduktStrukturyzowany::setCzasTrwania(int czasTrwania) {
    if(czasTrwania>0) {
        this->czasTrwania = czasTrwania;
    } else{
        throw std::string("czas trwania musi byc wiekszy od zera");
    }
}

void ProduktStrukturyzowany::setUdzialWZyskach(double udzialWZyskach) {
    if(udzialWZyskach > 0 && udzialWZyskach <= 100) {
        this->udzialWZyskach = udzialWZyskach;
    } else{
        throw std::string("udzial w zyskach musi byc dodatni i nie wiekszy niz 100%");
    }
}

void ProduktStrukturyzowany::setMaksymalnyZysk(double maksymalnyZysk) {
    if(maksymalnyZysk > 0) {
        this->maksymalnyZysk= maksymalnyZysk;
    } else{
        throw std::string("maksymalny zysk procentowy musi byc dodatni");
    }
}

void ProduktStrukturyzowany::wyswietlInformacje() {
    std::cout << "1: Opis: " << getOpis() << std::endl;
    std::cout << "2: Aktualna wartosc: " << getWartosc() << std::endl;
    std::cout << "3: Czas trwania [miesiace]: " << czasTrwania << std::endl;
    std::cout << "4: Udzial w zyskach: " << udzialWZyskach << "%" << std::endl;
    std::cout << "5: Maksymalny zysk: " << maksymalnyZysk << "%" << std::endl;
}

double ProduktStrukturyzowany::wartoscWMiesiacu(int miesiac) {
    if(miesiac<0){
        throw std::string("miesiac musi byc liczba naturalna");
    }
    if(miesiac == 0){
        return getWartosc();
    }
    if(miesiac > czasTrwania)
        miesiac = czasTrwania;
    int rand = std::rand()%101;
    double zysk = maksymalnyZysk * (udzialWZyskach/100) * ((double)rand / 100) * ((double)miesiac / 12);
    return getWartosc() * (1 + zysk/100);
}

void ProduktStrukturyzowany::edytuj() {
    char wybor;
    std::string daneWejsciowe;
    do{
        try {
            wyswietlInformacje();
            std::cout << "Wybierz ktore pole chcesz zmodyfikowac (6 aby wyjsc z edycji): ";
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
                case '4':
                    double udzialWZyskach;
                    std::cout << "Wprowadz nowy udzial w zyskach [%]:" << std::endl;
                    std::cin >> daneWejsciowe;
                    try {
                        udzialWZyskach = std::stod(daneWejsciowe);
                    }
                    catch(...){
                        throw std::string("Wpisz liczbe");
                    }
                    setUdzialWZyskach(udzialWZyskach);
                    break;
                case '5':
                    double maksymalnyZysk;
                    std::cout << "Wprowadz nowy maksymalny zysk [%]:" << std::endl;
                    std::cin >> daneWejsciowe;
                    try {
                        maksymalnyZysk = std::stod(daneWejsciowe);
                    }
                    catch(...){
                        throw std::string("Wpisz liczbe");
                    }
                    setMaksymalnyZysk(maksymalnyZysk);
                    break;
                default:
                    std::cout << "Wprowadz liczbe od 1 do 6" << std::endl;
                    break;
            }
        }
        catch (std::string &string){
            std::cout << string << std::endl;
        }
    }while(wybor!='6');
}

std::string ProduktStrukturyzowany::serializuj() {
    std::string string = "";

    string += "5";
    string += "\n";
    string += Aktywa::serializuj();
    string += std::to_string(czasTrwania);
    string += "\n";
    string += std::to_string(udzialWZyskach);
    string += "\n";
    string += std::to_string(maksymalnyZysk);
    string += "\n";

    return string;
}
