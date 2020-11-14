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

    std::vector<Jucator> jucatori;
    std::string nume;
    int bani_card;

    for (int i = 0; i < n; ++i) {
        juc >> nume;
        juc >> bani_card;
        Jucator jucator_nou(nume, bani_card, i+1);
        jucatori.push_back(jucator_nou);
    }

    for (int i = 0; i < n; ++i) {
       afisare_jucatori(jucatori[i].get_nume(), jucatori[i].get_bani_card(), jucatori[i].get_id());
    }

    int nr_proprietati;
    pr>>nr_proprietati;
    std::vector<Proprietate> proprietati;
    std::string culoare, nume_proprietate;
    int pret_chirie, pret_vanzare;

    for (int i = 0; i < nr_proprietati; ++i) {
        pr>>nume_proprietate;
        pr>>culoare;
        pr>>pret_chirie;
        pr>>pret_vanzare;
        Proprietate proprietate_noua(nume_proprietate, culoare, pret_chirie, pret_vanzare);
        proprietati.push_back(proprietate_noua);
    }
    std::cout<<"--------------Proprietati Monopoly--------------"<<std::endl;
    for (int i = 0; i < nr_proprietati; ++i) {
        afisare_proprietati(proprietati[i].get_nume(), proprietati[i].get_culoare(), proprietati[i].get_stadiu(), proprietati[i].get_pret_chirie(), proprietati[i].get_pret_vanzare(), proprietati[i].get_id());
    }

    juc.close();
    pr.close();
    return 0;
}
