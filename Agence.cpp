#include <iostream>
using namespace std;
#include "Agence.hpp"


Agence::Agence(){

}

Biens Agence::idGood() {
  std::string adress;
  int ref;
  int prixx;
  int numm=0;

  std::cout << "Quelle est l'adresse ?" << '\n';
  std::cin >> adress;
  std::cout << "Quelle est la référence ?" << '\n';
  std::cin >> ref;
  std::cout << "Quel est le prix ?" << '\n';
  std::cin >> prixx;
  numm++;
  Biens *good = new Biens(prixx,adress,ref,numm);
  return *good;
}

void Agence::idTerrain(Biens b) {
  bool constructible;

  Terrain *good = new Terrain(b.getPrice(), b.getAdress(), b.getNum(),
  b.getRef());

  std::cout << "Le terrain est-il constructible ? false/true" << '\n';
  std::cin >> constructible;
  good->setConstructible(constructible);
}

void Agence::idMaison(Biens b) {
  int nb_pieces;
  bool garage, jardin, piscine;

  Maison *good = new Maison(b.getPrice(), b.getAdress(), b.getNum(),
  b.getRef());

  std::cout << "combien de pièces ?" << '\n';
  std::cin >> nb_pieces;
  good->setNbPieces(nb_pieces);
  std::cout << "voulez-vous un garage ? false/true" << '\n';
  std::cin >> garage;
  good->setGarage(nb_pieces);
  std::cout << "voulez-vous un jardin ? false/true" << '\n';
  std::cin >> jardin;
  good->setJardin(jardin);
  std::cout << "voulez-vous une piscine ? false/true" << '\n';
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
  std::cout << "voulez-vous une piece pour stocker ? false/true" << '\n';
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
  std::cout << "voulez-vous un garage ? false/true" << '\n';
  std::cin >> garage;
  good->setGarage(garage);
  std::cout << "voulez-vous une cave ? false/true" << '\n';
  std::cin >> cave;
  good->setCave(cave);
  std::cout << "voulez-vous un balcon ? false/true" << '\n';
  std::cin >> balcon;
  good->setBalcon(balcon);

}

void Agence::addOneGood(){
  int type;
      std::cout << "Quel type de biens voulez-vous ?" << '\n';
      std::cout << "1: Locaux \n2: Maison \n3: Terrain \n4: Appartement" << '\n';
  std::cin >> type;

  Biens good = idGood();
  switch (type) {
      case 1: idLocaux(good);break;
      case 2: idMaison(good);break;
      case 3: idTerrain(good);break;
      case 4: idFlat(good);break;
      // default: std::cout << "vous vous etes trompés. Recommencez." <<'\n';
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
  int nb;
  Client_acheteur *idv = new Client_acheteur();
  idClients(idv);

  std::cout << "Combien de biens l'intéresse ?" << '\n';
  std::cin >> nb;
  for(int i = 0; i<nb; i++) {

  }
}

void Agence::addSellers() {
  int nb;
  Client_vendeur *idv = new Client_vendeur();
  idClients(idv);

  std::cout << "Combien de biens l'intéresse ?" << '\n';
  std::cin >> nb;
  for(int i = 0; i<nb; i++) {

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
    int piece;
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
    for(std::map<Biens,std::vector<std::string> >::iterator it=goods_map.begin();it!=goods_map.end();it++) {
        // Biens *good=new Biens(prixx,adress,ref,numm)
        Biens *test = it->first;
        if(test->getPrice() == prix && test->getAdress() == adresse && test->getRef() == ref) {
            v.push_back(*test);
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
}}}}


void Agence::affiche(){
  cout << "Vendeurs :\n" << endl;
    for(int i=0;i<sellers.size();i++) {
      sellers[i].affiche();
    }
  cout << "\nAcheteurs :\n" << endl;
    for(int i=0;i<buyers.size();i++) {
      buyers[i].affiche();
    }
}


// void Agence::create_biens() {
//     int nb_biens;
//     Biens init;
//     std::cout << "Combien de biens voulez-vous ajouter ?" << endl;
//     std::cin >> nb_biens;
//     for(int i=0;i<nb_biens;i++){
//       init = init.create_biens();
//       goods_map[init];
//     }
// }


// void Agence::check_biens(Biens b){
//   std::map<Biens,std::vector<Client_acheteur>>::iterator iter;
//   for (iter = goods_map.begin(); iter != goods_map.end(); iter++) {
//     Biens courant=iter->first;
//     if(courant==b){
//       return true;
//     }
//     else{
//       return false;
//     }
//   }
// }



// void Agence::save_client() {
//   std::string reponse;
//   int nb;
//   cout<<"Voulez-vous ajouter des acheteurs ou des vendeurs ? a/v"<<endl;
//   cin>>reponse;
//   cout<<"Combien voulez-vous en ajouter ?"<<endl;
//   cin>>nb;
//   if(reponse=="a"){
//     Client_acheteur idv;
//     for(int i=0;i<nb;i++){
//       idv.create_client();
//       idv.affiche();
//       buyers.push_back(idv);
//     }
//   }
//   else if(reponse=="v") {
//     Client_vendeur idv;
//     for(int i=0;i<nb;i++){
//       idv.create_client();
//       sellers.push_back(idv);
//     }
//   }
//   else {
//     cout << "done" << endl;
//   }
// }


void Agence::ajouter_biens(){
  // Biens good;
  // std::string vendeur;
  // good.create_biens();
  // cout << "Indiquez le nom du vendeur." << endl;
  // cin >> vendeur;
  // for(int i=0;i<sellers.size();i++) {
  //   if(sellers[i].get_nom_client()==vendeur){
  //     sellers[i].add_biens(good);
  //     break;
  //   }
  // }
}

// void Agence::proposition_achat(){
//   Client_acheteur interet;
//   std::string acheteur;
//   int good;
//   int prix;
//   cout << "Quel client a fait une proposition d'achat ?" << endl;
//   cin >> acheteur;
//   cout << "Sur quel bien ? Indiquez son identifiant numérique." << endl;
//   cin >> good;
//   for(int i=0;i<buyers.size();i++){
//     if(buyers[i].get_nom_client()==acheteur){
//       Client_acheteur interet=buyers[i];
//       break;
//     }
//   }
//   std::map<Biens,int> goodList=interet.getMapVisites();
//   std::map<Biens,int>::iterator iter;
//   for (iter = goodList.begin(); iter != goodList.end(); iter++) {
//     Biens courant=iter->first;
//     if(courant.getNum()==good) {
//       cout << "A combien s'élève la proposition d'achat ?" << endl;
//       cin >> prix;
//       iter->second=prix;
//     }
//   }
// }
