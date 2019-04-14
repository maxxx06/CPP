#ifndef  BIENS_HPP
#define BIENS_HPP

#include <iostream>
using namespace std;

class Biens {
private:
    int prix;
    std::string adresse_biens;
    int ref_client;
    int num;

public:
    Biens();
    Biens(int prix, std::string adresse_biens,int ref_client,int num);
    void create_biens();
    void vendre_biens();
    std::string getadress();
};

#endif
