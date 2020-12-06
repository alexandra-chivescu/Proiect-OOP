//
// Created by alexandra on 11/20/2020.
//
#include "../headers/banca.h"
Banca::Banca() {
    suma_bani = 10000;
}

void Banca::primeste_bani(int suma) {
    suma_bani += suma;
}

void Banca::da_bani(int suma) {
    suma_bani -= suma;
}

Banca::~Banca() {

}