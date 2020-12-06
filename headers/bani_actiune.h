//
// Created by alexandra on 11/20/2020.
//

#ifndef TEMA_BANI_ACTIUNE_H
#define TEMA_BANI_ACTIUNE_H
#include <iostream>
#include "jucator.h"
#include "banca.h"
#include "spatiu_proprietate.h"
#include "alt_spatiu.h"
class Bani_actiune {
public:
    void inchiriaza_de_la_jucator(Jucator& chirias, Jucator& proprietar,Proprietate& proprietate);
    void cumpara_de_la_banca(Jucator& cumparator, Banca& banca,Proprietate& proprietate, std::string choice);

    void alte_carduri_interact(Jucator& jucator, Banca &banca, Alta_carte &alta_carte, std::string);

    ~Bani_actiune();
};

#endif //TEMA_BANI_ACTIUNE_H
