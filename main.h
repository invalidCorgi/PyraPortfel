//
// Created by wojtas on 1/16/18.
//

#ifndef PYRAPORTFEL_MAIN_H
#define PYRAPORTFEL_MAIN_H

#include "IKE.h"
#include "Kontrakt.h"
#include "Lokata.h"
#include "Nieruchomosc.h"
#include "ProduktStrukturyzowany.h"

void wyswietlMenu();
void wyswietlMozliweAktywaDoStworzenia();
IKE* tworzenieIKE();
Kontrakt* tworzenieKontraktu();
Lokata* tworzenieLokaty();
Nieruchomosc* tworzenieNieruchomosci();
ProduktStrukturyzowany* tworzenieProduktuStrukturyzowanego();

#endif //PYRAPORTFEL_MAIN_H
