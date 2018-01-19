//
// Created by wojtekreg on 15.01.18.
//

#ifndef PYRAPORTFEL_AKTYWA_H
#define PYRAPORTFEL_AKTYWA_H

#include <iostream>


class Aktywa {
private:
    std::string opis;
    double wartosc;
protected:
    void setOpis(std::string opis);
    void setWartosc(double wartosc);
    std::string getOpis();
    double getWartosc();
public:
    Aktywa(std::string opis, double wartosc);
    virtual void wyswietlInformacje()=0;
    virtual double wartoscWMiesiacu(int miesiac)=0;
    virtual void edytuj()=0;
    virtual std::string serializuj();
};


#endif //PYRAPORTFEL_AKTYWA_H
