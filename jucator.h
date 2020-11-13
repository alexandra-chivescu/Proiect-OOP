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

    Jucator(std::string, int, int);
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
Jucator::Jucator(std::string nume, int bani_card, int id) {
    this->nume = nume;
    this->bani_card = bani_card;
    this->id = id;
}

Jucator::~Jucator() {
    std::cout << "Jucatorul " << nume << "a abandonat jocul.";
}
#endif //TEMA_JUCATOR_H
