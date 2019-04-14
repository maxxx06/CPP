#include <iostream>
using namespace std;
#include "Biens.hpp"

Biens::Biens() {
    prix=0;
    adresse_biens="unknown";
    ref_client=0;
    int num=0;
}

Biens::Biens(int _prix,std::string _adresse_biens,int _ref_client,int _num) {
    prix=_prix;
    adresse_biens=_adresse_biens;
    ref_client=_ref_client;
    num=_num;
}

void Biens::create_biens() { // le stocker dans un vector
    int type;
    std::cout << "Quel type de biens voulez-vous ?" << '\n';
    std::cout << "1: Locaux \n, 2: Maison \n, 3: Terrain \n, 4: Appartement" << '\n';
    std::cin >> type;
    switch (type) {
        case 1: void create_locaux();break; 
        case 2: void create_maison();break;
        case 3: void create_terrain();break;
        case 4: void create_appartement();break;
        default : std::cout << "vous vous etes trompés. Recommencez." <<'\n';
    }
}

void Biens::vendre_biens() {
    int type;
    std::cout << "quel type de biens voulez-vous vendre ?" << '\n';
    std::cout << "1: Locaux \n, 2: Maison \n, 3: Terrain \n, 4: Appartement" << '\n';
    std::cin >> type;
    switch (type) {
        case 1: void vendre_locaux();break;
        case 2: void vendre_maison();break;
        case 3: void vendre_terrain();break;
        case 4: void vendre_appartement();break;
        default : std::cout << "vous vous etes trompés. Recommencez." <<'\n';
    }
}

std::string Biens::getadress() {
    return adresse_biens;
}
