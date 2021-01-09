//
// Created by alexandra on 12/5/2020.
//

#ifndef TEMA_ALT_SPATIU_H
#define TEMA_ALT_SPATIU_H
#include <iostream>
#include <vector>
#include "spatiu_joc.h"
class Alta_carte : public Spatiu_joc {
    std::string primesc_sau_platesc;
public:

    const std::string &getPrimescSauPlatesc() const;

    void setPrimescSauPlatesc(const std::string &primescSauPlatesc);

    friend std::istream& operator>>(std::istream&, Alta_carte&);
    friend std::ostream& operator<<(std::ostream&, const Alta_carte&);

    void aleg_card_comunitate();
    void aleg_card_noroc();
    void aleg_card_gara();
    void aleg_card_taxa();

    std::string MesajTest();

    ~Alta_carte();
};
#endif //TEMA_ALT_SPATIU_H
