#ifndef CLIENT_HPP
#define  CLIENT_HPP

#include "Agence.hpp"
#include <iostream>

class Client {
protected:
    std::string nom_client;
    std::string adresse_client;

public:
    Client();
    Client(std::string nom_client,std::string adresse_client);
    void create_client();
    std::string get_nom_client();
    std::string get_adresse_client();
    virtual void save_client();
};


#endif
