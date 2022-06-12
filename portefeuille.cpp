#include <iostream>
#include<vector>
#include<algorithm>
#include<ostream>
#include<istream>
#include<string>
#include<fstream>
#include<ctime>
#include<map>
#include"headers.h"

void Portefeuille::ajoutersolde(double f){
    solde+=f;}


ostream& operator<<(ostream& flux,Portefeuille& p) {flux<<"solde : "<<p.solde<<"  les titres: "<<endl;
      for (int i=0;i<p.portf.size();i++){
        flux<<*(p.portf[i]);}
        return flux;}
Portefeuille::Portefeuille(string np){
    nomportefeuille=np ;
    taille=0;
}
/////////////////////////////////////

///////////////////////////////////////////////////
int Portefeuille::indicetitre(string m){
    int indice;
    indice =-1;
    for(int i=0;i<portf.size();i++){
    string s=portf[i]->getnomactiontitre();

    if (s==m ){indice=i;};
};
    return indice ;
}

/////////////////////////////////////////////////

void Portefeuille::ajoutertitre(string m ,int q ){
     int a=indicetitre(m);
    if (a!=-1 )portf[a]->ajouterquantite(q) ;
    else {titre *t; t=new titre(m,q);
    this->portf.push_back(t);};
}
////////////////////////////////////////////////

void Portefeuille::retirertitre(string m ,int q ){
    int a=indicetitre(m);
if (a!=-1) {
        int b =portf[a]->getquantite();
        if (b<=q) portf.erase(portf.begin()+a);

         else{portf[a]->retirerquantite(q);
         };
         }
}
