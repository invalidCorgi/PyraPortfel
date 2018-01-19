//
// Created by wojtekreg on 15.01.18.
//

#ifndef PYRAPORTFEL_PRODUKT_STRUKTURYZOWANY_H
#define PYRAPORTFEL_PRODUKT_STRUKTURYZOWANY_H


#include "Aktywa.h"

class ProduktStrukturyzowany : public Aktywa {
private:
    int czasTrwania;
    double udzialWZyskach;
    double maksymalnyZysk;
    void setCzasTrwania(int czasTrwania);
    void setUdzialWZyskach(double udzialWZyskach);
    void setMaksymalnyZysk(double maksymalnyZysk);
public:
    ProduktStrukturyzowany(std::string opis, double wartosc, int czasTrwania, double udzialWZyskach, double maksymalnyZysk);
    virtual void wyswietlInformacje() override;
    virtual double wartoscWMiesiacu(int miesiac) override;
    virtual void edytuj() override;
    virtual std::string serializuj() override;
};


#endif //PYRAPORTFEL_PRODUKT_STRUKTURYZOWANY_H
