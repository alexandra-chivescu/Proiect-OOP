//
// Created by alexandra on 11/20/2020.
//
#include<iostream>
#include <fstream>
#include "../headers/jucator.h"
#include "../headers/spatiu_proprietate.h"
#include "../headers/joc.h"
#include "../headers/zar.h"

void Joc::start() {
    std::ifstream juc("../fisiere/jucatori.txt");
    std::ifstream pr("../fisiere/proprietate.txt");
    std::ifstream alt("../fisiere/alte_carti.txt");
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

    int nr_alte_carti;
    alt>> nr_alte_carti;
    for (int i = 0; i < nr_alte_carti; ++i) {
        Alta_carte alta_carte;
        alt >> alta_carte;
        carti.push_back(alta_carte);
    }
//    std::cout << "--------------Proprietati Monopoly--------------" << std::endl;
//    for (int i = 0; i < nr_proprietati; i++) {
//        std::cout << proprietati[i];
//    }

// momentan punem nr. de runde ca să se oprească jocul
    Zar zar;
    Bani_actiune bani_actiune;
    Banca banca;
    while (nr_runde-- ) {
        for (auto &jucator : jucatori) {
            //Jucatorul da cu zarul
            int nr_poz_inaintare = zar.da_cu_zarul() ;
            //Jucatorul inainteaza pe o pozitie
            if (jucator.get_pozitie() + nr_poz_inaintare >= 39)
                jucator.set_pozitie(jucator.get_pozitie() + nr_poz_inaintare - 40); //pentru ca jucatorul poate face mai multe ture de tabla
            else
                jucator.set_pozitie(jucator.get_pozitie() + nr_poz_inaintare);
            system("Color 05");
            std::cout<<"Jucatorul : "<<jucator.get_nume() << " a avansat la pozitia: " << jucator.get_pozitie()<< std::endl;

            //Aflu pe pozitia respectiva ce am proprietate sau altceva
            int pozitie = jucator.get_pozitie();
            int exista_pozitia = 0;
            int nr_proprietate;
            for (int i = 0; i < nr_proprietati; ++i) {
                if(proprietati[i].get_pozitie() == pozitie) {
                    exista_pozitia = 1;
                    nr_proprietate = i;
                    break;
                }
            }
            if(exista_pozitia == 1) {
                ///Proprietatea apartine bancii
                int id_proprietate = proprietati[nr_proprietate].get_id();
                if (id_proprietate == 0) {
                    system("Color 02");
                    std::cout << "Proprietatea apartine bancii." << std::endl;
                    std::cout << "Vrei sa o cumperi? da/nu ";
                    std::string choice;
                    std::cin >> choice;
                    bani_actiune.cumpara_de_la_banca(jucator, banca, proprietati[jucator.get_pozitie()], choice);
                } else { ///Proprietatea apartine unui jucator
                    int i;
                    for (i = 0; i < n; ++i) {
                        if (jucatori[i].get_id() == id_proprietate) {
                            break;
                        }
                    }
                    system("Color 04");
                    std::cout << "Proprietatea apartine lui: " << jucatori[i].get_nume()
                              << ". Aici se va percepe o chirie de "
                              << proprietati[jucator.get_pozitie()].get_pret_chirie() << "$. " << std::endl;
                    bani_actiune.inchiriaza_de_la_jucator(jucator, jucatori[i], proprietati[jucator.get_pozitie()]);
                    system("Color 04");
                }
            } else {
                int nr_carte = 0;
                for (int i = 0; i < nr_alte_carti; ++i) {
                    if(carti[i].get_pozitie() == pozitie) {
                        nr_carte = i;
                        break;
                    }
                }
                if(carti[nr_carte].get_nume() == "comunitate")
                    carti[nr_carte].get_card_comunitate(carti[nr_carte]);
                else if(carti[nr_carte].get_nume() == "taxa")
                    carti[nr_carte].get_card_taxa(carti[nr_carte]);
                else if(carti[nr_carte].get_nume() == "gara")
                    carti[nr_carte].get_card_gara(carti[nr_carte]);
                else if(carti[nr_carte].get_nume() == "noroc")
                    carti[nr_carte].get_card_noroc(carti[nr_carte]);
                else if(carti[nr_carte].get_nume() == "parcare")
                    std::cout << "FREE PARKING. GRAB A BEER" << std::endl;
                else if(carti[nr_carte].get_nume() == "inchisoare")
                    std::cout<< "PRISON" << std::endl;

                ///Aici verific daca jucatorul trebuie sa primeasca sau sa plateasca
                bani_actiune.alte_carduri_interact(jucator, banca, carti[nr_carte], carti[nr_carte].getPrimescSauPlatesc());
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
    system("Color 01");
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
}

Joc::~Joc() = default;
