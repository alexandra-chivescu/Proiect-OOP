#include <iostream>
#include <vector>
#include <fstream>
#include "headers/jucator.h"
#include "headers/banca.h"
#include "headers/proprietate.h"

int main() {
    std::ifstream juc("../fisiere/jucatori.txt");
    std::ifstream pr("../fisiere/proprietate.txt");
    int n;
    juc >> n;
    std::cout<<"--------------START GAME--------------"<<std::endl;
    std::cout<<"--------------Detalii joc--------------"<<std::endl;
    std::cout<<"--------------Jucatori--------------"<<std::endl;
    std::cout << "Numarul de jucatori este: " << n << "\n";

    std::vector<Jucator> jucator;
    std::string nume;
    int bani_card;

    for (int i = 0; i < n; ++i) {
        juc >> nume;
        juc >> bani_card;
        Jucator jucator_nou(nume, bani_card, i+1);
        jucator.push_back(jucator_nou);
    }

    for (int i = 0; i < n; ++i) {
       afisare_jucatori(jucator[i].get_nume(), jucator[i].get_bani_card(), jucator[i].get_id());
    }

    int nr_proprietati;
    pr>>nr_proprietati;
    std::vector<Proprietate> proprietate;
    std::string culoare, nume_proprietate;
    int pret_chirie, pret_vanzare;

    for (int i = 0; i < nr_proprietati; ++i) {
        pr>>nume_proprietate;
        pr>>culoare;
        pr>>pret_chirie;
        pr>>pret_vanzare;
        Proprietate proprietate_noua(nume_proprietate, culoare, pret_chirie, pret_vanzare);
        proprietate.push_back(proprietate_noua);
    }
    std::cout<<"--------------Proprietati Monopoly--------------"<<std::endl;
    for (int i = 0; i < nr_proprietati; ++i) {
        afisare_proprietati(proprietate[i].get_nume(), proprietate[i].get_culoare(), proprietate[i].get_stadiu(), proprietate[i].get_pret_chirie(), proprietate[i].get_pret_vanzare(), proprietate[i].get_id());
    }

    juc.close();
    pr.close();
    return 0;
}
