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

}

void Appartement::vendre_appartement() {

}
