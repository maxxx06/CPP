#ifndef CLIENTS_ACHETEURS_HPP
#define CLIENTS_ACHETEURS_HPP

#include "Gestion_client.hpp"
#include "Biens.hpp"
#include <map>
#include <vector>

class Clients_acheteurs : public Gestion_client{
private:
    // int nb_visite;
    // std::string liste_biens;
    map<std::string,int> liste_visite;
    bool proposition_achat;
    int prix_achat;

public:
    Clients_acheteurs();
    Clients_acheteurs(bool proposition_achat);
    Clients_acheteurs(bool proposition_achat,int prix_achat);
    Clients_acheteurs(bool proposition_achat,int prix_achat, map<std::string,int> liste_visite);
    void ajouter(Biens b);
    void afficher();
    ~Clients_acheteurs();
};

#endif
