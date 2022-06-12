#include <iostream>
#include<vector>
#include<algorithm>
#include<ostream>
#include<istream>
#include<string>
#include<fstream>
#include<ctime>
#include<stdlib.h>
#include<map>
#include"headers.h"
using namespace std;


int main(){
system (" color 5F ");
Date dep,fin;  int a,b; trader * tr; Bourse *brs;cout<<endl<<endl<<"                                         Simulatuer De Trading                           "<<endl<<endl;
cout<<"   Choisir Un trader:" <<endl<<"    0 : Trader Humain "<<endl <<"    1 : Trader Aleatoire "<<endl <<"    2 : Trader intelligent.1 "<<endl<<"    3 : Trader intelligent.2"<<endl;
cin>>a;
if (a==0) {tr =new traderhumain("Hum");}
else if (a==1) {tr=new traderaleatoire("Alea");}
else if (a==2) {tr=new traderalgorithmique("alea");}
else {tr=new traderalgorithmique2("Algo");}
do {
cout<<"   Saisir la date de debut du simulation (././.;)" ;
cin>>dep;
cout<<"   Saisir la date de fin du simulation (././.;)" ;
cin>>fin;} while (fin<dep);
vector<Prixjournalier> his =gestionhistorique::creerhistorique();
Portefeuille p(" ");
cout<<"   Choisir La Bourse : " <<endl<<"    0 : Bourse Vector "<<endl<<"    1 : Bourse Map "<<endl;
cin>>b;
if (b==0){
 brs =new Boursemap(dep,his);}
else {
brs =new Boursemap(dep,his);}
simulation s(tr,dep,fin,700000,brs,p);
s.lancersimulation();
cout<<endl<<"   Votre gain est de :  "<<s.calculgain()<< endl<<"        FIN DE LA SIMULATION     "<<endl; ;

return 0 ;


}


