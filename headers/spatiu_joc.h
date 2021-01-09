//
// Created by alexandra on 12/5/2020.
//

#ifndef TEMA_CARTE_JOC_H
#define TEMA_CARTE_JOC_H

#include <iostream>
#include <vector>

class Spatiu_joc {
protected:
    std::string nume;
    int pozitie, pret, id;

public:
    Spatiu_joc();

    std::string get_nume();
    int get_pozitie();
    int get_pret();
    int get_id();

    void set_nume(std::string);
    void set_pozitie(int);
    void set_pret(int);
    void set_id(int);

    virtual std::string MesajTest();

    ~Spatiu_joc();
};
#endif //TEMA_CARTE_JOC_H
