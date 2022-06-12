#include <iostream>
#include<vector>
using namespace std;

class titre
{public:
    string nom_action;
    int qauntite;
    titre(string,int);
    string  getnom_action();
    int getqauntite();
    void ajouter(int);
    void retirer(int);

};

titre::titre(string s,int q){
nom_action:s;
quantite=q;
}


string titre::getnom_action()
{
    return nom_action;
}
int titre::getqauntite()
{
    return qauntite;
}
void titre::ajouter(int data)
{
    this->qauntite+=data;
}
void titre::retirer(int data)
{
    this->qauntite-=data;
    if(this->qauntite<0)
       this->qauntite=0;

}

/////////////////////////////////////////////////
class Portefeuille
{
private:
    string nomportfeuille;
    titre *tab;
    int siz;
public:
    Portefeuille(string);
    int getsiz();
};
titre Portefeuille::gettitre()
{
    return *tab;
}

Portefeuille::Portefeuille(string np)
{nomportefeuille=np ;
 siz=0;
 tab=new titre;
}
int Portefeuille::getsiz()
{return siz;
}
//////////////////////////////////////////////////
class date
{public:

    int day;
    int month;
    int year;
    date(int,int,int);
    int getday();
    int getmonth();
    int getyear();
    void incrementerdate();


int date::getday()
{
    return day;
}
int date::getmonth()
{
    return month;
}
int date::getyear()
{
    return year;
}
date::date(int i,int j ,int k) {
day=i;month=j;year=k;
};

////////////////////////////////////////////////////////////////:
class prixjournalier
{public:

    date datecourant;
    string nomaction;
    float prixaction;
    date getdatecourant();
    string getnomaction();
    double getprix_action();
    prixjournalier(date,string,float);
};
date prixjournalier:: getdate_courant()
{
    return datecourant;
}
string prixjournalier::getnomaction()
{
    return nomaction;
}
double prixjournalier::getprix_action()
{
    return prixaction;
}
prixjournalier::prixjournalier(date d, string m , float f){
datecourant=d ;
nomaction=m ;
prixaction=f;
}

///////////////////////////////////

class trader {
public :
    nomtrader:string ;
    trader(string);
    virtual transaction fairechoix(*bourse,portefeuille )const; // retourne objet de type transaction
};
trader::trader (string m) {nomtrader=m;};
trader::fairechoix (*bourse,portefeuille) const {
transaction t (string typetransaction,string nomaction, int quantite);
return transaction ;
}

class traderhumain : public trader {
public :
    traderhumain(string );
    transaction fairechoix(*bourse,portefeuille )const{} ;

};
traderhumain::fairechoix
class traderalg :public trader{
   public:
       traderalg (string );
        transaction fairechoix(*bourse,portefeuille )const {};
};

/////////////////////////////////////////

class transaction{
public :
    string typetransaction  ; // le type de transacation est : passerdate , vendre ou acheter
    string nomaction ;
    int quantite  ;
    transaction (string,string,int);
};
transaction::transaction(string c,string f,int q){
typetransaction=c;
nomaction=f;
quantite=q ;
};

/////////////////////////////////////////

class bourse {
public:
    date datedebut;
    virtual float donnerprixaction(n,string)=0 ;               // le prix d'une action dans ce jour et les n derniers jours
    virtual vector <prixjournalier> donnerlisteactions(n)=0;   //liste des prix journaliers des n derniers jours
};
class boursevector :public bourse {
public :
    vector <prixjournalier> b;
    float donnerprixaction(n,string);
    void vector <prixjournalier> donnerlisteactions(n);
};
class boursedynamique :public bourse {};
/////////////////////////////////////////
class simulation {
     trader t ;
     date datedebut;
     int nombrejourssim;
     portefeuille p ;
     float solde ;
     bourse b  ;
     FILE* historique  ; // contient l'hitorique de la simulation
     simulation (trader,date,int,float,bourse,*FILE);
     transaction demanderchoixtrader();
     float calculgain();
     void vendreaction (string,int);
     void achteraction(string,int);
     void passerjoursuivant();
     void remplirhistoriquesim(historique);
     void fermersimulation();

};

simulation::simulation(trader a ,date d,int i,portfeuille v ,float f ,bourse q ,*FILE):
    t(a),p(v),b(q) {
datedebut =d;
solde=f;
};

simulation::acheteraction(string m ,int n){};
simulation::vendreaction(string m ,int n){};
simulation::passerjoursuivant(){datedebut.incrementerdate();}


simulation::demanderchoixtrader(){
transaction tr;

tr=this->t.fairechoix(*b,p);
switch (tr.typetransaction):
    case("passer"):
        *this.passerjoursuivant();

    case("vendre"):
        *this.vendreaction(tr.nomaction,tr.quantite);
    case("acheter"):
        *this.acheteraction(tr.nomaction,tr.quantite);
}


//////////////////////////////
