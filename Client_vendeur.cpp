#include <iostream>
using namespace std;
#include "Client_vendeur.hpp"

Client_vendeur::Client_vendeur() : Client() {
}

Client_vendeur::Client_vendeur(std::string _nom_client, std::string _adresse_client) : Client(_nom_client, _adresse_client) {

}


std::vector<Biens> Client_vendeur::getListGoods(){
  return liste_biens;
}


void Client_vendeur::affiche(){
  Client::affiche();
  Biens courant;
  cout << "Liste des biens :\n" << endl;
  for(int i=0;i<liste_biens.size();i++){
    courant=liste_biens[i];
    courant.affiche();
  }
}


void Client_vendeur::add_biens(Biens b){
  liste_biens.push_back(b);
}

void Client_vendeur::delete_biens(Biens b) {
  vector<Biens>::iterator it = liste_biens.begin();
  int i=0;

  for (auto it = liste_biens.begin(); it != liste_biens.end(); ++it, i++) {
    if(liste_biens[i]==b){
      // liste_biens.erase(it);
    }
  }
}

void Client_vendeur::setRef(int _ref) {
  ref=_ref;
}

int Client_vendeur::getRef() {
  return ref;
}
