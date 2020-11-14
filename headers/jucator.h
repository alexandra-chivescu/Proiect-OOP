//
// Created by alexandra on 10/19/2020.
//

#ifndef TEMA_JUCATOR_H
#define TEMA_JUCATOR_H

#include <iostream>
#include <vector>

class Jucator {

    std::string nume;
    int bani_card;
    int id;
public:
    Jucator();

    std::string get_nume();
    int get_bani_card();
    int get_id();

    void set_nume(std::string);
    void set_bani_card(int);
    void set_id(int);

    friend std::istream& operator>>(std::istream&, Jucator&);
    friend std::ostream& operator<<(std::ostream&, Jucator&);

    Jucator(std::string, int, int);

    void afisare_jucatori(std::string, int, int);
    ~Jucator();

};

std::string Jucator::get_nume() {
    return nume;
}
int Jucator::get_bani_card() {
    return bani_card;
}
int Jucator::get_id() {
    return id;
}
void Jucator::set_nume(std::string nume) {
    this->nume = nume;
}
void Jucator::set_bani_card(int bani_card) {
    this->bani_card = bani_card;
}
void Jucator::set_id(int id) {
    this->id = id;
}

std::istream& operator>>(std::istream& in, Jucator& jucator) {
    in >> jucator.nume;
    in >> jucator.bani_card;
    in >> jucator.id;
    return in;
}

std::ostream& operator<<(std::ostream& out, Jucator& jucator) {
    out << "Jucatorul mai are " <<jucator.bani_card << " $ pe card." <<std::endl;
    return out;
}

Jucator::Jucator(std::string nume, int bani_card, int id) {
    this->nume = nume;
    this->bani_card = bani_card;
    this->id = id;
}

void afisare_jucatori(std::string nume, int bani_card, int id) {
    std::cout << "Jucatorul " << nume << " cu id-ul " << id << " are pe card suma de " << bani_card<< " $"<<"\n";
}

Jucator::~Jucator() {
    //std::cout<<"Jucatorul "<< nume << " a iesit din joc. " << std::endl;
}

#endif //TEMA_JUCATOR_H
