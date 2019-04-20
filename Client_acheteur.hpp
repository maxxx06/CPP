#ifndef Client_acheteur_HPP
#define Client_acheteur_HPP

#include "Client.hpp"
#include "Biens.hpp"
#include <map>
#include <vector>

class Client_acheteur : public Client {
private:
    // int nb_visite;
    // std::string liste_biens;
    map<Biens,int> map_visites;
    // bool proposition_achat;
    // int prix_achat;

public:
    Client_acheteur();
    Client_acheteur(std::string,std::string);
    void addProposal(Biens);
    // Client_acheteur(bool proposition_achat);
    // Client_acheteur(bool proposition_achat,int prix_achat);
    // Client_acheteur(map<Biens,int> liste_visite);
    // void create_client();
    void virtual affiche();
    std::map<Biens,int> getMapVisites();

    void add_biens(Biens b);
    void delete_biens(Biens b);
};

#endif
