#ifndef GESTION_CLIENT_HPP
#define  GESTION_CLIENT_HPP

#include "Agence.hpp"
#include <iostream>

class Gestion_client {
protected:
    std::string nom_client;
    std::string adresse_client;

public:
    Gestion_client();
    Gestion_client(std::string nom_client,std::string adresse_client);
    void create_client();
    std::string get_nom_client();
    std::string get_adresse_client();
    virtual void save_client();
};


#endif
