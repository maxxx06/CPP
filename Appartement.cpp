#include <iostream>
using namespace std;
#include "Appartement.hpp"

Appartement::Appartement(int _nb_pieces,int _etage,bool _garage,bool _cave,bool _balcon,int _nb_apparts) {
    nb_pieces=_nb_pieces;
    etage=_etage;
    garage=_garage;
    cave=_cave;
    balcon=_balcon;
    nb_apparts=_nb_apparts;
}

void Appartement::create_appartement() {
    int nb_pieces;
    int etage;
    bool garage;
    bool cave;
    bool balcon;
    int nb_apparts;
    std::cout << "combien d'appartement voulez vous ?" << '\n';
    std::cin >> nb_apparts;
    for (int i=0;i<=nb_apparts; i++) {
        std::cout << "combien de pièces ?" << '\n';
        std::cin >> nb_pieces;
        std::cout << "A quel étage ?" << '\n';
        std::cin >> etage;
        std::cout << "voulez-vous un garage ? false/true" << '\n';
        std::cin >> garage;
        std::cout << "voulez-vous une cave ? false/true" << '\n';
        std::cin >> cave;
        std::cout << "voulez-vous un balcon ? false/true" << '\n';
        std::cin >> balcon;
        Appartement(nb_pieces,etage,garage,cave,balcon,nb_apparts);

    }
}

void Appartement::vendre_appartement() {

}
