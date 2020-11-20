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

//    for (int i = 0; i < n; ++i) {
//        std::cout << jucatori[i];
//    }

    int nr_proprietati;
    pr >> nr_proprietati;

    for (int i = 0; i < nr_proprietati; ++i) {
        Proprietate proprietate_noua;
        pr >> proprietate_noua;
        proprietati.push_back(proprietate_noua);
    }
//    std::cout << "--------------Proprietati Monopoly--------------" << std::endl;
//    for (int i = 0; i < nr_proprietati; i++) {
//        std::cout << proprietati[i];
//    }

    int nr_runde = 3;
// momentan punem nr. de runde ca să se oprească jocul
    Zar zar;
    Bani_actiune bani_actiune;
    Banca banca;
    while (nr_runde-- ) {
        for (auto &jucator : jucatori) {
// rândul fiecărui jucător; jucătorul are asociată o poziție pe tabla de joc în intervalul [0, proprietati.size())
            int nr_poz_inaintare = zar.da_cu_zarul() ;
            if (jucator.get_pozitie() + nr_poz_inaintare >= proprietati.size())
                jucator.set_pozitie(jucator.get_pozitie() + nr_poz_inaintare - proprietati.size()); //pentru ca jucatorul poate face mai multe ture de tabla
            else
                jucator.set_pozitie(jucator.get_pozitie() + nr_poz_inaintare);
            std::cout<<"Jucatorul : "<<jucator.get_nume() << " a avansat la pozitia: " << jucator.get_pozitie()<< std::endl;
            ///Proprietatea apartine bancii
            int id_proprietate =  proprietati[jucator.get_pozitie()].get_id();
            if(id_proprietate == 0)
            {
                std::cout<<"Proprietatea apartine bancii." <<std::endl;
                std::cout<<"Vrei sa o cumperi? da/nu ";
                std::string choice;
                std::cin>>choice;
                bani_actiune.cumpara_de_la_banca(jucator, banca, proprietati[jucator.get_pozitie()], choice);
            } else { ///Proprietatea apartine unui chirias
                int i;
                for ( i = 0; i < n; ++i) {
                    if(jucatori[i].get_id() == proprietati[jucator.get_pozitie()].get_id()) {
                        break;
                    }
                }
                std::cout<<"Proprietatea apartine lui: "<< jucatori[i].get_nume()<< ". Aici se va percepe o chirie." << std::endl;
                    bani_actiune.inchiriaza_de_la_jucator(jucator, jucatori[i], proprietati[jucator.get_pozitie()]);
            }


        }
   }

    ///Verific cine a castigat
    int max = 0;
    for(int i = 0 ; i < n; i++)
    {
        if( jucatori[i].get_bani_card() > max)
            max = jucatori[i].get_bani_card();
    }
    std::cout<<"Situatia finala a proprietatilor de pe tabla: "<<std::endl;
    for(int i = 0 ; i < nr_proprietati; i++)
    {
        if(proprietati[i].get_stadiu() == 'v')
            std::cout << proprietati[i].get_nume() << ": stadiu- vanzare & id- " << proprietati[i].get_id() << std::endl;
        else
            std::cout << proprietati[i].get_nume() << ": stadiu- inchiriat & id- " << proprietati[i].get_id() << std::endl;
    }
    for(int i = 0 ; i < n; i++)
    {
        if( jucatori[i].get_bani_card() == max)
            std::cout<<"Cei mai multi bani pe card ii are: "<< jucatori[i].get_nume() <<": "<< jucatori[i].get_bani_card() <<"$."<< std::endl;
    }
    std::cout << "Banca este adevaratul castigator cu: "<<banca.suma_bani << "$ in cont.";
        // ulterior, vom adăuga și acele căsuțe cu cards/free pass/jail/start ca subclase de proprietate
    juc.close();
    pr.close();
    return;
}
