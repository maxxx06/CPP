#ifndef CLIENT_VENDEUR_HPP
#define CLIENT_VENDEUR_HPP

#include <iostream>
#include "Gestion_client.hpp"
#include "Biens.hpp"
#include <vector>

class Client_vendeur {
private:
  std::vector<Biens>liste_biens;

public:
    Client_vendeur();
    Client_vendeur(std::string nom_client);
    Client_vendeur(std::string nom_client,std::string adresse_client);
    Client_vendeur(std::string nom_client,std::string adresse_client,std::vector<Biens>liste_biens);
};


#endif
