//
// Created by alexandra on 11/20/2020.
//

#ifndef TEMA_JOC_H
#define TEMA_JOC_H

#include <iostream>
#include <vector>
#include "bani_actiune.h"
#include "banca.h"
#include "alt_spatiu.h"

class Joc {
    std::vector<Jucator> jucatori;
    std::vector<Proprietate> proprietati;
    std::vector<Alta_carte> carti;
    int nr_runde = 3;
public:
    void start();

    ~Joc();

    void find_winner(int nr_jucatori, int nr_proprietati, const Banca &banca);

    void init(std::ifstream &alt, std::ifstream &juc, std::ifstream &pr, int &nr_jucatori, int &nr_proprietati,
              int &nr_alte_carti);
};

#endif //TEMA_JOC_H
