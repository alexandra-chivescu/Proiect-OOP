//
// Created by alexandra on 10/19/2020.
//

#ifndef TEMA_SPATIU_PROPRIETATE_H
#define TEMA_SPATIU_PROPRIETATE_H

#include <iostream>
#include <vector>
#include "spatiu_joc.h"

class Proprietate : public Spatiu_joc {
    std::string culoare;
    char stadiu; ///v-vanzare; i-inchiriat
    int pret_chirie; ///id = 0 inseama ca apartine bancii

public:
    Proprietate();

    std::string get_culoare();
    char get_stadiu();
    int get_pret_chirie();

    void set_culoare(std::string culoare);
    void set_stadiu(char stadiu);
    void set_pret_chirie(int pret);

    friend std::istream& operator>>(std::istream&, Proprietate&);
    friend std::ostream& operator<<(std::ostream&, const Proprietate&);

    bool operator==(Proprietate&);

    ~Proprietate();

};
#endif //TEMA_SPATIU_PROPRIETATE_H
