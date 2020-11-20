//
// Created by alexandra on 11/20/2020.
//
#include<iostream>
#include <fstream>
#include "../headers/jucator.h"
#include "../headers/proprietate.h"
#include "../headers/joc.h"
#include "../headers/zar.h"

void Joc::start() {
    std::ifstream juc("../fisiere/jucatori.txt");
    std::ifstream pr("../fisiere/proprietate.txt");
    int n;
    juc >> n;
    std::cout << "--------------START GAME--------------" << std::endl;
    std::cout << "--------------Detalii joc--------------" << std::endl;
    std::cout << "--------------Jucatori--------------" << std::endl;
    std::cout << "Numarul de jucatori este: " << n << "\n";

    for (int i = 0; i < n; ++i) {
        Jucator jucator_nou(i + 1);
        juc >> jucator_nou;
        jucatori.push_back(jucator_nou);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << jucatori[i];
    }

    int nr_proprietati;
    pr >> nr_proprietati;

    for (int i = 0; i < nr_proprietati; ++i) {
        Proprietate proprietate_noua(i + 1);
        pr >> proprietate_noua;
        proprietati.push_back(proprietate_noua);
    }
    std::cout << "--------------Proprietati Monopoly--------------" << std::endl;
    for (int i = 0; i < nr_proprietati; i++) {
        std::cout << proprietati[i];
    }
    int nr_runde = 5;
// momentan punem nr. de runde ca să se oprească jocul
    Zar zar;
    while (nr_runde-- ) {
        for (auto &jucator : jucatori) {
// rândul fiecărui jucător; jucătorul are asociată o poziție pe tabla de joc în intervalul [0, proprietati.size())
            int nr_poz_inaintare = zar.da_cu_zarul() ;
            if (jucator.get_pozitie() + nr_poz_inaintare >= proprietati.size())
                jucator.set_pozitie(jucator.get_pozitie() + nr_poz_inaintare - proprietati.size()); //pentru ca jucatorul poate face mai multe ture de tabla
            else
                jucator.set_pozitie(jucator.get_pozitie() + nr_poz_inaintare);
            //std::cout<<"Jucatorul : "<<jucator.get_id() << " -> " << jucator.get_pozitie()<< std::endl;
            if(proprietati[jucator.get_pozitie()].get_stadiu() == 'v' && proprietati[jucator.get_pozitie()].get_id() == 0) //proprietatea apartine bancii
            {
                std::cout<<"Proprietatea apartine bancii." <<std::endl;
                std::cout<<"Apasa 1-cumperi sau 0-continui jocul";
                int choice;
                std::cin>>choice;
                if(choice == 1) {
                    proprietati[jucator.get_pozitie()].set_stadiu('c');
                }
            }
                std::cout << "Jucatorul"<< jucator.get_nume() << "introdu 1-pt a cumpara sau 0-pt a plati chiria si a continua jocul";

// se verifică dacă proprietatea aparține băncii sau unui jucător
// dacă aparține băncii, o cumpără sau o scoate la licitație (parcă așa era)
// altfel, trebuie să plătească chirie
// ulterior, vom adăuga și acele căsuțe cu cards/free pass/jail/start ca subclase de proprietate
        }
   }
    juc.close();
    pr.close();
    return;
}