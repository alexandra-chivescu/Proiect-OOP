#include <iostream>
#include <vector>
#include "jucator.h"
//#include "proprietate.h"

int main() {
    std::cout<< "Introdu numarul de jucatori: ";
    int n;
    std::cin >> n;
    Jucator* jucator[n];

    std::string nume;
    int bani;
    std::string proprietate;
    std::vector<std::string> proprietati;

    for(int i = 0; i < n; i++) {
        jucator[i] = new Jucator();

        std::cout<< "Introdu numele jucatorului  "<<i+1<< ": ";
        std::cin >> nume;
        jucator[i]->setNume(nume);
        std::cout<< "Banii pe card: ";

        std::cin >> bani;
        jucator[i]->setBaniCard(bani);
        std::cout<< "Proprietatile detinute: (daca nu detine niciuna, introdu 0)";

        std::cin >> proprietate;
        if(proprietate == "0") {
            continue;
        } else {
            jucator[i]->listaProprietati(proprietate);
        }
    }

    //std::vector<std::string> toateProprietatile;

    std::cout<< "Afisarea situatiilor financiare ale jucatorilor: " << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << jucator[i]->getNume() << " -> " << jucator[i]->getBaniCard() << "$ pe card si proprietati: ";
        for(auto  &x: jucator[i]->listaProprietati()) {
            std::cout << x<< " ";
        }
        std::cout<< std::endl;
    }

    Jucator jucatorNou("Alexandra", 500, "Mall");
    std::cout << jucatorNou.getNume();

    for (int i=0; i< n; i++)
        delete jucator[i];
    return 0;
}
