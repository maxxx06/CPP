#ifndef CLIENTS_ACHETEURS_HPP
#define CLIENTS_ACHETEURS_HPP
#include <map>

class Clients_acheteurs {
private:
    int nb_visite;
    map<std::string* liste_biens, int nb_visite> liste_visite; // metrtre en dico {biens : nombre_visite}
    bool proposition_achat;
    int prix_achat;

public:
    Clients_acheteurs();
    Clients_acheteurs(map liste_visite, bool proposition_achat);
    ~Clients_acheteurs();
};

#endif
