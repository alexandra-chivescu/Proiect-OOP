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

    void get_card_comunitate(Alta_carte &alta_carte);
    void get_card_noroc(Alta_carte &alta_carte);
    void get_card_gara(Alta_carte &alta_carte);
    void get_card_taxa(Alta_carte &alta_carte);

    ~Alta_carte();
};
#endif //TEMA_ALT_SPATIU_H
