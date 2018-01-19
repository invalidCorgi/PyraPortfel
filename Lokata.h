//
// Created by wojtekreg on 15.01.18.
//

#ifndef PYRAPORTFEL_LOKATA_H
#define PYRAPORTFEL_LOKATA_H

#include "Aktywa.h"

class Lokata : public Aktywa{
private:
    double oprocentowanie;
    int czasTrwania;
    void setOprocentowanie(double oprocentowanie);
    void setCzasTrwania(int czasTrwania);
public:
    Lokata(std::string opis, double wartosc, double oprocentowanie, int czasTrwania);
    virtual void wyswietlInformacje() override;
    virtual double wartoscWMiesiacu(int miesiac) override;
    virtual void edytuj() override;
    virtual std::string serializuj() override;
};


#endif //PYRAPORTFEL_LOKATA_H
