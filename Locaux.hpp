#ifndef LOCAUX_HPP
#define LOCAUX_HPP


#include <iostream>
#include "Biens.hpp"
using namespace std;

class Locaux : public Biens {
private:
    int taille_vitrine;
    bool stocker;

public:
    void create_locaux();

};
#endif
