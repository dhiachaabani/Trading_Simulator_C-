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

Transaction traderhumain::fairechoix(Bourse& b,Portefeuille p){
cout<<"taper 0 pour choisir une transaction"<<endl;
cout<<"taper 1 pour consulter votre portefeuille "<<endl;
cout<<"taper 2 pour consulter les axtions diponibles aujourd'hui "<<endl;

string s,t; int sz;int q;Typetransaction ty;
cin>>sz;
vector<Prixjournalier> v=b.listeactiondatecourante();
if( v.size()!=0 ){

if (sz==0){}
if (sz==1) {
                        cout<<endl<<"-----------------------------------------------------------------------------"                 /// juste pour voir les resultat en executant un trader aeatoire par exemple
                        <<endl<<p<<endl<<"-----------------------------------------------------------------------------"<<endl;
            }
if (sz==2){
        for (int i=0;i<v.size();i++){cout<<v[i]<<endl; }
            for (int i=0;i<v.size();i++){
            cout<<v[i]<<endl;}
          }
do {
cout<<"  Choisir le type votre transaction: ";
cin>>t;} while((t!="acheter")&&(t!="vendre")&&(t!="rien"));
if (t=="acheter"){ty=acheter;
cout<<"l'action que vous voulez acheter: ";
cin>>s; cout<<"la quantite :";cin>>q;
Transaction tr(ty,s,q);return tr;}
if (t=="vendre") {ty=vendre;cout<<"l'action que vous voulez vendre :";
cin>>s;cout<<" la quantite :";cin>>q;
Transaction tr(ty,s,q);cout<<tr<<endl;return tr;}
if (t=="rien"){ty=rien ;cout<<endl<<"on passe au jour suivant "<<endl; Transaction tr(ty," ",0);return tr; }
}
else {ty=rien ;Transaction tr(ty," ",0);return tr;}
}

///////////////////////////////////////////////////////////////

Transaction traderalgorithmique::fairechoix(Bourse& b ,Portefeuille p){
Typetransaction tp;
int n, qvente;
double q;
vector<Prixjournalier> v=b.listeactiondatecourante();
std::sort( v.begin(), v.end(), prixgreater() );
if (v.size()!=0){
if( (verif ==0 )&&(verif2==0)){

q=(p.getsolde())*0.07;
n=(int)q/(v[0].getprixaction());
tp=acheter;
Transaction t(tp,v[0].getnomaction(),n);
verif =1;
return t;
}

if((verif==1)&&(verif2==0)){

vector<Prixjournalier> test;

vector<titre*> vec=p.getportf() ;
for (int k=0;k<vec.size();k++){
        for (int y=0;y<v.size();y++){
if (vec[k]->getnomactiontitre()==v[y].getnomaction()){
        test.push_back(v[y]); break;}
}
}
std::sort(test.begin(), test.end(), prixgreater() );
q=(p.getsolde())*0.05;
n=(int)q/(test[test.size()-1].getprixaction());
if (test.size()!=0){ tp=vendre; Transaction t (tp,test[test.size()-1].getnomaction() ,n) ;verif2=1;verif=0;
return t;
}
}
else {tp=rien;Transaction t (tp," " ,0) ;verif2=0;return t;}
}
else {tp=rien;Transaction t (tp," " ,0) ;verif2=0;return t;}
 }

 ////////////////////////////////////////////////////////////////


 Transaction traderalgorithmique2::fairechoix(Bourse& b ,Portefeuille p){
Typetransaction tp;
int n, qvente;
double q;
vector<Prixjournalier> v=b.listeactiondatecourante();
std::sort( v.begin(), v.end(), prixgreaterinverse() );
if (v.size()!=0){
if( (verif ==0 )&&(verif2==0)){

q=(p.getsolde())*0.07;
n=(int)q/(v[0].getprixaction());
tp=acheter;
Transaction t(tp,v[0].getnomaction(),n);
verif =1;
return t;
}

if((verif==1)&&(verif2==0)){

vector<Prixjournalier> test;

vector<titre*> vec=p.getportf() ;
for (int k=0;k<vec.size();k++){
        for (int y=0;y<v.size();y++){
if (vec[k]->getnomactiontitre()==v[y].getnomaction()){
        test.push_back(v[y]); break;}
}
}
std::sort(test.begin(), test.end(), prixgreater() );
q=(p.getsolde())*0.05;
n=(int)q/(test[test.size()-1].getprixaction());
if (test.size()!=0){ tp=vendre; Transaction t (tp,test[test.size()-1].getnomaction() ,n) ;verif2=1;verif=0;
return t;
}
}
else {tp=rien;Transaction t (tp," " ,0) ;verif2=0;return t;}
}
else {tp=rien;Transaction t (tp," " ,0) ;verif2=0;return t;}
 }

//////////////////////////////////////////

Transaction traderaleatoire:: fairechoix(Bourse &b,Portefeuille p) {
int c,i ;
Typetransaction t;
vector<Prixjournalier> v =b.listeactiondatecourante();
if( v.size() !=0) {
c=rand() % 3;

if (c==1){

t=vendre;
vector<titre*> pp =p.getportf();

if (p.getportf().size()!=0){
    i=rand()%(pp.size());
    string action = pp[i]->getnomactiontitre();
    int quantity; quantity= rand()% (p.getportf()[i]->getquantite()+1 ) ;
    Transaction tr(t,action,quantity);
    return tr; }
}


if (c==0){
t=acheter;
int quantity;
int i =rand()% (v.size());
string action =v[i].getnomaction();
if (p.getsolde()!=0){
int qu=(int) (p.getsolde()/v[i].getprixaction());
quantity=rand()% (qu + 1);
}
Transaction tr(t,action,quantity);
return tr ;
}
if (c==2){
t=rien; Transaction tr (t," ",0);
return tr;
}
                    }


else {t=rien;Transaction tr (t," ",0);
return tr;
}
}
