#include <iostream>
using namespace std;
#include "Client_acheteur.hpp"

Client_acheteur::Client_acheteur() {
    proposition_achat=false;
    prix_achat=0;
    // liste_visite=0; faire une surcharge d'operateur pour dire que le string = Unknow et int = 0
}

Client_acheteur::Client_acheteur(bool _proposition_achat) {
    proposition_achat=_proposition_achat;
    prix_achat=0;
    // liste_visite=0; faire une surcharge d'operateur pour dire que le string = Unknow et int = 0
}

Client_acheteur::Client_acheteur(bool _proposition_achat,int _prix_achat) {
    proposition_achat=_proposition_achat;
    prix_achat=_prix_achat;
}

Client_acheteur::Client_acheteur(bool _proposition_achat,int _prix_achat,map<std::string,int> _liste_visite) {
    proposition_achat=_proposition_achat;
    prix_achat=_prix_achat;
    liste_visite=_liste_visite;
}


void Client_acheteur::ajouter(Biens b) {
    liste_visite[b.getadress()]=0;
}

void Client_acheteur::afficher() {
    for(std::map<std::string,int>::iterator it=liste_visite.begin();it!=liste_visite.end();it++){
        std::cout << it->first <<endl;
    }
}
