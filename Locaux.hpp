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
    Locaux(int taille_vitrine,bool stocker);
    void create_locaux();
    void vendre_locaux();

};
#endif
