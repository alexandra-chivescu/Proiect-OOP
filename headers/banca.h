//
// Created by alexandra on 11/11/2020.
//

#ifndef TEMA_BANCA_H
#define TEMA_BANCA_H

#include <iostream>
#include <vector>
class Banca {
    int suma_bani;
public:
    Banca();

    void primeste_bani(int suma);
    void da_bani(int suma);

    friend class Joc;

    ~Banca();
};
#endif //TEMA_BANCA_H
