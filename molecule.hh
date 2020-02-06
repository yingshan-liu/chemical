#pragma once
#include "utility.hh"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Molecule{
public:
  Molecule(string a);
  vector<string> atomes;
  string forme_eclatee;
  //string forme_normal;
  string normalize() const;
  //friend ostream& operator<<(ostream& out,Molecule mole);
};
extern ostream& operator<<(ostream& out,Molecule mole);
