#include <iostream>
using namespace std;
#include "Client_acheteur.hpp"
#include "Biens.hpp"
#include "Agence.hpp"

int main() {
  int choix;

  std::cout << "##### MENU #####" << '\n';
  std::cout << "-----------------" << '\n';
  std::cout << "1. Ajouter un client (acheteur ou vendeur) " << '\n';
  std::cout << "2. Ajouter un bien à vendre" << '\n';
  std::cout << "3. Ajouter une proposition d'achat" << '\n';
  std::cout << "4. Rechercher un bien" << '\n';
  std::cout << "5. Enregistrer les données dans des fichiers" << '\n';
  std::cout << "6. " << '\n';

  // switch(choix){
  //   case 1: Agence::addClients();break; //ou save client?
  //   case 2: Agence::addGoods();break;
  //   case 3: Agence::proposition_achat();break;
  //   case 4: Agence::recherche();break;
  //   case 5: // save_clients ou pas le bon fichier?;break;
  //   case 6:
  //   default: std::cout << "Ce menu n'existe pas, essayez de nouveau svp." << '\n';break;
  // }
  return 0;
}
