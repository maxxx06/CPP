#ifndef Client_acheteur_HPP
#define Client_acheteur_HPP

#include "Client.hpp"
#include "Biens.hpp"
#include <map>
#include <vector>

class Client_acheteur : public Client{
private:
    // int nb_visite;
    // std::string liste_biens;
    map<std::string,int> liste_visite;
    bool proposition_achat;
    int prix_achat;

public:
    Client_acheteur();
    Client_acheteur(bool proposition_achat);
    Client_acheteur(bool proposition_achat,int prix_achat);
    Client_acheteur(bool proposition_achat,int prix_achat, map<std::string,int> liste_visite);
    void ajouter(Biens b);
    void afficher();
    ~Client_acheteur();
};

#endif
