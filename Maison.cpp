#include <iostream>
using namespace std;
#include "Maison.hpp"

void Maison::create_maison() {
    int nb;
    int nb_pieces;
    bool garage;
    bool jardin;
    bool piscine;

    std::cout << "combien de maison voulez vous ?" << '\n';
    std::cin >> nb;
    for (int i=0;i<=nb; i++) {
        std::cout << "combien de pièces ?" << '\n';
        std::cin >> nb_pieces;
        std::cout << "voulez-vous un garage ? false/true" << '\n';
        std::cin >> garage;
        std::cout << "voulez-vous un jardin ? false/true" << '\n';
        std::cin >> jardin;
        std::cout << "voulez-vous une piscine ? false/true" << '\n';
        std::cin >> piscine;
    }
}
