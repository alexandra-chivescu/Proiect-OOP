//
// Created by alexandra on 12/5/2020.
//
#include<iostream>
#include "../headers/spatiu_joc.h"

Spatiu_joc::Spatiu_joc() {
    pret = 0;
}

int Spatiu_joc::get_pozitie() {
    return pozitie;
}
std::string Spatiu_joc::get_nume() {
    return nume;
}
int Spatiu_joc::get_pret() {
    return pret;
}
int Spatiu_joc::get_id() {
    return id;
}



void Spatiu_joc::set_pozitie(int pozitie) {
    this->pozitie = pozitie;
}
void Spatiu_joc::set_nume(std::string) {
    this->nume = nume;
}
void Spatiu_joc::set_pret(int pret) {
    this->pret = pret;
}
void Spatiu_joc::set_id(int id) {
    this->id = id;
}

std::string Spatiu_joc::MesajTest() {
        return "Felicitari ai ajuns pana aici-baza!";
}

void Spatiu_joc::aleg_card() {
    std::cout << "Ai ales un card.";
}


Spatiu_joc::~Spatiu_joc() {
}
