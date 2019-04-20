#include <iostream>
using namespace std;
#include "Terrain.hpp"

Terrain::Terrain() {

}

Terrain::Terrain(int prixx, std::string adress, int ref, int numm) :Biens(prixx,adress,ref,numm) {

}

Terrain::Terrain(bool _constructible) {
    constructible = _constructible;
}


void Terrain::setConstructible(bool _constructible) {
  constructible=_constructible;
}

bool Terrain::getConstructible() {
    return constructible;
}

void Terrain::affiche() {
  cout << "\nBien numéro " << num << " :\n" <<
  "Adresse : " << adresse << ", prix : " << prix << ", référence client vendeur : " << ref << "constructible ? :" << getConstructible() << endl;
}
