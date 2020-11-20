//
// Created by alexandra on 11/20/2020.
//

#ifndef TEMA_JOC_H
#define TEMA_JOC_H

#include <iostream>
#include <vector>

class Joc {
    std::vector<Jucator> jucatori;
    std::vector<Proprietate> proprietati;
public:
    void start();
};

#endif //TEMA_JOC_H
