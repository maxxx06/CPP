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
    Locaux();
    Locaux(int prixx, std::string adress, int ref, int numm);
    Locaux(int taille_vitrine,bool stocker);
    void create_locaux();

    void setTailleVitrine(int);
    int getTaille();
    void setStocker(bool);
    bool getStock();

};
#endif
