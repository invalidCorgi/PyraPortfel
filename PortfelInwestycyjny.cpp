//
// Created by wojtekreg on 15.01.18.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Aktywa.h"
#include "IKE.h"
#include "Kontrakt.h"
#include "Lokata.h"
#include "Nieruchomosc.h"
#include "ProduktStrukturyzowany.h"

template <class T>
class PortfelInwestycyjny{
private:
    std::vector<T*> listaElementow;

public:
    PortfelInwestycyjny<T>& operator+=(T* element)
    {
        listaElementow.push_back(element);
    }

    PortfelInwestycyjny<T>& operator-=(int index)
    {
        if(index < 0 || index > listaElementow.size()){
            throw std::string("Nie istnieje element o tym indeksie");
        }
        listaElementow.erase(listaElementow.begin() + index);
    }
};

template<>
class PortfelInwestycyjny<Aktywa>{
private:
    std::vector<Aktywa*> listaAktywow;
    std::string nazwaPliku = "portfel.txt";

    void wczytajZPliku(){
        std::ifstream plik(nazwaPliku);
        std::string liniaDanychWejsciowych;
        int idObiektu;

        std::string opis;
        double wartosc;
        double miesiecznaWplata;
        double oprocentowanie;
        double podatekZaZbytWczesneZakonczenie;
        double miesiecznaZmianaWartosci;
        double miesiecznyCzynsz;
        double udzialWZyskach;
        double maksymalnyZysk;
        int czasTrwania;

        while(plik.good()){
            getline(plik, liniaDanychWejsciowych);
            if(liniaDanychWejsciowych.empty()){
                return;
            }
            idObiektu = std::stoi(liniaDanychWejsciowych);

            switch (idObiektu){
                case 1:
                    getline(plik, opis);
                    getline(plik, liniaDanychWejsciowych);
                    wartosc = std::stod(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    miesiecznaWplata = std::stod(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    oprocentowanie = std::stod(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    czasTrwania = std::stoi(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    podatekZaZbytWczesneZakonczenie = std::stod(liniaDanychWejsciowych);

                    this->operator+=(new IKE(opis, wartosc, miesiecznaWplata, oprocentowanie, czasTrwania, podatekZaZbytWczesneZakonczenie));

                    break;
                case 2:
                    getline(plik, opis);
                    getline(plik, liniaDanychWejsciowych);
                    wartosc = std::stod(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    czasTrwania = std::stoi(liniaDanychWejsciowych);

                    this->operator+=(new Kontrakt(opis, wartosc, czasTrwania));

                    break;
                case 3:
                    getline(plik, opis);
                    getline(plik, liniaDanychWejsciowych);
                    wartosc = std::stod(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    oprocentowanie = std::stod(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    czasTrwania = std::stoi(liniaDanychWejsciowych);

                    this->operator+=(new Lokata(opis, wartosc, oprocentowanie, czasTrwania));

                    break;
                case 4:
                    getline(plik, opis);
                    getline(plik, liniaDanychWejsciowych);
                    wartosc = std::stod(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    miesiecznaZmianaWartosci = std::stod(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    miesiecznyCzynsz = std::stod(liniaDanychWejsciowych);

                    this->operator+=(new Nieruchomosc(opis, wartosc, miesiecznaZmianaWartosci, miesiecznyCzynsz));

                    break;
                case 5:
                    getline(plik, opis);
                    getline(plik, liniaDanychWejsciowych);
                    wartosc = std::stod(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    czasTrwania = std::stoi(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    udzialWZyskach = std::stod(liniaDanychWejsciowych);
                    getline(plik, liniaDanychWejsciowych);
                    maksymalnyZysk = std::stod(liniaDanychWejsciowych);

                    this->operator+=(new ProduktStrukturyzowany(opis, wartosc, czasTrwania, udzialWZyskach, maksymalnyZysk));

                    break;
                default:
                    break;
            }
        }
    }

    void zapiszDoPliku(){
        std::ofstream plik(nazwaPliku);

        if(plik.good()){
            for (auto &aktywa : listaAktywow) {
                plik << aktywa->serializuj();
            }
        }

        plik.close();
    }

public:
    PortfelInwestycyjny()
    {
        wczytajZPliku();
    }

    PortfelInwestycyjny<Aktywa>& operator+=(Aktywa* element)
    {
        if(element == nullptr){
            throw std::string("Dodawane aktywa nie istnieja");
        }
        listaAktywow.push_back(element);
        zapiszDoPliku();
    }

    PortfelInwestycyjny<Aktywa>& operator-=(int index)
    {
        if(index < 0 || index >= listaAktywow.size()){
            throw std::string("Nie istnieje element o tym indeksie");
        }
        delete listaAktywow[index];
        listaAktywow.erase(listaAktywow.begin() + index);
        zapiszDoPliku();
    }

    void edytujAktywa(int indeks){
        if(indeks < 0 || indeks >= listaAktywow.size()){
            throw std::string("Nie istnieje element o tym indeksie");
        }
        listaAktywow[indeks]->edytuj();
        zapiszDoPliku();
    }

    void wyswietlAktywa(){
        std::cout << "Posiadasz aktywow: " << listaAktywow.size() << std::endl;
        for (int i = 0; i < listaAktywow.size(); ++i) {
            std::cout << std:: endl << "Aktywa nr " << i << std::endl;
            listaAktywow[i]->wyswietlInformacje();
        }
    }

    double getWartoscOszczednosciWMiesiacu(int miesiac){
        if(miesiac <= 0){
            throw std::string("Symulacje mozna przeprowadzic dla miesiecy wiekszych od zera");
        }
        double suma = 0;
        for (auto &i : listaAktywow) {
            suma += i->wartoscWMiesiacu(miesiac);
        }
        return suma;

    }

    double getAktualnaWartoscOszczednosci(){
        double suma = 0;
        for (auto &i : listaAktywow) {
            suma += i->wartoscWMiesiacu(0);
        }
        return suma;
    }
};