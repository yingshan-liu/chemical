#include "utility.hh"
#include "molecule.hh"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
Molecule::Molecule(string a):forme_eclatee(a){
  atomes=split(a,"-=");
}
string Molecule::normalize() const{
  string strnor="";
  vector<string> atome;
  atome=atomes;
  sort(atome.begin(),atome.end());
  //for(auto iter:atome) cout<<iter;
  //cout<<endl;
  int count=1;
  string atom=atome[0];
  for(vector<string>::size_type i=1;i<atome.size();i++){
    if(atome[i]!=atom){
      if(count!=1)strnor=strnor+atom+to_string(count);
      else strnor=strnor+atom;
      count=1;
      atom=atome[i];
    }
    else{
      count++;
     }
    }
  if(count!=1)strnor=strnor+atom+to_string(count);
  else strnor=strnor+atom;
 
  return strnor;
}
ostream& operator<<(ostream& out,Molecule mole){
  out<<mole.normalize()<<endl;
  return out;
}
