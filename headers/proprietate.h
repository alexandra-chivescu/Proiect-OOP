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

    void afisare_proprietati(std::string, std::string, char, int, int, int);

    bool operator==(Proprietate&);

    ~Proprietate();

};

Proprietate::Proprietate(std::string nume, std::string culoare, int pret_chirie, int pret_vanzare) {
    stadiu = 'v';
    id = 0;
    this->nume = nume;
    this->culoare = culoare;
    this->pret_chirie = pret_chirie;
    this->pret_vanzare = pret_vanzare;
}

void Proprietate::dateProprietate() {
    if(stadiu == 'i')
        std::cout<< "Proprietatea " << nume << " se afla in zona " << culoare <<" si este de vanzare la pretul de" << pret_vanzare << "$.";
    else
        std::cout<< "Proprietatea " << nume << " se afla in zona " << culoare <<" si este de inchiriat la pretul de" << pret_chirie << "$.";
}

std::string Proprietate::get_nume() {
    return nume;
}

std::string Proprietate::get_culoare() {
    return culoare;
}

char Proprietate::get_stadiu() {
    return stadiu;
}

int Proprietate::get_pret_chirie() {
    return  pret_chirie;
}

int Proprietate::get_pret_vanzare() {
    return  pret_vanzare;
}


int Proprietate::get_id() {
    return id;
}

void Proprietate::set_nume(std::string nume) {
    this->nume = nume;
}

void Proprietate::set_culoare(std::string culoare) {
    this->culoare = culoare;
}

void Proprietate::set_stadiu(char stadiu) {
    this->stadiu = stadiu;
}

void Proprietate::set_pret_chirie(int pret_chirie) {
    this->pret_chirie = pret_chirie;
}

void Proprietate::set_pret_vanzare(int pret_vanzare) {
    this->pret_vanzare = pret_vanzare;
}

void Proprietate::set_id(int id) {
    this->id = id;
}

void afisare_proprietati(std::string nume, std::string culoare, char stadiu, int pret_chirie, int pret_vanzare, int id) {
    if(id == 0) {
        if(stadiu == 'v')
        {
            std::cout<<"Proprietatea " << nume << " se afla in zona " << culoare << " , stadiu de vanzare, la pretul de " << pret_vanzare << "$ si apartine bancii." << std::endl;
        }
    }
}

bool Proprietate::operator==(Proprietate & alta_proprietate) {
    return this->get_id() == alta_proprietate.get_id();
}
Proprietate::~Proprietate() {
    //std::cout <<"S-a terminat jocul. Speram sa avem mai multe proprietati in realitate :). "<< std::endl;
}

#endif //TEMA_PROPRIETATE_H
