#include "molecule.hh"
#include "reaction.hh"
#include "utility.hh"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
Reaction::Reaction(string a){
  /*
 char* point=const_cast<char*>(a.c_str());
  string obj="";
   while((*point)!='>'){
    while((*point)!='+'&&(*point)!='>'){
      obj=obj+*point;
      point++;
    }
    Molecule lire(obj);
    gauche.push_back(lire);
   }
   point++;
   while((*point)!='\0'){
    while((*point)!='+'&&(*point)!='\0'){
      obj=obj+*point;
      point++;
    }
    Molecule lire(obj);
    droit.push_back(lire);
  }
  
  */
  vector<string> reaction=split(a,">");
  vector<string> gauche1;
  vector<string> droit1;
  gauche1=split(reaction[0]," + ");
  droit1=split(reaction[1]," + ");
  for(const auto& iter:gauche1)
    gauche.push_back(Molecule(iter));
  for(const auto& iter:droit1)
    droit.push_back(Molecule(iter));
  
}
string Reaction::normalize() const{
  string norm="";
  for(vector<Molecule>::size_type i=0;i<gauche.size();i++){
    if(i==(gauche.size()-1)) norm=norm+gauche[i].normalize()+"->";
    else norm=norm+gauche[i].normalize()+"+";
  }
  for(vector<Molecule>::size_type i=0;i<droit.size();i++){
    if(i==(droit.size()-1)) norm=norm+droit[i].normalize();
    else norm=norm+droit[i].normalize()+"+";
  }
  return norm;
}
ostream& operator<<(ostream& out,Reaction reac){
  out<<reac.normalize()<<endl;
  return out;
}
