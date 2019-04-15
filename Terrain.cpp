#include <iostream>
using namespace std;
#include "Terrain.hpp"


Terrain::Terrain(bool _constructible) {
    constructible = _constructible;
}

void Terrain::create_terrain() {
    int nb;
    bool constructible;
    std::cout << "combien de locaux voulez vous ?" << '\n';
    std::cin >> nb;
    for (int i=0;i<=nb; i++) {
        std::cout << "voulez-vous un terrain constructibe ? false/true" << '\n';
        std::cin >> constructible;
        Terrain(constructible);
    }

}


void Terrain::vendre_terrain() {

}
