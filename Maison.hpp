#ifndef MAISON_HPP
#define MAISON_HPP

#include <iostream>
#include "Biens.hpp"
using namespace std;

class Maison : public Biens{
private:
    int nb_pieces;
    bool garage;
    bool jardin;
    bool pisicne;

public:
    void create_maison();

};

#endif
