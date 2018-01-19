#include <iostream>
#include <netinet/in.h>
#include <climits>

#include "main.h"
#include "Aktywa.h"
#include "IKE.h"
#include "Kontrakt.h"
#include "Lokata.h"
#include "Nieruchomosc.h"
#include "ProduktStrukturyzowany.h"
#include "PortfelInwestycyjny.cpp"

int main() {
    PortfelInwestycyjny<Aktywa> portfelInwestycyjny;
    //IKE* ike = new IKE("ff", 2, 3, 4, 5, 6);
    //std::cout << ike->serializuj();
    std::cout << "Witaj w swojej ewidencji oszczednosci" << std::endl;

    char wybor;
    std::string daneWejsciowe;
    int indeks;
    double wartosc;
    do{
        try {
            std::cout << std::endl;
            wyswietlMenu();
            std::cout << std::endl << "Wybierz opcje od 1 do 6: ";
            std::cin >> wybor;
            switch (wybor) {
                //wyswietlanie stanu aktywow
                case '1':
                    std::cout << std::endl;
                    portfelInwestycyjny.wyswietlAktywa();
                    wartosc = portfelInwestycyjny.getAktualnaWartoscOszczednosci();
                    std::cout << "Aktualna laczna wartosc oszczednosci to: " << wartosc << std::endl;
                    break;
                    //dodawanie aktywow
                case '2':
                    char wybor2;
                    do {
                        try {
                            std::cout << std::endl;
                            wyswietlMozliweAktywaDoStworzenia();
                            std::cout << "Wybierz jaki typ aktywow chcesz dodac (6 aby anulowac): ";
                            std::cin >> wybor2;
                            switch (wybor2) {
                                case '1':
                                    portfelInwestycyjny += tworzenieIKE();
                                    break;
                                case '2':
                                    portfelInwestycyjny += tworzenieKontraktu();
                                    break;
                                case '3':
                                    portfelInwestycyjny += tworzenieLokaty();
                                    break;
                                case '4':
                                    portfelInwestycyjny += tworzenieNieruchomosci();
                                    break;
                                case '5':
                                    portfelInwestycyjny += tworzenieProduktuStrukturyzowanego();
                                    break;
                                case '6':
                                    break;
                                default:
                                    std::cout << "Wprowadz liczbe od 1 do 6" << std::endl;
                                    break;
                            }
                        }
                        catch(std::string &ex){
                            std::cout << ex << std::endl;
                        }
                    }while (wybor2 != '6');
                    break;
                //edytowanie aktywow
                case '3':
                    std::cout << std::endl;
                    portfelInwestycyjny.wyswietlAktywa();
                    std::cout << std::endl;
                    std::cout << "Aktywa o ktorym indeksie chcesz edytowac: ";
                    std::cin >> daneWejsciowe;
                    try {
                        indeks = std::stoi(daneWejsciowe);
                    }
                    catch (...) {
                        throw std::string("Wprowadzona liczba jest nieprawidlowa");
                    }
                    portfelInwestycyjny.edytujAktywa(indeks);
                    break;
                //usuwanie aktywow
                case '4':
                    std::cout << std::endl;
                    portfelInwestycyjny.wyswietlAktywa();
                    std::cout << std::endl;
                    std::cout << "Aktywa o ktorym indeksie chcesz usunac: ";
                    std::cin >> daneWejsciowe;
                    try {
                        indeks = std::stoi(daneWejsciowe);
                    }
                    catch (...) {
                        throw std::string("Wprowadzona liczba jest nieprawidlowa");
                    }
                    portfelInwestycyjny -= indeks;
                    break;
                //symulacja oszczednosci
                case '5':
                    std::cout << std::endl;
                    std::cout << "Ile miesiecy ma obejmowac symulacja: ";
                    std::cin >> daneWejsciowe;
                    try {
                        indeks = std::stoi(daneWejsciowe);
                    }
                    catch (...) {
                        throw std::string("Wprowadzona liczba jest nieprawidlowa");
                    }
                    wartosc = portfelInwestycyjny.getWartoscOszczednosciWMiesiacu(indeks);
                    std::cout << "Prognozowana wartosc oszczednosci za " << indeks << " miesiecy: " << wartosc << std::endl;
                    break;
                case '6':
                    break;
                default:
                    std::cout << "Wprowadz liczbe od 1 do 6" << std::endl;
                    break;
            }
        }
        catch(std::string &ex){
            std::cout << ex << std::endl;
        }
    }while(wybor!='6');

    return 0;
}

void wyswietlMenu(){
    std::cout << "1: Wyswietlenie aktualnego stanu oszczednosci" << std::endl;
    std::cout << "2: Dodanie aktywu do portfela" << std::endl;
    std::cout << "3: Edytowanie wybranego aktywu z portfela" << std::endl;
    std::cout << "4: Usuwanie wybranego aktywu z portfela" << std::endl;
    std::cout << "5: Symulacja przewidywanej wartosci oszczednosci za x miesiecy" << std::endl;
    std::cout << "6: Wyjscie z programu" << std::endl;
}

void wyswietlMozliweAktywaDoStworzenia(){
    std::cout << "1: IKE" << std::endl;
    std::cout << "2: Kontrakt" << std::endl;
    std::cout << "3: Lokata" << std::endl;
    std::cout << "4: Nieruchomosc" << std::endl;
    std::cout << "5: Produkt Strukturyzowany" << std::endl;
}

IKE* tworzenieIKE(){
    std::string daneWejsciowe;

    std::string opis;
    double wartosc;
    double miesiecznaWplata;
    double oprocentowanie;
    int czasTrwania;
    double podatekZaZbytWczesneZakonczenie;

    std::cout << "Wprowadz opis:" << std::endl;
    std::cin >> opis;
    std::cout << "Wprowadz poczatkowa wplate:" << std::endl;
    std::cin >> daneWejsciowe;
    try {
        wartosc = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz miesieczna wplate:" << std::endl;
    std::cin >> daneWejsciowe;
    try {
        miesiecznaWplata = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz oprocentowanie [%]:" << std::endl;
    std::cin >> daneWejsciowe;
    try{
        oprocentowanie = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz czas trwania [miesiace]:" << std::endl;
    std::cin >> daneWejsciowe;
    try{
        czasTrwania = std::stoi(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz podatek przy przedwczesnej wyplacie [%]:" << std::endl;
    std::cin >> daneWejsciowe;
    try {
        podatekZaZbytWczesneZakonczenie = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }

    IKE* ike = new IKE(opis, wartosc, miesiecznaWplata, oprocentowanie, czasTrwania, podatekZaZbytWczesneZakonczenie);
    return ike;
}

Kontrakt* tworzenieKontraktu(){
    std::string daneWejsciowe;

    std::string opis;
    double wartosc;
    int czasTrwania;

    std::cout << "Wprowadz opis:" << std::endl;
    std::cin >> opis;
    std::cout << "Wprowadz wartosc:" << std::endl;
    std::cin >> daneWejsciowe;
    try {
        wartosc = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz czas trwania [miesiace]:" << std::endl;
    std::cin >> daneWejsciowe;
    try{
        czasTrwania = std::stoi(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }

    Kontrakt* kontrakt = new Kontrakt(opis, wartosc, czasTrwania);
    return kontrakt;
}

Lokata* tworzenieLokaty(){
    std::string daneWejsciowe;

    std::string opis;
    double wartosc;
    double oprocentowanie;
    int czasTrwania;

    std::cout << "Wprowadz opis:" << std::endl;
    std::cin >> opis;
    std::cout << "Wprowadz poczatkowa wplate:" << std::endl;
    std::cin >> daneWejsciowe;
    try {
        wartosc = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz oprocentowanie [%]:" << std::endl;
    std::cin >> daneWejsciowe;
    try{
        oprocentowanie = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz czas trwania [miesiace]:" << std::endl;
    std::cin >> daneWejsciowe;
    try{
        czasTrwania = std::stoi(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }

    Lokata* lokata = new Lokata(opis, wartosc, oprocentowanie, czasTrwania);

    return lokata;
}

Nieruchomosc* tworzenieNieruchomosci(){
    std::string daneWejsciowe;

    std::string opis;
    double wartosc;
    double miesiecznaZmianaWartosci;
    double miesiecznyCzynsz;

    std::cout << "Wprowadz opis:" << std::endl;
    std::cin >> opis;
    std::cout << "Wprowadz aktualna wartosc:" << std::endl;
    std::cin >> daneWejsciowe;
    try {
        wartosc = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz szacowana miesieczna zmiane wartosci:" << std::endl;
    std::cin >> daneWejsciowe;
    try{
        miesiecznaZmianaWartosci = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz miesieczny czynsz:" << std::endl;
    std::cin >> daneWejsciowe;
    try{
        miesiecznyCzynsz = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }

    Nieruchomosc* nieruchomosc = new Nieruchomosc(opis, wartosc, miesiecznaZmianaWartosci, miesiecznyCzynsz);

    return nieruchomosc;
}

ProduktStrukturyzowany* tworzenieProduktuStrukturyzowanego(){
    std::string daneWejsciowe;

    std::string opis;
    double wartosc;
    int czasTrwania;
    double udzialWZyskach;
    double maksymalnyZysk;

    std::cout << "Wprowadz opis:" << std::endl;
    std::cin >> opis;
    std::cout << "Wprowadz wartosc:" << std::endl;
    std::cin >> daneWejsciowe;
    try {
        wartosc = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz czas trwania [miesiace]:" << std::endl;
    std::cin >> daneWejsciowe;
    try{
        czasTrwania = std::stoi(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz udzial w zyskach [%]:" << std::endl;
    std::cin >> daneWejsciowe;
    try {
        udzialWZyskach = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }
    std::cout << "Wprowadz maksymalny zysk [%]:" << std::endl;
    std::cin >> daneWejsciowe;
    try {
        maksymalnyZysk = std::stod(daneWejsciowe);
    }
    catch(...){
        throw std::string("Wpisz liczbe");
    }

    ProduktStrukturyzowany* produktStrukturyzowany = new ProduktStrukturyzowany(opis, wartosc, czasTrwania, udzialWZyskach, maksymalnyZysk);

    return produktStrukturyzowany;
}