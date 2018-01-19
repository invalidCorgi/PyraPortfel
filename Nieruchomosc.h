//
// Created by wojtekreg on 15.01.18.
//

#ifndef PYRAPORTFEL_NIERUCHOMOSC_H
#define PYRAPORTFEL_NIERUCHOMOSC_H


#include "Aktywa.h"

class Nieruchomosc : public Aktywa{
private:
    double miesiecznaZmianaWartosci;
    double miesiecznyCzynsz;
    void setMiesiecznaZmianaWartosci(double miesiecznaZmianaWartosci);
    void setMiesiecznyCzynsz(double miesiecznyCzynsz);
public:
    Nieruchomosc(std::string opis, double wartosc, double miesiecznaZmianaWartosci, double miesiecznyCzynsz);
    virtual void wyswietlInformacje() override;
    virtual double wartoscWMiesiacu(int miesiac) override;
    virtual void edytuj() override;
    virtual std::string serializuj() override;
};


#endif //PYRAPORTFEL_NIERUCHOMOSC_H
