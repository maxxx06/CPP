#ifndef AGENCE_HPP
#define AGENCE_HPP

#include <iostream>
#include "Client.hpp"
#include "Biens.hpp"
using namespace std;

class Agence {


protected:
    // std::map<std::string,std::map<Biens,std::vector<Client_acheteur>>> goods_type_map;
    // std::vector<Client_vendeur> sellers;
    // std::vector<Client_acheteur> buyers;

public:
    virtual void save_client();
};
#endif
