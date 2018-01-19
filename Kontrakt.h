//
// Created by wojtekreg on 15.01.18.
//

#ifndef PYRAPORTFEL_KONTRAKT_H
#define PYRAPORTFEL_KONTRAKT_H


#include "Aktywa.h"

class Kontrakt : public Aktywa{
private:
    int czasTrwania;
    void setCzasTrwania(int czasTrwania);
public:
    Kontrakt(std::string opis, double wartosc, int czasTrwania);
    virtual void wyswietlInformacje() override;
    virtual double wartoscWMiesiacu(int miesiac) override;
    virtual void edytuj() override;
    virtual std::string serializuj() override;
};


#endif //PYRAPORTFEL_KONTRAKT_H
