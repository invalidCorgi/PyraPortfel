//
// Created by wojtekreg on 15.01.18.
//

#ifndef PYRAPORTFEL_IKE_H
#define PYRAPORTFEL_IKE_H


#include "Aktywa.h"

class IKE : public Aktywa {
private:
    double miesiecznaWplata;
    double oprocentowanie;
    int czasTrwania;
    double podatekZaZbytWczesneZakonczenie;
    void setMiesiecznaWplata(double miesiecznaWplata);
    void setOprocentowanie(double oprocentowanie);
    void setCzasTrwania(int czasTrwania);
    void setPodatekZaZbytWczesneZakonczenie(double podatekZaZbytWczesneZakonczenie);
public:
    IKE(std::string opis, double wartosc, double miesiecznaWplata, double oprocentowanie, int czasTrwania, double podatekZaZbytWczesneZakonczenie);
    virtual void wyswietlInformacje() override;
    virtual double wartoscWMiesiacu(int miesiac) override;
    virtual void edytuj() override;
    virtual std::string serializuj() override;
};


#endif //PYRAPORTFEL_IKE_H
