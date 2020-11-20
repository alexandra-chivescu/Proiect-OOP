//
// Created by alexandra on 11/20/2020.
//
#include<iostream>
#include "../headers/bani_actiune.h"
void Bani_actiune::cumpara_de_la_banca(Jucator& cumparator, Banca& banca,Proprietate& proprietate, std::string choice) {
    if(choice == "da") {
        cumparator.da_bani(proprietate.get_pret_vanzare());
        banca.primeste_bani(proprietate.get_pret_vanzare());
        proprietate.set_id(cumparator.get_id());
        proprietate.set_stadiu('i');
    } else if(choice == "nu") {
        cumparator.da_bani(proprietate.get_pret_chirie());
        banca.primeste_bani(proprietate.get_pret_chirie());
    } //aici urmeaza sa completez cu choice != da/nu => Mai introdu o data ce vrei sa faci
}

void Bani_actiune::inchiriaza_de_la_jucator(Jucator& chirias, Jucator& proprietar,Proprietate& proprietate) {
    chirias.da_bani(proprietate.get_pret_chirie());
    proprietar.primeste_bani(proprietate.get_pret_chirie());
}