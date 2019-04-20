#include <iostream>
using namespace std;
#include "Maison.hpp"

Maison::Maison(){}

Maison::Maison(int prixx, std::string adress, int ref, int numm) : Biens(prixx,adress,ref,numm) {

}


Maison::Maison(int _nb_pieces,bool _garage,bool _jardin,bool _piscine) {
    nb_pieces=_nb_pieces;
    garage=_garage;
    jardin=_jardin;
    piscine=_piscine;
}

void Maison::setNbPieces(int _nb_pieces) {
  nb_pieces=_nb_pieces;
}

void Maison::setGarage(bool _garage) {
  garage=_garage;
}

void Maison::setJardin(bool _jardin) {
  jardin=_jardin;
}

void Maison::setPiscine(bool _piscine) {
  piscine=_piscine;
}

int Maison::getNbPieces(){
    return nb_pieces;
}

bool Maison::getGarage() {
    return garage;
}

bool Maison::getJardin() {
    return jardin;
}

bool Maison::getPiscine() {
    return piscine;
}

void Maison::affiche() {
  cout << "\nBien numéro " << num << " :\n" <<
  "Adresse : " << adresse << ", prix : " << prix << ", référence client vendeur : " << ref << ", nombre de pièces : " << nb_pieces << ", garage ? " << getGarage() << ", jardin ? " << getJardin() <<", piscine ? " << getPiscine() <<  endl;
}
