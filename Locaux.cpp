#include <iostream>
using namespace std;
#include "Locaux.hpp"

Locaux::Locaux(int m_taille_vitrine, bool m_stocker) {
  taille_vitrine = m_taille_vitrine;
  stocker = m_stocker;
}

void Locaux::create_locaux() {
    int nb;
    int taille;
    std::string stocker;
    std::cout << "combien de locaux voulez vous ?" << '\n';
    std::cin >> nb;
    for (int i=0;i<=nb; i++) {
        std::cout << "quelle taille vitrine ?" << '\n';
        std::cin >> taille;
        std::cout << "voulez-vous une piece pour stocker ? false/true" << '\n';
        std::cin >> stocker;
    }
}

void Locaux::vendre_locaux() {

}
