#include <iostream>
#include <vector>
#include <fstream>
#include "jucator.h"
//#include "proprietate.h"

int main() {
    std::ifstream f("jucatori.txt");
    int n;
    f>>n;
    std::cout << "Numarul de jucatori este: " << n << "\n";

    std::vector<Jucator> jucator;
    std::string nume;
    int bani_card;

    for (int i = 0; i < n; ++i) {
        f>>nume;
        f>>bani_card;
        Jucator jucator_nou(nume, bani_card, i+1);
        jucator.push_back(jucator_nou);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << "Jucatorul " << jucator[i].get_nume() << " cu id-ul " << jucator[i].get_id() << " are pe card suma de " << jucator[i].get_bani_card() << " lei"<<"\n";
    }
    return 0;
}
