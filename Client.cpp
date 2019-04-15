#include <iostream>
using namespace std;
#include "Client.hpp"

Client::Client() {
    nom_client="Unknown";
    adresse_client="Unknown";
}

Client::Client(std::string nom_client,std::string adresse_client) {
    nom_client=this->nom_client;
    adresse_client=this->adresse_client;
}

void Client::create_client() {
    std::cout << "Le nom du client ?" << '\n';
    std::cin >> nom_client;
    std::cout << "adresse du client ?" << '\n';
    std::cin >> adresse_client;
}

std::string Client::get_nom_client() {
    std::cout << nom_client << '\n';
    return nom_client;
}

std::string Client::get_adresse_client() {
    std::cout << adresse_client <<'\n';
    return adresse_client;
}

void Client::save_client() {
    get_nom_client();
    get_adresse_client();
}
