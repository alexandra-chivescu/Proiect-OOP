//
// Created by alexandra on 11/20/2020.
//

#ifndef TEMA_BANI_ACTIUNE_H
#define TEMA_BANI_ACTIUNE_H
#include <iostream>
#include "jucator.h"
#include "banca.h"
class Bani_actiune {
public:
    void cumpara_de_la_jucator(Jucator cumparator, Jucator proprietar, int suma);
    void inchiriaza_de_la_jucator(Jucator chirias, Jucator proprietar, int suma);
    void cumpara_de_la_banca(Jucator cumparator, Banca banca, int suma);
    void inchiriaza_de_la_banca(Jucator chirias, Banca banca, int suma);

};

#endif //TEMA_BANI_ACTIUNE_H
