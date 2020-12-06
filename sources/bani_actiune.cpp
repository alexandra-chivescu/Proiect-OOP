//
// Created by alexandra on 11/20/2020.
//
#include<iostream>
#include "../headers/bani_actiune.h"
#include "../headers/rlutil.h"
void Bani_actiune::cumpara_de_la_banca(Jucator& cumparator, Banca& banca,Proprietate& proprietate, std::string choice) {
    try {
        if (choice == "da") {
            cumparator.da_bani(proprietate.get_pret());
            banca.primeste_bani(proprietate.get_pret());
            proprietate.set_id(cumparator.get_id());
            proprietate.set_stadiu('i');
        } else if (choice == "nu") {
            cumparator.da_bani(proprietate.get_pret_chirie());
            banca.primeste_bani(proprietate.get_pret_chirie());
        }
        else {
            throw choice;
        }
    } catch (std::string bad_choice) {
        std::cout << "Nu ai introdus un raspuns exact, deci vom continua." <<std::endl;
    }
}

void Bani_actiune::inchiriaza_de_la_jucator(Jucator& chirias, Jucator& proprietar,Proprietate& proprietate) {
    chirias.da_bani(proprietate.get_pret_chirie());
    proprietar.primeste_bani(proprietate.get_pret_chirie());
}

void Bani_actiune::alte_carduri_interact(Jucator &jucator, Banca &banca, Alta_carte &alta_carte, std::string actiune_jucator) {
    if(actiune_jucator == "primesc") {
        rlutil::setColor(14);
        std::cout<<"Ai primit "<< alta_carte.get_pret() <<"$ "<< std::endl;
        jucator.primeste_bani(alta_carte.get_pret());
        banca.da_bani(alta_carte.get_pret());
    }
    else  if(actiune_jucator == "platesc") {
        rlutil::setColor(4);
        std::cout<<"Ai platit "<< alta_carte.get_pret() <<"$ "<< std::endl;
        jucator.da_bani(alta_carte.get_pret());
        banca.primeste_bani(alta_carte.get_pret());
    }
    else if(actiune_jucator == "stau") {
        rlutil::setColor(0);
        std::cout << "Ramai cu aceeasi suma de bani"<<std::endl;
    }
}

Bani_actiune::~Bani_actiune() = default;