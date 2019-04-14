#include <iostream>
using namespace std;
#include "Clients_acheteurs.hpp"

Clients_acheteurs::Clients_acheteurs() {
    proposition_achat=false;
    prix_achat=0;
    // liste_visite=0; faire une surcharge d'operateur pour dire que le string = Unknow et int = 0
}

Clients_acheteurs::Clients_acheteurs(bool _proposition_achat) {
    proposition_achat=_proposition_achat;
    prix_achat=0;
    // liste_visite=0; faire une surcharge d'operateur pour dire que le string = Unknow et int = 0
}

Clients_acheteurs::Clients_acheteurs(bool _proposition_achat,int _prix_achat) {
    proposition_achat=_proposition_achat;
    prix_achat=_prix_achat;
}

Clients_acheteurs::Clients_acheteurs(bool _proposition_achat,int _prix_achat,map<std::string,int> _liste_visite) {
    proposition_achat=_proposition_achat;
    prix_achat=_prix_achat;
    liste_visite=_liste_visite;
}


void Clients_acheteurs::ajouter(Biens b) {
    for (int it=0;it<4;it++) {
        liste_visite[b.getadress()]=it;
    }
}

void Clients_acheteurs::afficher() {
    for(std::map<std::string,int>::iterator it=liste_visite.begin();it!=liste_visite.end();it++){
        std::cout << it->first <<endl;
    }
}
