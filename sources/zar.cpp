//
// Created by alexandra on 11/20/2020.
//

#include <cstdlib>
#include "../headers/zar.h"

Zar::Zar(){
    nr_fete_zar = 6;
}

int Zar::da_cu_zarul(){

    int nr_poz = 0;
    nr_poz = rand() % nr_fete_zar + 1;

    return nr_poz;
}