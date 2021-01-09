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

void Alta_carte::aleg_card_comunitate() {
    switch(rand()% 5) {
        case 0:
            std::cout << "PRIMESTI $45 DE LA STAT CA AI MATURAT SOSEAUA"<<std::endl;
            this->setPrimescSauPlatesc("primesc");
            this->set_pret(45);
            break;
        case 1:
            std::cout << "IN URMA SEDINTEI DE LA WORLD CLASS AI DE PLATIT $50"<<std::endl;
            this->setPrimescSauPlatesc("platesc");
            this->set_pret(50);
            break;
        case 2:
            std::cout << "PRIMESTI $20 DE LA UN ADMIRATOR SECRET" << std::endl;
            this->setPrimescSauPlatesc("primesc");
            this->set_pret(20);
            break;
        case 3:
            std::cout << "EYY. AI RETRAS BANII LA TIMP, PRIMESTI $100" << std::endl;
            this->setPrimescSauPlatesc("primesc");
            this->set_pret(100);
            break;
        case 4:
            std::cout << "TAXA SCOLARA DE $150" << std::endl;
            this->setPrimescSauPlatesc("platesc");
            this->set_pret(150);
            break;
        default:
            break;
    }
}

void Alta_carte::aleg_card_noroc() {
    switch(rand()% 6) {
        case 0:
            std::cout << "TAXA INVENTATA DE VIORICA: $15"<<std::endl;
            this->setPrimescSauPlatesc("platesc");
            this->set_pret(15);
            break;
        case 1:
            std::cout << "BANCA TE RASPLATESTE CU $50 PENTRU LOIALITATE"<<std::endl;
            this->setPrimescSauPlatesc("primesc");
            this->set_pret(50);
        case 2:
            std::cout << "RAMBURSAREA IMPOZITULUI. COLECTEAZA $20" << std::endl;
            this->setPrimescSauPlatesc("primesc");
            this->set_pret(20);
        case 3:
            std::cout << "TE DUCI DIRECT LA PUSCARIE. NU TRECI PE LA GO, NU PRIMESTI $200" << std::endl;
            this->setPrimescSauPlatesc("stau");
            this->set_pozitie(30);
        case 4:
            std::cout << "CINEVA TI-A DONAT 150$" << std::endl;
            this->setPrimescSauPlatesc("primesc");
            this->set_pret(150);
        case 5:
            std::cout << "DU-TE IN SPATE 3 SPATII"<< std::endl;
            this->setPrimescSauPlatesc("stau");
            if(this->get_pozitie() >= 3)
                this->set_pozitie(this->get_pozitie() - 3);
            else if(this->get_pozitie() == 0)
                this->set_pozitie(37);
            else if(this->get_pozitie() == 1)
                this->set_pozitie(38);
            else if(this->get_pozitie() == 2)
                this->set_pozitie(39);
            break;
        default:
            break;
    }
}
void Alta_carte::aleg_card_gara() {
    this->set_pret(200);
    this->setPrimescSauPlatesc("platesc");
    if(this->get_pozitie() == 5)
        std::cout << "GARA BANEASA" << std::endl;
    else if(this->get_pozitie() == 15)
        std::cout<<"GARA DE NORD"<< std::endl;
    else if(this->get_pozitie() == 25)
        std::cout<<"GARA SINAIA"<< std::endl;
    else if(this->get_pozitie() == 35)
        std::cout<<"GARA PREDEAL"<< std::endl;
}

void Alta_carte::aleg_card_taxa() {
    this->setPrimescSauPlatesc("platesc");
    if(this->get_pozitie() == 4) {
        this->set_pret(200);
        std::cout << "TAXA PE VENIT" << std::endl;
    }
    else if(this->get_pozitie() == 12) {
        this->set_pret(150);
        std::cout << "COMPANIA ELECTRICA. PLATESTI 150$ PENTRU INTERVENTIE" << std::endl;
    }
    else if(this->get_pozitie() == 28) {
        this->set_pret(150);
        std::cout << "APA NU E GRATIS. PLATESTI 150$ PENTRU INTERVENTIE." << std::endl;
    }
    else if(this->get_pozitie() == 38) {
        this->set_pret(100);
        std::cout << "O VIATA LUXOASA NECESITA O TAXA DE 100$" << std::endl;
    }
}

std::string Alta_carte::MesajTest() {
    return "Felicitari ai ajuns pana aici-deriv!";
}


Alta_carte::~Alta_carte() {
}

const std::string &Alta_carte::getPrimescSauPlatesc() const {
    return primesc_sau_platesc;
}

void Alta_carte::setPrimescSauPlatesc(const std::string &primescSauPlatesc) {
    primesc_sau_platesc = primescSauPlatesc;
}

