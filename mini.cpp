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
using namespace std;

 bool operator==(const Date& d1,const Date& d2){
        if ((d1.getannee()==d2.getannee())&&(d1.getmois()==d2.getmois())&&(d1.getjour()==d2.getjour())){return true ;}
        else{return false;}
    };
bool operator< (const Date& d1,const Date &d2){
if( d1.getannee()<d2.getannee() ) {return true ;}
        else if (d1.getannee()==d2.getannee())
        {
            if (d1.getmois()<d2.getmois()) {return true ;}


        else if (d1.getmois()==d2.getmois()){if (d1.getjour()<d2.getjour()) {return true ;}}

    }
    return false;};

/*---------------------------------------------------------------------*/
/*bool operator==(Date d,Date r){
 if ((d.getannee()==r.getannee())&&(d.getmois()==r.getmois())&&(d.getjour()==r.getjour())){return true ;}
 else{return false;}
}*/
ostream& operator <<(ostream& flux , Date& d ){
flux<<d.jour<<'/'<<d.mois<<'/'<<d.annee;
return flux;
}
bool operator> ( const Date& d1,const Date& d2) {
    if( d1.getannee()>d2.getannee() ) {return true ;}
        else if (d1.getannee()==d2.getannee())
        {
            if (d1.getmois()>d2.getmois()) {return true ;}


        else if (d1.getmois()==d2.getmois()){if (d1.getjour()>d2.getjour()) {return true ;}}

    }
    return false;}


istream& operator>> (istream& flux , Date& d ){
char tmp[1000];
flux.getline(tmp,1000,'/');
d.jour= atoi(tmp);
flux.getline(tmp,1000,'/');
d.mois=atoi(tmp);
flux.getline(tmp,1000,';');
d.annee=atoi(tmp);
return flux;
}
Date::Date(){}
Date::Date(unsigned short j,unsigned short m,unsigned short a){
    if ((j<32)&&(j>=0)) {jour=j;}
    if ((m<13)&&(m>=0) ){mois=m;}
    if ((a<2023)&&(a>=1950)) {annee=a;}
}
void Date::setday(unsigned short d){
    jour=d;
}
void Date::setmonth(unsigned short m){
    mois=m;
}
void Date::setyear(unsigned short y){
    annee=y;
}
//////////////////////////////////////////////
Prixjournalier::Prixjournalier(){}
Prixjournalier::Prixjournalier(Date d ,string n,double p):dateprixjour(d){nomaction=n;prixaction=p;}
ostream& operator<<(ostream& flux,Prixjournalier& p){
flux<<p.dateprixjour<<"--"<<p.nomaction<<"--"<<p.prixaction;
return flux;
}
istream& operator>>(istream& flux,Prixjournalier& p){
flux>>p.dateprixjour;char tmp[1000];
flux.getline(tmp,1000,';');
p.nomaction=tmp;
flux>>p.prixaction;
return flux ;
}
/*----------------------------------------*/

///////////////////////////////////////////////////////////////////////

string titre::getnomactiontitre(){return nomaction;};

ostream& operator<<(ostream& flux,titre& t) {flux<<"nom del'action: "<<t.nomaction<<", "<<"quantite: "<<t.quantite<<endl;
    return flux;
    }
titre::titre(string s,int q){
nomaction=s;
quantite=q;
}
void titre::ajouterquantite(int data){
    this->quantite+=data;
}
void titre::retirerquantite(int data){
    this->quantite-=data;
    if(this->quantite<0)
      {this->quantite=0;

      }

}

///////////////////////////////////////////////


Transaction::Transaction(Typetransaction c,string f,int q){
type=c;
nomaction=f;
quantite=q ;
};
ostream& operator <<(ostream& o,Transaction& t){
o<<"Type de transaction: "<<t.type<<" ,"<<"nomaction : "<<t.nomaction<<" , quantite: "<<t.quantite<<endl;
return o;}

//////////////////////////////////////////

 vector<Prixjournalier> gestionhistorique::creerhistorique(){
    vector<Prixjournalier> his;
    ifstream fichier("prices_simple.csv");
    string premiereligne ; //pour enlever la premiere ligne
    if(fichier.is_open()){
        fichier>>premiereligne;

    while (!fichier.eof()){
        Prixjournalier p;
        fichier>>p;
        his.push_back(p);
    }
    }
    return his;
}


