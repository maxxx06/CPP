#include <iostream>
using namespace std;
#include "Locaux.hpp"


// CONSTRUCTEURS //

Locaux::Locaux() {
  taille_vitrine = 0;
  stocker = 0;
}

Locaux::Locaux(int prixx, std::string adress, int ref, int numm) : Biens(prixx,adress,ref, numm) {

}

Locaux::Locaux(int m_taille_vitrine, bool m_stocker) {
    taille_vitrine = m_taille_vitrine;
    stocker = m_stocker;
}

// GETTERS AND SETTERS //


void Locaux::setTailleVitrine(int _taille) {
  taille_vitrine=_taille;
}

void Locaux::setStocker(bool _stocker) {
  stocker=_stocker;
}

int Locaux::getTaille() {
    return taille_vitrine;
}

bool Locaux::getStock() {
    return stocker;
}

void Locaux::affiche() {
  cout << "\nBien numéro " << num << " :\n" <<
  "Adresse : " << adresse << ", prix : " << prix << ", référence client vendeur : " << ref << ", Taille de la vitrine : " << taille_vitrine << ",piece pour stocker ? : " << getStock() << endl;
}
