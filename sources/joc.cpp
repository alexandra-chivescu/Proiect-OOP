//
// Created by alexandra on 11/20/2020.
//
#include<iostream>
#include <fstream>
#include "../headers/jucator.h"
#include "../headers/spatiu_proprietate.h"
#include "../headers/joc.h"
#include "../headers/zar.h"
#include "../headers/rlutil.h"

void Joc::start() {
    std::ifstream juc("../fisiere/jucatori.txt");
    std::ifstream pr("../fisiere/proprietate.txt");
    std::ifstream alt("../fisiere/alte_carti.txt");
    int nr_jucatori;
    int nr_proprietati;
    int nr_alte_carti;
    init(alt, juc, pr, nr_jucatori, nr_proprietati, nr_alte_carti);

    // momentan pun nr. de runde ca să se oprească jocul
    Zar zar;
    Bani_actiune bani_actiune;
    Banca banca;
    std::vector<int> indici_eliminare;
    while (nr_runde--) {
        for (auto &jucator : jucatori) {
            //Jucatorul da cu zarul
            try {
                int bani_pe_card = jucator.get_bani_card();
                if (bani_pe_card <= 0)
                    throw (bani_pe_card);
            } catch (int bani_card) {
                std::cout << "Trebuie sa ai bani pe card pentru a juca. Esti pe minus cu " << bani_card
                          << ". Ne pare rau, parasesti jocul";
                indici_eliminare.push_back(jucator.get_id());
            }
            int nr_poz_inaintare = zar.da_cu_zarul();
            //Jucatorul inainteaza pe o pozitie
            if (jucator.get_pozitie() + nr_poz_inaintare >= 39)
                jucator.set_pozitie(jucator.get_pozitie() + nr_poz_inaintare -
                                    40); //pentru ca jucatorul poate face mai multe ture de tabla
            else
                jucator.set_pozitie(jucator.get_pozitie() + nr_poz_inaintare);
            std::cout << "Jucatorul : " << jucator.get_nume() << " a avansat la pozitia: " << jucator.get_pozitie()
                      << std::endl;

            //Aflu pe pozitia respectiva ce am proprietate sau altceva
            int pozitie = jucator.get_pozitie();
            int exista_pozitia = 0;
            int nr_proprietate;
            for (int i = 0; i < nr_proprietati; ++i) {
                if (proprietati[i].get_pozitie() == pozitie) {
                    exista_pozitia = 1;
                    nr_proprietate = i;
                    break;
                }
            }
            if (exista_pozitia == 1) {
                ///Proprietatea apartine bancii
                int id_proprietate = proprietati[nr_proprietate].get_id();
                if (id_proprietate == 0) {
                    std::cout << "Proprietatea apartine bancii." << std::endl;
                    std::cout << "Vrei sa o cumperi? da/nu ";
                    std::string choice;
                    std::cin >> choice;
                    bani_actiune.cumpara_de_la_banca(jucator, banca, proprietati[jucator.get_pozitie()], choice);
                } else { ///Proprietatea apartine unui jucator
                    int i;
                    for (i = 0; i < nr_jucatori; ++i) {
                        if (jucatori[i].get_id() == id_proprietate) {
                            break;
                        }
                    }
                    std::cout << "Proprietatea apartine lui: " << jucatori[i].get_nume()
                              << ". Aici se va percepe o chirie de "
                              << proprietati[jucator.get_pozitie()].get_pret_chirie() << "$. " << std::endl;
                    bani_actiune.inchiriaza_de_la_jucator(jucator, jucatori[i], proprietati[jucator.get_pozitie()]);
                }
            } else {
                int nr_carte = 0;
                for (int i = 0; i < nr_alte_carti; ++i) {
                    if (carti[i].get_pozitie() == pozitie) {
                        nr_carte = i;
                        break;
                    }
                }
                std::cout << "Te afli in : " << std::endl;
                carti[nr_carte].aleg_card();

                ///Aici verific daca jucatorul trebuie sa primeasca sau sa plateasca bani
                bani_actiune.alte_carduri_interact(jucator, banca, carti[nr_carte],
                                                   carti[nr_carte].getPrimescSauPlatesc());
                rlutil::setColor(3);
            }
        }
        if (indici_eliminare.size() > 0) {
            for (int i = 0; i < indici_eliminare.size(); i++) {
                if(jucatori[i].get_id() == indici_eliminare[i])
                    jucatori.erase(jucatori.begin() + i);
            }
        }
    }

///    std::cout<<"Situatia finala a proprietatilor de pe tabla: "<<std::endl;
//    for(int i = 0 ; i < nr_proprietati; i++)
//    {
//        if(proprietati[i].get_stadiu() == 'v')
//            std::cout << proprietati[i].get_nume() << ": stadiu- vanzare & id- " << proprietati[i].get_id() << std::endl;
//        else
//            std::cout << proprietati[i].get_nume() << ": stadiu- inchiriat & id- " << proprietati[i].get_id() << std::endl;
//    }

    ///Verific cine a castigat
    find_winner(nr_jucatori, nr_proprietati, banca);

    ///Verificare functie virtuala
    std::cout << "\n---------Fct virtuala----------\n";
    test_virtual();

    juc.close();
    pr.close();
}


void Joc::init(std::ifstream &alt, std::ifstream &juc, std::ifstream &pr, int &nr_jucatori, int &nr_proprietati,
               int &nr_alte_carti) {
    juc >> nr_jucatori;
    rlutil::setColor(3);
    std::cout << "--------------START GAME--------------" << std::endl;
    std::cout << "--------------Detalii joc--------------" << std::endl;
    std::cout << "--------------Jucatori--------------" << std::endl;
    std::cout << "Numarul de jucatori este: " << nr_jucatori << "\n";

    for (int i = 0; i < nr_jucatori; ++i) {
        Jucator jucator_nou(i + 1);
        juc >> jucator_nou;
        jucatori.push_back(jucator_nou);
    }
    pr >> nr_proprietati;

    for (int i = 0; i < nr_proprietati; ++i) {
        Proprietate proprietate_noua;
        pr >> proprietate_noua;
        proprietati.push_back(proprietate_noua);
    }
    alt >> nr_alte_carti;
    for (int i = 0; i < nr_alte_carti; ++i) {
        Alta_carte alta_carte;
        alt >> alta_carte;
        carti.push_back(alta_carte);
    }
}

void Joc::find_winner(int nr_jucatori, int nr_proprietati, const Banca &banca) {
    int avere_jucator[nr_jucatori];
    for (int i = 0; i < nr_jucatori; ++i) {
        avere_jucator[i] = 0;
    }
    for (int i = 0; i < nr_proprietati; ++i) {
        for (int j = 0; j < nr_jucatori; ++j) {
            if (proprietati[i].get_id() == jucatori[j].get_id()) {
                avere_jucator[j] = avere_jucator[j] + proprietati[i].get_pret();
                break;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < nr_jucatori; i++) {
        if (jucatori[i].get_bani_card() + avere_jucator[i] > max)
            max = jucatori[i].get_bani_card() + avere_jucator[i];
    }
    int count_winners = 1;
    for (int i = 0; i < nr_jucatori; i++) {
        if (jucatori[i].get_bani_card() + avere_jucator[i] == max) {
            count_winners++;
        }
    }
    rlutil::setColor(13);
    int first_time = 1;
    for (int i = 0; i < jucatori.size(); ++i) {
        if (jucatori[i].get_bani_card() + avere_jucator[i] == max && count_winners == 1 && jucatori[i].get_bani_card()> 0) {
            std::cout << "Castigatorul este: " << jucatori[i].get_nume() << " cu o avere de "
                      << jucatori[i].get_bani_card() + avere_jucator[i] << " $." << std::endl;
        } else {
            if (first_time == 1 && jucatori[i].get_bani_card()> 0 ) {
                std::cout << "Castigatorii cu suma de " << jucatori[i].get_bani_card() + avere_jucator[i] << " $ sunt: "
                          << std::endl;
            }
            std::cout << jucatori[i].get_nume() << std::endl;
            first_time = 0;
        }
    }
    std::cout << "Banca este adevaratul castigator cu: " << banca.suma_bani << "$ in cont.";
}

void Joc::test_virtual() {
    Alta_carte *altaCarte = new Alta_carte();
    Spatiu_joc *sp = altaCarte;
    std::cout << altaCarte->MesajTest();
    std::cout << sp->MesajTest();
}

Joc::~Joc() = default;
