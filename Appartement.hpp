#ifndef APPARTEMENT_HPP
#define APPARTEMENT_HPP

#include <iostream>
#include "Biens.hpp"
using namespace std;

class Appartement : public Biens {
private:
    int nb_pieces;
    int etage;
    bool garage;
    bool cave;
    bool balcon;
    int nb_apparts;

public:
    void create_appartement();
    void vendre_appartement();
};



#endif
