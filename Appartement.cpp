#include <iostream>
using namespace std;
#include "Appartement.hpp"


// CONSTRUCTEURS //

Appartement::Appartement(){
  nb_pieces = 0;
  etage = 0;
  garage = 0;
  cave = 0;
  balcon = 0;
}

Appartement::Appartement(int prixx, std::string adress, int ref, int numm) : Biens(prixx,adress,ref,numm) {

}

Appartement::Appartement(int prix, std::string adresse_biens, int num, int ref_client, int _nb_pieces,int _etage,bool _garage,bool _cave,bool _balcon) : Biens(prix, adresse_biens,ref_client,num) {
    nb_pieces=_nb_pieces;
    etage=_etage;
    garage=_garage;
    cave=_cave;
    balcon=_balcon;
}

// GETTERS AND SETTERS //


void Appartement::setNbPieces(int _nb_pieces) {
  nb_pieces=_nb_pieces;
}

void Appartement::setEtage(int _etage) {
  etage=_etage;
}

void Appartement::setGarage(bool _garage) {
  garage=_garage;
}

void Appartement::setCave(bool _cave) {
  cave=_cave;
}

void Appartement::setBalcon(bool _balcon) {
  balcon=_balcon;
}

int Appartement::getNbPieces(){
    return nb_pieces;
}

bool Appartement::getGarage(){
    return garage;  // 0 = false 1 = true
}

bool Appartement::getCave(){
    return cave;
}

bool Appartement::getBalcon(){
    return balcon;
}

int Appartement::getEtage() {
    return etage;
}

void Appartement::affiche() {
  cout << "\nBien numéro " << num << " :\n" <<
  "Adresse : " << adresse << ", prix : " << prix << ", référence client vendeur : " << ref << ", nombre de pièces : " << nb_pieces << ", etage numero : " << etage << ", garage ? " << getGarage() << ", cave ? " << getCave() <<", balcon ? " << getBalcon() <<endl;
}
