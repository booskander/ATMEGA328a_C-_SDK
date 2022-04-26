#include <fstream>
#include "bibliotheque_cours.hpp"
#include <vector>
#include "classes.h"
#include "Affichable.h"
#include <memory>
#include <fstream>
#include <string>
using namespace std;
using UInt8  = uint8_t;
using UInt16 = uint16_t;

UInt8 lireUint8(std::istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(std::istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

std::string lireString(std::istream& fichier)
{
	std::string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), std::streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}

using namespace std;

void colorier(int couleur)
{
	cout << "\033[" << couleur << "m";
}

int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros("heros.bin", ios::binary);
	ifstream fichierVilains("vilains.bin", ios::binary);
	fichierHeros.exceptions(ios::failbit);
	fichierVilains.exceptions(ios::failbit);
	
	//TODO: Votre code pour le main commence ici
	// Initialisation des listes sous forme de std::vector
	vector<shared_ptr<Hero>> listeHeros;
	vector<shared_ptr<Vilain>> listeVilains;
	vector<shared_ptr<Personnage>> listePersonnages;
	//lecture des heros
	
	const unsigned int nbHeros = lireUint16(fichierHeros);
	for (unsigned int i = 0; i < nbHeros; i++)
	{
		string nom = lireString(fichierHeros);
		string parution = lireString(fichierHeros);
		string ennemi = lireString(fichierHeros);
		unsigned int nbAllies = lireUint8(fichierHeros);
		vector<string> allies;
		auto hero = make_shared<Hero>(nom, parution, ennemi);
		for (unsigned int j = 0; j < nbAllies; j++)
		{
			hero->ajouterAllie(lireString(fichierHeros));
		}
		listeHeros.push_back(hero);
	}
	

	const unsigned int nbVilains = lireUint16(fichierVilains);
	for (unsigned int i = 0; i < nbVilains; i++)
	{
		string nom = lireString(fichierVilains);
		string parution = lireString(fichierVilains);
		string objectif = lireString(fichierVilains);
		auto vilain = make_shared<Vilain>(nom, parution, objectif);
		listeVilains.push_back(vilain);
	}
	//Affichage des heros
	colorier(93);
	cout << '\n' << "AFFICHAGE DES HEROS" <<'\n'<< endl;
	for (auto&& h : listeHeros)
	{
		h->changerCouleur(cout, 94);
		h->afficher(cout);
		cout << "--------------------------------------------------------" << endl; //la constante trait fournie bug :(
	}
	colorier(93);
	cout << '\n' << "AFFICHAGE DES VILAINS" << '\n' << endl;
	for (auto&& v : listeVilains)
	{
		v->changerCouleur(cout, 91);
		v->afficher(cout);
		cout << "--------------------------------------------------------------" << endl;
	}
	
	//Remplissage de la liste de personnages a partir de la liste de heros
	for (auto&& h : listeHeros)
	{
		listePersonnages.push_back(h);
	}
	//Remplissage de la liste de personnages a partir de la liste de vilains
	for (auto&& v : listeVilains)
	{
		listePersonnages.push_back(v);
	}
	//Creation du VilainHero
	unsigned int vHero = 1;
	unsigned int hVilain = 2;
	
	if (listeHeros[vHero]->getEnnemi() == listeVilains[hVilain]->getNom())
		if(vHero != listeHeros.size())
			vHero++;
		else
		{
			hVilain--;
		}
		
	auto mVilainHero = make_shared<VilainHero>(listeHeros[vHero], listeVilains[hVilain]);
	colorier(93);
	cout << '\n' << "AFFICHAGE DU VILAINHERO" << '\n' << endl;
	mVilainHero->changerCouleur(cout, 95);
	mVilainHero->afficher(cout);
	cout << '\n' << "------------------------------------------------------" << endl;
	//Affectation du VilainHero a la liste de personnages

	listePersonnages.push_back(mVilainHero);
	colorier(93);
	//Affichage des personnages
	cout << '\n' << "AFFICHAGE DE TOUS LES PERSONNAGES" <<'\n' << endl;

	for (auto&& p : listePersonnages)
	{
		if (auto vilainHero = dynamic_cast<VilainHero*>(p.get()))
		{
			p->changerCouleur(cout, 95);
			p->afficher(cout);
			cout << '\n' << "------------------------------------------------------" << endl;

		}
		if (auto hero = dynamic_cast<Hero*>(p.get()))
		{
			p->changerCouleur(cout, 94);
			p->afficher(cout);
			cout << '\n' << "------------------------------------------------------" << endl;
		}
		if (auto vilain = dynamic_cast<Vilain*>(p.get()))
		{
			p->changerCouleur(cout, 91);
			p->afficher(cout);
			cout << '\n' << "------------------------------------------------------" << endl;
		}

	}

	colorier(97);
	cout << '\n' << "BY THE WAY!!!!!!!!!! le vilainHero s'afficher 3 fois lors de l'affichage " <<
		" des personnages, vu que mes dynamic_casts me permettent un affichage selon le type de l'élement"
		<< " de listePersonnages, puisque Vilain Hero est a la fois vilain, hero et vilainhero, il verifie mes trois "
		<< "conditions du coup... voila" << endl;
	
	
	
}
