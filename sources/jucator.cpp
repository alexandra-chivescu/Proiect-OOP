//
// Created by alexandra on 11/20/2020.
//
#include<iostream>
#include "../headers/jucator.h"

Jucator::Jucator(int id_curent) {
    id= id_curent;
    pozitie = 0;
}
std::string Jucator::get_nume() {
    return nume;
}
int Jucator::get_bani_card() {
    return bani_card;
}
int Jucator::get_id() {
    return id;
}
int Jucator::get_pozitie() {
    return pozitie;
}

void Jucator::set_nume(std::string nume) {
    this->nume = nume;
}
void Jucator::set_bani_card(int bani_card) {
    this->bani_card = bani_card;
}
void Jucator::set_id(int id) {
    this->id = id;
}
void Jucator:: set_pozitie(int pozitie) {
    this->pozitie = pozitie;
}

std::istream& operator>>(std::istream& in, Jucator& jucator) {
    in >> jucator.nume;
    in >> jucator.bani_card;
    return in;
}

std::ostream& operator<<(std::ostream& out, Jucator& jucator) {
    out << "Jucatorul " << jucator.nume << " cu id-ul " << jucator.id << " are pe card suma de " << jucator.bani_card<< " $"<<"\n";
    return out;
}


void Jucator::da_bani(int suma) {
    this->bani_card -= suma;
}
void Jucator::primeste_bani(int suma) {
    this->bani_card += suma;
}

Jucator::~Jucator() {
    //std::cout<<"Jucatorul "<< nume << " a iesit din joc. " << std::endl;
}

