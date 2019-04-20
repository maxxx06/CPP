#include <iostream>
using namespace std;
#include "Client_acheteur.hpp"

Client_acheteur::Client_acheteur() : Client() {

}


Client_acheteur::Client_acheteur(std::string _nom_client, std::string _adresse_client) : Client(_nom_client, _adresse_client) {

}

void Client_acheteur::addProposal(Biens b) {
  std::cout << "Quelle est sa proposition d'achat ?" << '\n';
  cin >> map_visites[b];
}

void Client_acheteur::add_biens(Biens b){
  map_visites[b];
}

void Client_acheteur::delete_biens(Biens b) {
  map_visites.erase(b);
}

std::map<Biens,int> Client_acheteur::getMapVisites(){
  return map_visites;
}

void Client_acheteur::affiche(){
  Client::affiche();
  Biens courant;
  cout << "Liste des biens et leurs propositions d'achat:\n" << endl;
  std::map<Biens,int>::iterator iter;
  for (iter = map_visites.begin(); iter != map_visites.end(); iter++) {
    courant=iter->first;
    courant.affiche();
    cout << "Proposition d'achat : " << iter->second << endl;
  }
}
