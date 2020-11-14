//
// Created by alexandra on 11/11/2020.
//

#ifndef TEMA_BANCA_H
#define TEMA_BANCA_H

#include <iostream>
#include <vector>
class Banca {
    int nr_card;
    std::string nume;
    float suma_pe_card;
public:
    void depunere();
    void retragere();
    void afisare();
};

void Banca::depunere() {
    int suma_depusa;
    std::cout << "Introdu suma pe care vrei sa o depui:";
    std::cin >> suma_depusa;
    suma_pe_card += suma_depusa;
}

void Banca::retragere() {
    int suma_retrasa;
    std::cout << "Introdu suma pe care vrei sa o retragi: ";
    std::cin >> suma_retrasa;
    suma_pe_card -= suma_retrasa;
}

void Banca::afisare() {
    std::cout << "\n---------------";
    std::cout << "\n Numar card: "<<nr_card;
    std::cout << "\n Nume: " << nume;
    std::cout << "\n Suma totala: " << suma_pe_card;
}

#endif //TEMA_BANCA_H
