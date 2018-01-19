//
// Created by wojtekreg on 15.01.18.
//

#include "Aktywa.h"

Aktywa::Aktywa(std::string opis, double wartosc) {
    setOpis(opis);
    setWartosc(wartosc);
}

void Aktywa::setOpis(std::string opis) {
    this->opis = opis;
}

void Aktywa::setWartosc(double wartosc) {
    if(wartosc >= 0) {
        this->wartosc = wartosc;
    } else{
        throw std::string("wartosc nie moze byc ujemna");
    }

}

std::string Aktywa::getOpis() {
    return opis;
}

double Aktywa::getWartosc() {
    return wartosc;
}

std::string Aktywa::serializuj() {
    std::string string = "";

    string += opis;
    string += "\n";
    string += std::to_string(wartosc);
    string += "\n";

    return string;
}
