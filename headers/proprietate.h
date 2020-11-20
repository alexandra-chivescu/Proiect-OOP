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
    int pret_chirie, pret_vanzare, id; ///id = 0 inseama ca apartine bancii

public:
    Proprietate(int);

    Proprietate(std::string, std::string, int, int);

    void dateProprietate();

    std::string get_nume();
    std::string get_culoare();
    char get_stadiu();
    int get_pret_chirie();
    int get_pret_vanzare();
    int get_id();

    void set_nume(std::string nume);
    void set_culoare(std::string culoare);
    void set_stadiu(char stadiu);
    void set_pret_chirie(int pret);
    void set_pret_vanzare(int pret);
    void set_id(int id);

    friend std::istream& operator>>(std::istream&, Proprietate&);
    friend std::ostream& operator<<(std::ostream&, const Proprietate&);

    bool operator==(Proprietate&);

    ~Proprietate();

};
#endif //TEMA_PROPRIETATE_H
