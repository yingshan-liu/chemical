#pragma once
//#include "molecule.hh"
//#include "utility.hh"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Reaction{
public:
  Reaction(string a);
  vector<Molecule> gauche;
  vector<Molecule> droit;
  string normalize() const;
  //friend ostream& operator<<(ostream& out,Reaction reac);
};
extern ostream& operator<<(ostream& out,Reaction reac);
