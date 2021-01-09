//
// Created by alexandra on 10/19/2020.
//

#ifndef TEMA_JUCATOR_H
#define TEMA_JUCATOR_H

#include <iostream>
#include <vector>

class Jucator {
protected:
    std::string nume;
    int bani_card;
    int id, pozitie;
public:
    Jucator(int);

    std::string get_nume();
    int get_bani_card();
    int get_id();
    int get_pozitie();

    void set_nume(std::string);
    void set_bani_card(int);
    void set_id(int);
    void set_pozitie(int);

    friend std::istream& operator>>(std::istream&, Jucator&);
    friend std::ostream& operator<<(std::ostream&, Jucator&);

    ///op=
    Jucator& operator=(const Jucator& alt_jucator){
        if(this == &alt_jucator)
            return *this;
        else
        {
            nume = alt_jucator.nume;
            bani_card = alt_jucator.bani_card;
            id = alt_jucator.id;
            pozitie = alt_jucator.pozitie;
            return *this;
        }
    };

    ///Copy constructor
    Jucator(const Jucator &juc) {
        nume = juc.nume;
        bani_card = juc.bani_card;
        id = juc.id;
        pozitie = juc.pozitie;
    }

    void da_bani(int suma);
    void primeste_bani(int suma);

    ~Jucator();

};

#endif //TEMA_JUCATOR_H
