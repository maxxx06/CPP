#include <iostream>
using namespace std;
#include "Agence.hpp"
#include "Biens.hpp"
#include "Locaux.hpp"
#include "Maison.hpp"
#include "Appartement.hpp"
#include "Terrain.hpp"
#include "Client.hpp"
#include <vector>
#include <fstream>
#include <iterator>

static int numm=0;


Agence::Agence(){

}

Biens Agence::idGood() { // affecte une référence à un bien
    std::string adress;
    int ref;
    int prixx;

    std::cout << "Quelle est l'adresse ?" << '\n';
    std::cin >> adress;
    std::cout << "Quelle est la référence ?" << '\n';
    std::cin >> ref;
    std::cout << "Quel est le prix ?" << '\n';
    std::cin >> prixx;
    numm++;
    Biens *good = new Biens(prixx,adress,ref,numm); // pointeurs vers un bien ayant un prix, adresse ...
    return *good;
}

void Agence::idTerrain(Biens b) {
    bool constructible;

    Terrain *good = new Terrain(b.getPrice(), b.getAdress(), b.getNum(),
    b.getRef()); // obtenir les caracteristiques du bien terrain

    std::cout << "Le terrain est-il constructible ? 0 --> non 1 --> oui" << '\n';
    std::cin >> constructible;
    good->setConstructible(constructible); // modification de la valeur constructible
}

void Agence::idMaison(Biens b) {
    int nb_pieces;
    bool garage, jardin, piscine;

    Maison *good = new Maison(b.getPrice(), b.getAdress(), b.getNum(),
    b.getRef());

    std::cout << "combien de pièces ?" << '\n';
    std::cin >> nb_pieces;
    good->setNbPieces(nb_pieces);
    std::cout << "voulez-vous un garage ? 0 --> non 1 --> oui" << '\n';
    std::cin >> garage;
    good->setGarage(nb_pieces);
    std::cout << "voulez-vous un jardin ? 0 --> non 1 --> oui" << '\n';
    std::cin >> jardin;
    good->setJardin(jardin);
    std::cout << "voulez-vous une piscine ? 0 --> non 1 --> oui" << '\n';
    std::cin >> piscine;
    good->setPiscine(piscine);
}

void Agence::idLocaux(Biens b) {
    int taille_vitrine;
    bool stocker;

    Locaux *good = new Locaux(b.getPrice(), b.getAdress(), b.getNum(),
    b.getRef());

    std::cout << "quelle taille vitrine ?" << '\n';
    std::cin >> taille_vitrine;
    good->setTailleVitrine(taille_vitrine);
    std::cout << "voulez-vous une piece pour stocker ? 0 --> non 1 --> oui" << '\n';
    std::cin >> stocker;
    good->setStocker(stocker);
}

void Agence::idFlat(Biens b) {
    int nb_pieces;
    int etage;
    bool garage, cave, balcon;

    Appartement *good = new Appartement(b.getPrice(), b.getAdress(), b.getNum(),
    b.getRef());

    std::cout << "combien de pièces ?" << '\n';
    std::cin >> nb_pieces;
    good->setNbPieces(nb_pieces);
    std::cout << "A quel étage ?" << '\n';
    std::cin >> etage;
    good->setEtage(etage);
    std::cout << "voulez-vous un garage ? 0 --> non 1 --> oui" << '\n';
    std::cin >> garage;
    good->setGarage(garage);
    std::cout << "voulez-vous une cave ? 0 --> non 1 --> oui" << '\n';
    std::cin >> cave;
    good->setCave(cave);
    std::cout << "voulez-vous un balcon ? 0 --> non 1 --> oui" << '\n';
    std::cin >> balcon;
    good->setBalcon(balcon);

}

void Agence::addGoods() {
    int nb;

    std::cout << "Combien voulez-vous ajouter de biens ?" << '\n';
    std::cin >> nb;

    for(int i = 0; i < nb; i++) {
        addOneGood();
    }
}

void Agence::addOneGood(){
    int type;
    std::string nom;

    std::cout << "Quel type de biens ?" << '\n';
    std::cout << "1: Locaux \n2: Maison \n3: Terrain \n4: Appartement" << '\n';
    std::cin >> type;

    Biens good = idGood(); // definition d'un bien
    switch (type) {
        case 1: idLocaux(good);break;
        case 2: idMaison(good);break;
        case 3: idTerrain(good);break;
        case 4: idFlat(good);break;
        default: std::cout << "vous vous etes trompés. Recommencez." << '\n';
    }
    goods_map[good]; // ajout du bien dans la map goods_map
    for(int i = 0; i < sellers.size(); i++) {
        if(sellers[i]->getRef()==good.getRef()) { // verification de la concordance
            sellers[i]->add_biens(good); // ajout dans le vecteur sellers
        }
    }

}


void Agence::idClients(Client *c) {
    std::string nom;
    std::string adresse;
    std::cout << "Quel est le nom du client ?" << '\n';
    std::cin >> nom;
    c->setNom(nom);
    std::cout << "Quelle est son adresse ?" << '\n';
    std::cin >> adresse;
    c->setAdresse(adresse);
    c->affiche();
  // Client *idv = new Client(nom,adresse);
  // return *idv;
}

void Agence::addClients(){
    std::string choix;
    int nb;

    std::cout << "Voulez-vous ajouter des acheteurs ou des vendeurs ? a/v" << '\n';
    std::cin >> choix;
    std::cout << "Combien voulez-vous en ajouter ?" << '\n';
    std::cin >> nb;
    if(choix=="a") {
        for(int i = 0; i<nb; i++){
            addBuyers();
        }
    }
    else if(choix=="v") {
        for(int i = 0; i<nb; i++) {
            addSellers();
        }
    }
}

void Agence::addBuyers() {
    Biens courant;
    int nb;
    Client_acheteur *idv = new Client_acheteur();
    idClients(idv);
    buyers.push_back(idv);

    std::cout << "Combien de biens l'intéresse ?" << '\n';
    std::cin >> nb;
    for(int i = 0; i<nb; i++) {
        std::cout << "\nBien " << i << '\n';
        courant=searchGood();
        goods_map[courant].emplace_back(*idv);  // Associer un bien à un acheteurs
        idv->addProposal(courant); // ajout d'une proposition d'achat a l'acheteur
    }
}

void Agence::addSellers() {
    int ref;
    Client_vendeur *idv = new Client_vendeur();
    idClients(idv);
    cout << "Quel est son numéro référence ?" << endl;
    cin >> ref;
    idv->setRef(ref);
    sellers.push_back(idv);
}


void Agence::sellGoods() {
    std::string loop="y";
    afficheGoods();
    while(loop!="n") {
        Biens courant = searchGood();
        Client_vendeur vendeur = searchSeller(courant);
        Client_acheteur acheteur = searchBuyer(courant);
        vendeur.delete_biens(courant);
        for(int i = 0; i<goods_map[courant].size(); i++) {
            goods_map[courant][i].delete_biens(courant); // supprime le bien associé à ce client(methode dans client vendeur)
        }
    deleteClient(acheteur);
    goods_map.erase(courant);
    // afficheGoods();
    std::cout << "D'autres biens ont-ils été vendus ? y/n" << '\n';
    std::cin >> loop;
    }
}


void Agence::afficheGoods() {
    std::map<Biens,std::vector<Client_acheteur>>::iterator iter;
    for (iter = goods_map.begin(); iter != goods_map.end(); iter++) {
        Biens courant = iter->first;
        courant.affiche();
        cout << "Intéressés : " << "\t";
        for(int i = 0; i<goods_map[courant].size(); i++) {
            cout << goods_map[courant][i].get_nom_client() << "\t";
        }
    }
}



void Agence::afficheClients(){
    cout << "Vendeurs :\n" << endl;
    for(int i=0;i<sellers.size();i++) {
        sellers[i]->affiche();
    }
    cout << "\nAcheteurs :\n" << endl;
    for(int i=0;i<buyers.size();i++) {
        buyers[i]->affiche();
    }
}

Biens Agence::searchGood() {
    int id;
    Biens courant;

    std::cout << "Quel est l'identifiant du bien ?" << '\n';
    std::cin >> id;

    std::map<Biens,std::vector<Client_acheteur>>::iterator iter;
    for (iter = goods_map.begin(); iter != goods_map.end(); iter++) {
        courant=iter->first;
        if(courant.getNum()==id) {
            return courant;
        }

    }
}

Client_vendeur Agence::searchSeller(Biens b) {
    for(int i = 0; i<sellers.size(); i++) {
        if(sellers[i]->getRef()==b.getRef()) {
            return *sellers[i];
        }
    }
}

Client_acheteur Agence::searchBuyer(Biens b) {
    std::string nom;
    cout << "Quel est le nom de l'acheteur ?" << endl;
    std::cin >> nom;
    for(int i = 0; i<goods_map[b].size(); i++) {
        if(goods_map[b][i].get_nom_client()==nom) {
            return goods_map[b][i];
        }
    }
}

void Agence::deleteClient(Client_acheteur idv) {
    vector<Client_acheteur*>::iterator it = buyers.begin();
    int i=0;

    for (auto it = buyers.begin(); it != buyers.end(); ++it, i++) {
        if(buyers[i]->get_nom_client()==idv.get_nom_client()) {
            // buyers.erase(it);
            delete *it;

        }
    }
}

void Agence::recherche() {
    std::vector<Biens> v;
    int type;
    int prix;
    std::string adresse;
    int ref;
    std::string answer;
    int taille;
    int etage;
    int nb_pieces;
    bool piscine;
    bool stock;
    bool garage;
    bool cave;
    bool balcon;
    bool jardin;
    bool constructible;

    std::cout << "Quelle prix ?" << '\n';
    std::cin >> prix;
    std::cout << "Quelle adresse ?" << '\n';
    std::cin >> adresse;
    std::cout << "Quelle ref du client ?" << '\n';
    std::cin >> ref;
    for(std::map<Biens,std::vector<Client_acheteur> >::iterator it=goods_map.begin();it!=goods_map.end();it++) {
        Biens test = it->first;
        if(test.getPrice() == prix && test.getAdress() == adresse && test.getRef() == ref) {
            v.push_back(test);
            std::cout << "quel type de biens ? " << '\n';
            std::cout << "1: Locaux \n2: Maison \n3: Terrain \n4: Appartement" << '\n';
            std::cin >> type;
            switch (type) {
                case 1: {Locaux *test = new Locaux(prix,adresse,ref,1);
                        std::cout << "Quelle taille de vitrine ?" << '\n';
                        std::cin >> taille;
                        std::cout << "Une piece pour stocker ? 0 --> non 1 --> oui " << '\n';
                        std::cin >> stock;
                        if(test->getTaille()==taille && test->getStock()==stock) {
                            v.push_back(*test);
                        }}break;

                case 2:{Maison *test = new Maison(prix,adresse,ref,1);
                        std::cout << "combien de piece ?" << '\n';
                        std::cin >> nb_pieces;
                        std::cout << "voulez-vous un garage ? 0 --> non 1--> oui" << '\n';
                        std::cin >> garage;
                        std::cout << "voulez-vous un jardin ? 0 --> non 1--> oui" << '\n';
                        std::cin >> jardin;
                        std::cout << "voulez-vous une piscine ? 0 --> non 1--> oui" << '\n';
                        std::cin >> piscine;
                        if(test->getNbPieces()==nb_pieces && test->getGarage()==garage && test->getJardin()==jardin && test->getPiscine()==piscine) {
                            v.push_back(*test);
                        }}break;

                case 3:{Terrain *test = new Terrain(prix,adresse,ref,1);
                        std::cout << "constructible 0 --> non 1--> oui?" << '\n';
                        std::cin >> constructible;
                        if(test->getConstructible()==constructible) {
                            v.push_back(*test);
                        }}break;

                case 4:{Appartement *test = new Appartement(prix,adresse,ref,1);
                        std::cout << "combien de piece ?" << '\n';
                        std::cin >> nb_pieces;
                        std::cout << "A quel etage ?" << '\n';
                        std::cin >> etage;
                        std::cout << "voulez-vous un garage ? 0 --> non 1--> oui" << '\n';
                        std::cin >> garage;
                        std::cout << "voulez-vous une cave ? 0 --> non 1--> oui" << '\n';
                        std::cin >> cave;
                        std::cout << "voulez-vous un balcon ? 0 --> non 1--> oui" << '\n';
                        std::cin >> balcon;
                        if(test->getNbPieces()==nb_pieces && test->getEtage()==etage && test->getGarage()==garage && test->getBalcon()==balcon && test->getCave()==cave) {
                            v.push_back(*test);
                        }}break;
              }
          }
      }
      // v.affiche();
}

void Agence::load_fichier() {
    int nom_fichier;
    std::cout << "quel fichier voulez vous ? 1: biens.txt / 2 : acheteurs.txt / 3: vendeurs.txt" << '\n';
    std::cin >> nom_fichier;
    switch(nom_fichier) {
        case 1 : load_biens();break;
        case 2 : load_acheteurs();break;
        case 3 : load_vendeurs();break;
    }
}


void Agence::load_biens() {
  vector<std::string> vecString;
    ifstream fInFile("biens.txt");
    copy(istream_iterator<std::string>(fInFile), istream_iterator<std::string>(), back_inserter(vecString));
    for(int i=0; i<=vecString.size();i++ ) {
      std::cout << vecString[i] << '\t';
    }
}

void Agence::load_acheteurs() {
  vector<std::string> vecacheteurs;
    ifstream fichier("acheteurs.txt");
    copy(istream_iterator<std::string>(fichier), istream_iterator<std::string>(), back_inserter(vecacheteurs));
    for(int i=0; i<=vecacheteurs.size();i++ ) {
        std::cout << vecacheteurs[i] << '\t';}
}

void Agence::load_vendeurs() {
  vector<std::string> vecvendeurs;
    ifstream fichier2("vendeurs.txt");
    copy(istream_iterator<std::string>(fichier2), istream_iterator<std::string>(), back_inserter(vecvendeurs));
    for(int i=3; i<=vecvendeurs.size();i++ ) {
        std::cout << "vendeurs : " << vecvendeurs[i] << '\t';
    }
}
