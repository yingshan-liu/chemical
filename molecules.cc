#include "molecule.hh"
#include "reaction.hh"
#include "utility.hh"
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
  cout << "*** Exercice 1 ***" << endl;
  ifstream file("molecules.txt");
  ofstream res_file("res_normalisation.txt");
  list<Molecule> les_molecules;
  string s;
  string s2;
  while( file >> s)//passer data de file a s
    {
      les_molecules.push_back(Molecule(s));
    }
  
  for(auto& iter : les_molecules)
     {
       cout << iter.normalize() << std::endl;
       res_file<<iter.normalize()<<endl;
     }
  file.close();
  res_file.close();
  
 
  cout << "*** Exercice 2 ***" << endl;
  file.open("reactions.txt");
  ofstream reac_file("res_reaction.txt");
  list<Reaction> lesReactions;

  while(getline(file,s))
    {
      if(!s.empty())
	lesReactions.push_back(Reaction(s));
    }
   for(const  auto& iter : lesReactions)
   {
     std::cout << iter.normalize() << endl;
     reac_file<<iter.normalize()<<endl;
   }

  file.close();
  reac_file.close();
  cout<<"******Bonus*******"<<endl;
  for(const auto& iter: les_molecules)
    cout<<iter;
  for(const auto& iter: lesReactions)
    cout<<iter;
  return 0;
}
