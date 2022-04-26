#pragma once
#include <iostream>
#include <cppitertools/range.hpp>
#include <gsl/span>
#include <string>
using namespace iter;
using namespace gsl;
using namespace std;

class Affichable
{
public:
	virtual void afficher(ostream& os) const = 0;
	virtual void changerCouleur(ostream& os, int couleur) const = 0;
	~Affichable() = default;
	Affichable() = default;
};