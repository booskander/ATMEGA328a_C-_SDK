#pragma once
#include <iostream>
#include <cppitertools/range.hpp>
#include <gsl/span>
#include <string>
#include "Affichable.h"
#include <vector>
using namespace iter;
using namespace gsl;
using namespace std;
//Implementation de la classe Personnage
class Personnage : public Affichable
{
protected:
	string nom_;
	string parution_;
public:
	Personnage() { nom_ = "Ïnconnu", parution_ = "Inconnu"; }
	Personnage(const string& nom, const string& parution)
		:
		nom_(nom), parution_(parution) {}
	void afficher(ostream& os) const override { os << "Nom : " << nom_ << '\n' << "Parution : " << parution_ << endl;}
	string getNom() const { return nom_; }
	string getParution() const { return parution_; }
	void changerCouleur(ostream& os, int couleur) const override { os << "\033[" << couleur << "m"; }
};


//Implementation de la classe Hero
class Hero :  virtual public Personnage
{
protected:
	vector<string> allies_;
	string ennemi_;
public:
	Hero() = default;
	Hero(const string& nom, const string& parution, const string& ennemi)
		: Personnage(nom, parution), ennemi_(ennemi) {}
	Hero(const shared_ptr<Hero> ptr)
		: Personnage(ptr->nom_, ptr->parution_), allies_(ptr->allies_) {}

	void afficherSpec(ostream& os) const { os << "Alliés : " << '\n'; for (auto&& allie : allies_) os << '\t' << allie << '\n'; }
	void afficher(ostream& os) const override { Personnage::afficher(os); afficherSpec(os); }
	vector<string> getAllies() const { return allies_; }
	void ajouterAllie(string al) { allies_.push_back(al); }
	string getEnnemi() const { return ennemi_; }

};


//Implementation de la classe Vilain
class Vilain : virtual public Personnage
{
protected:
	string objectif_;
public:
	Vilain() : Personnage(), objectif_("Inconnu") {};
	Vilain(const shared_ptr<Vilain> ptr)
		: Personnage(ptr->nom_, ptr->parution_), objectif_(ptr->objectif_) {}
	Vilain(const string& nom, const string& parution, const string& objectif)
		:
		Personnage(nom, parution), objectif_(objectif) {}
	void afficherSpec(ostream& os) const { os << "Objectif : " << objectif_ << endl; }
	void afficher(ostream& os) const override { Personnage::afficher(os); os << endl; afficherSpec(os); }
	string getObjectif() const { return objectif_; }
};


//Implementation de la classe VilainHero
class VilainHero : public Hero, Vilain
{
protected:
	string missionSpeciale_;
public:
	VilainHero() = default;
	VilainHero(const shared_ptr<Hero> h, const shared_ptr<Vilain> v)
		:
		Personnage(v->getNom() + "-" + h->getNom(), v->getParution() + "-" + h->getParution()),
		missionSpeciale_(v->getObjectif() + " dans le monde de " + h->getParution()), Hero(h), Vilain(v) {}
	void afficher(ostream& os) const override {
		Personnage::afficher(os); os << endl; Vilain::afficherSpec(os); os << endl; Hero::afficherSpec(os);
		os << "Mission spéciale: " << missionSpeciale_ << endl;
	}

};