#include <iostream>
using namespace std;
#include "Client_vendeur.hpp"

Client_vendeur::Client_vendeur() {
    std::string nom_client="Unknown";
    std::string adresse_client="Unknow";
}

Client_vendeur::Client_vendeur(std::string _nom_client) {
    std::string nom_client=_nom_client;
    std::string adresse_client="Unknown";
}

Client_vendeur::Client_vendeur(std::string _nom_client,std::string _adresse_client) {
    std::string nom_client=_nom_client;
    std::string adresse_client=_adresse_client;
}

Client_vendeur::Client_vendeur(std::string _nom_client,std::string _adresse_client,std::vector<Biens>_liste_biens) {
    std::string nom_client=_nom_client;
    std::string adresse_client=_adresse_client;
    liste_biens=_liste_biens;
}
