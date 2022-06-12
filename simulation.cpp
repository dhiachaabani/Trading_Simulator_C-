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

/////////////////////////////////////////////////////////


Date simulation::chercherdernierdatetrans(string m){
vector<Prixjournalier> v; v=boursee->listeactionperiode(datedebut,datefin) ;
for (int i=v.size()-1;i>-1;i--){
    if( v[i].getnomaction()== m){ return v[i].getdateprixjour() ;}
}
}

/////////////////////////////////////////

double simulation::calculgain() {
    double gain=0;
    vector<titre*> v= portf.getportf();
    for (int i=0;i<v.size();i++) {
    string  m=v[i]->getnomactiontitre();
    Date d = chercherdernierdatetrans(m);
    double x=boursee->donnerprixactiondate(m,d);
    gain+= v[i]->getquantite() *x;
}
    gain+= portf.solde-soldeinitial;

    return gain;
}


//////////////////////////////////////////////////

void simulation::lancersimulation(){
    do {demanderchoixtrader();
   cout<<"                         VOICI VOTRE PORTEFEUILLE          " <<
   endl<<"-----------------------------------------------------------------------------"     /// juste pour voir les resultat en executant un trader aeatoire ou un trader
  <<portf<<

endl<<"-----------------------------------------------------------------------------"<<endl;
   cout<<"    La Datecourante    :" << datecourante<<endl<<endl;
        }
while ((datecourante<datefin)||(datecourante==datefin));
};

////////////////////////////////////////////////////////

void simulation::demanderchoixtrader(){
 Transaction y ;y=trd->fairechoix(*boursee,portf);
    if (y.gettype()==acheter){
    acheteraction(y.getnomaction(),y.getquantite());
}
    if (y.gettype()==vendre){
    vendreaction(y.getnomaction(),y.getquantite());
}
    if(y.gettype()==rien) {passerjoursuivant();
};
}
///////////////////////////////////////////////////////////

void simulation::acheteraction(string m ,int n){
vector<Prixjournalier> v= boursee->listeactiondatecourante();
    int a=portf.getsolde();
    double q;
    for (int i=0;i<v.size();i++){
        q= n*(v[i].getprixaction());
            if ((v[i].getnomaction()==m)&&(a>=q))
        {
            portf.ajoutertitre(m,n);
            portf.solde-=q;
            break;
        }
        }
};

////////////////////////////////////////////////////////////

void simulation::vendreaction(string m ,int n){
    vector<titre*> v=portf.getportf();
    vector<Prixjournalier> r=boursee->listeactiondatecourante();
    double q;
    for (int i=0;i<v.size();i++){
        if ((v[i]->getnomactiontitre()==m)&&(v[i]->getquantite()>=n)){
            for (int  j=0;j<r.size();j++)
            {
                if ((r[j].getnomaction()==m)){
                        q=n*(r[j].getprixaction());
                        portf.ajoutersolde(q); portf.retirertitre(m,n); break;
                }
                }
                break;}
                               }
};

simulation::simulation(trader* t,Date ddep,Date dfin,double s,Bourse* b,Portefeuille p)
:trd(t),datedebut(ddep),datefin(dfin),boursee(b),portf(p){
    soldeinitial=s;datecourante=ddep; portf.solde=s;
}

//////////////////////////////////////////////////////

void simulation::passerjoursuivant(){
   datecourante++;boursee->datecourante++;
}
