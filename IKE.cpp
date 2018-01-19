//
// Created by wojtekreg on 15.01.18.
//

#include "IKE.h"

IKE::IKE(std::string opis, double wartosc, double miesiecznaWplata, double oprocentowanie, int czasTrwania,
         double podatekZaZbytWczesneZakonczenie) : Aktywa(opis, wartosc){
    setMiesiecznaWplata(miesiecznaWplata);
    setOprocentowanie(oprocentowanie);
    setCzasTrwania(czasTrwania);
    setPodatekZaZbytWczesneZakonczenie(podatekZaZbytWczesneZakonczenie);
}

void IKE::setMiesiecznaWplata(double miesiecznaWplata) {
    if(miesiecznaWplata>=0) {
        this->miesiecznaWplata = miesiecznaWplata;
    } else{
        throw std::string("miesieczna wplata nie moze byc ujemna");
    }
}

void IKE::setOprocentowanie(double oprocentowanie) {
    if(oprocentowanie>=0) {
        this->oprocentowanie = oprocentowanie;
    } else{
        throw std::string("oprocentowanie nie moze byc ujemne");
    }
}

void IKE::setCzasTrwania(int czasTrwania) {
    if(czasTrwania>0) {
        this->czasTrwania = czasTrwania;
    } else{
        throw std::string("czas trwania musi byc wiekszy od zera");
    }
}

void IKE::setPodatekZaZbytWczesneZakonczenie(double podatekZaZbytWczesneZakonczenie) {
    if(podatekZaZbytWczesneZakonczenie>=0 && podatekZaZbytWczesneZakonczenie<=100){
        this->podatekZaZbytWczesneZakonczenie = podatekZaZbytWczesneZakonczenie;
    } else{
        throw std::string("podatek musi byc w przedziale od 0 do 100%");
    }
}

void IKE::wyswietlInformacje() {
    std::cout << "1: Opis: " << getOpis() << std::endl;
    std::cout << "2: Aktualna wartosc: " << getWartosc() << std::endl;
    std::cout << "3: Miesieczna wplata: " << miesiecznaWplata << std::endl;
    std::cout << "4: Oprocentowanie: " << oprocentowanie << "%" << std::endl;
    std::cout << "5: Czas trwania [miesiace]: " << czasTrwania << std::endl;
    std::cout << "6: Podatek przy przedwczesnej wyplacie: " << podatekZaZbytWczesneZakonczenie << "%" << std::endl;
}

double IKE::wartoscWMiesiacu(int miesiac) {
    if(miesiac<0){
        throw std::string("miesiac musi byc liczba naturalna");
    }
    if(miesiac == 0){
        return getWartosc();
    }
    double tempWartosc = getWartosc();
    for (int i = 1; i <= miesiac && i<=czasTrwania; ++i) {
        tempWartosc *= (100 + (oprocentowanie / 12)) / 100;
        tempWartosc += miesiecznaWplata;
    }
    if(miesiac < czasTrwania){
        tempWartosc -= (tempWartosc - getWartosc()) * (podatekZaZbytWczesneZakonczenie / 100);
    }
    return tempWartosc;
}

void IKE::edytuj() {
    char wybor;
    std::string daneWejsciowe;
    do{
        try {
            wyswietlInformacje();
            std::cout << "Wybierz ktore pole chcesz zmodyfikowac (7 aby wyjsc z edycji): ";
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
                    double miesiecznaWplata;
                    std::cout << "Wprowadz nowa miesieczna wplate:" << std::endl;
                    std::cin >> daneWejsciowe;
                    try {
                        miesiecznaWplata = std::stod(daneWejsciowe);
                    }
                    catch(...){
                        throw std::string("Wpisz liczbe");
                    }
                    setMiesiecznaWplata(miesiecznaWplata);
                    break;
                case '4':
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
                case '5':
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
                case '6':
                    double podatekZaZbytWczesneZakonczenie;
                    std::cout << "Wprowadz nowy podatek przy przedwczesnej wyplacie [%]:" << std::endl;
                    std::cin >> daneWejsciowe;
                    try {
                        podatekZaZbytWczesneZakonczenie = std::stod(daneWejsciowe);
                    }
                    catch(...){
                        throw std::string("Wpisz liczbe");
                    }
                    setPodatekZaZbytWczesneZakonczenie(podatekZaZbytWczesneZakonczenie);
                    break;
                default:
                    std::cout << "Wprowadz liczbe od 1 do 7" << std::endl;
                    break;
            }
        }
        catch (std::string &string){
            std::cout << string << std::endl;
        }
    }while(wybor!='7');
}

std::string IKE::serializuj() {
    std::string string = "";

    string += "1";
    string += "\n";
    string += Aktywa::serializuj();
    string += std::to_string(miesiecznaWplata);
    string += "\n";
    string += std::to_string(oprocentowanie);
    string += "\n";
    string += std::to_string(czasTrwania);
    string += "\n";
    string += std::to_string(podatekZaZbytWczesneZakonczenie);
    string += "\n";

    return string;
}
