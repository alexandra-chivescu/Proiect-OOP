//
// Created by alexandra on 11/20/2020.
//
#include<iostream>
#include "../headers/proprietate.h"
Proprietate::Proprietate() {
    stadiu = 'v';
    id = 0;
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

bool Proprietate::operator==(Proprietate & alta_proprietate) {
    return this->get_id() == alta_proprietate.get_id();
}

std::istream& operator>>(std::istream& in, Proprietate& proprietate) {
    in>>proprietate.nume;
    in>>proprietate.culoare;
    in>>proprietate.pret_chirie;
    in>>proprietate.pret_vanzare;
    return in;
}

std::ostream &operator<<(std::ostream &os, const Proprietate &proprietate) {
            os<<"Proprietatea " << proprietate.nume <<" cu id-ul "<< proprietate.id<< " se afla in zona " << proprietate.culoare << " , stadiu de vanzare, la pretul de " << proprietate.pret_vanzare << "$ si apartine bancii." << std::endl;
    return os;
}

Proprietate::~Proprietate() {
    //std::cout <<"S-a terminat jocul. Speram sa avem mai multe proprietati in realitate :). "<< std::endl;
}