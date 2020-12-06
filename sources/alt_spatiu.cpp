//
// Created by alexandra on 12/5/2020.
//
#include<iostream>
#include "../headers/alt_spatiu.h"

std::istream& operator>>(std::istream& in, Alta_carte& alta_carte) {
    in>>alta_carte.nume;
    in>>alta_carte.pozitie;
    return in;
}

std::ostream &operator<<(std::ostream &os, const Alta_carte& alta_carte) {
    os<<"Cartea random de tip  " << alta_carte.nume <<"se afla pe pozitia " << alta_carte.pozitie;
    return os;
}

void Alta_carte::get_card_comunitate(Alta_carte &alta_carte) {
    switch(rand()% 5) {
        case 0:
            std::cout << "FROM SALE OF STOCK YOU GET $45"<<std::endl;
            alta_carte.setPrimescSauPlatesc("primesc");
            alta_carte.set_pret(45);
            break;
        case 1:
            std::cout << "DOCTOR'S FEE PAY $50"<<std::endl;
            alta_carte.setPrimescSauPlatesc("platesc");
            alta_carte.set_pret(50);
            break;
        case 2:
            std::cout << "INCOME TAX REFUND COLLECT $20" << std::endl;
            alta_carte.setPrimescSauPlatesc("primesc");
            alta_carte.set_pret(20);
            break;
        case 3:
            std::cout << "CHRISTMAS FUND MATURES COLLECT $100" << std::endl;
            alta_carte.setPrimescSauPlatesc("primesc");
            alta_carte.set_pret(100);
            break;
        case 4:
            std::cout << "PAY SCHOOL TAX OF $150" << std::endl;
            alta_carte.setPrimescSauPlatesc("platesc");
            alta_carte.set_pret(150);
            break;
        default:
            break;
    }
}

void Alta_carte::get_card_noroc(Alta_carte &alta_carte) {
    switch(rand()% 6) {
        case 0:
            std::cout << "PAY POOR TAX OF $15"<<std::endl;
            alta_carte.setPrimescSauPlatesc("platesc");
            alta_carte.set_pret(15);
            break;
        case 1:
            std::cout << "BANK PAYS YOU DIIVIDENT OF $50"<<std::endl;
            alta_carte.setPrimescSauPlatesc("primesc");
            alta_carte.set_pret(50);
        case 2:
            std::cout << "INCOME TAX REFUND COLLECT $20" << std::endl;
            alta_carte.setPrimescSauPlatesc("primesc");
            alta_carte.set_pret(20);
        case 3:
            std::cout << "GO DIRECTLY TO JAIL. DO NOT PASS GO, DO NOT COLLECT $200" << std::endl;
            alta_carte.setPrimescSauPlatesc("stau");
            alta_carte.set_pozitie(0);
        case 4:
            std::cout << "YOUR BUILDING AND LOAN MATURES" << std::endl;
            alta_carte.setPrimescSauPlatesc("primesc");
            alta_carte.set_pret(150);
        case 5:
            std::cout << "GO BACK 3 SPACES"<< std::endl;
            alta_carte.setPrimescSauPlatesc("stau");
            if(alta_carte.get_pozitie() >= 3)
                alta_carte.set_pozitie(alta_carte.get_pozitie() - 3);
            else if(alta_carte.get_pozitie() == 0)
                alta_carte.set_pozitie(37);
            else if(alta_carte.get_pozitie() == 1)
                alta_carte.set_pozitie(38);
            else if(alta_carte.get_pozitie() == 2)
                alta_carte.set_pozitie(39);
            break;
        default:
            break;
    }
}
void Alta_carte::get_card_gara(Alta_carte &alta_carte) {
    alta_carte.set_pret(200);
    alta_carte.setPrimescSauPlatesc("platesc");
    if(alta_carte.get_pozitie() == 5)
        std::cout << "GARA BANEASA" << std::endl;
    else if(alta_carte.get_pozitie() == 15)
        std::cout<<"GARA DE NORD"<< std::endl;
    else if(alta_carte.get_pozitie() == 25)
        std::cout<<"GARA SINAIA"<< std::endl;
    else if(alta_carte.get_pozitie() == 35)
        std::cout<<"GARA PREDEAL"<< std::endl;
}

void Alta_carte::get_card_taxa(Alta_carte &alta_carte) {
    alta_carte.setPrimescSauPlatesc("platesc");
    if(alta_carte.get_pozitie() == 4) {
        alta_carte.set_pret(200);
        std::cout << "INCOME TAX" << std::endl;
    }
    else if(alta_carte.get_pozitie() == 12) {
        alta_carte.set_pret(150);
        std::cout << "ELECTRIC COMPANY" << std::endl;
    }
    else if(alta_carte.get_pozitie() == 28) {
        alta_carte.set_pret(150);
        std::cout << "WATER WORKS" << std::endl;
    }
    else if(alta_carte.get_pozitie() == 38) {
        alta_carte.set_pret(100);
        std::cout << "LUXURY TAX" << std::endl;
    }
}

Alta_carte::~Alta_carte() {
}

const std::string &Alta_carte::getPrimescSauPlatesc() const {
    return primesc_sau_platesc;
}

void Alta_carte::setPrimescSauPlatesc(const std::string &primescSauPlatesc) {
    primesc_sau_platesc = primescSauPlatesc;
}

