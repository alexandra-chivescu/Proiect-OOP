//
// Created by alexandra on 10/19/2020.
//

#ifndef TEMA_PROPRIETATE_H
#define TEMA_PROPRIETATE_H

#include <iostream>
#include <vector>

class Proprietate {
    std::string culoare, nume;
    char stadiu; ///v-vanzare; i-inchiriat
    int pret, id; ///id = 0 inseama ca apartine bancii

public:

    void dateProprietate();

};

void Proprietate::dateProprietate() {
    std::cout<< "Proprietatea " << nume << " se afla in zona " << culoare <<" si este de " << stadiu << "la pretul de" << pret << "$.";
}

#endif //TEMA_PROPRIETATE_H
