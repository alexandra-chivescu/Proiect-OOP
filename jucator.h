//
// Created by alexandra on 10/19/2020.
//

#ifndef TEMA_JUCATOR_H
#define TEMA_JUCATOR_H

#include <iostream>
#include <vector>
#include <unordered_map>

class Jucator {
    std::string nume;
    int baniCard;
    //std::unordered_map<std::string, int> umap;
    std::vector<std::string> proprietati;
    ///Proprietate p;
public:

    Jucator();

    const std::string &getNume() const;

    void setNume(const std::string &nume);

    int getBaniCard() const;

    void setBaniCard(int baniCard);

//    std::unordered_map<std::string, int> listaProprietati(std::string proprietati) {
//        umap[proprietati] = count ++;
//        return umap;
//    }

    void listaProprietati(std::string &proprietate) {
        proprietati.push_back(proprietate);
    }

    std::vector<std::string> listaProprietati() {
        return proprietati;
    }

    Jucator(const std::string &nume, int baniCard, const char *proprietati);

    virtual ~Jucator();
};
Jucator ::Jucator() {
    baniCard = 0;
}
const std::string &Jucator::getNume() const {
    return nume;
}

void Jucator::setNume(const std::string &nume) {
    Jucator::nume = nume;
}

int Jucator::getBaniCard() const {
    return baniCard;
}

void Jucator::setBaniCard(int baniCard) {
    Jucator::baniCard = baniCard;
}

Jucator::Jucator(const std::string &nume, int baniCard, const char *proprietati) : nume(nume),
                                                                                   baniCard(baniCard),
                                                                                   proprietati((unsigned int) proprietati) {
    std::cout << "Am fost creat!!";
}

Jucator::~Jucator() = default;

#endif //TEMA_JUCATOR_H
