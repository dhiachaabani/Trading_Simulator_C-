#include <iostream>
#include<vector>
#include<algorithm>
#include<ostream>
#include<istream>
#include<string>
#include<fstream>
#include<ctime>
#include<map>
using namespace std;

class Date
{
    unsigned short jour;
    unsigned short mois;
    unsigned short annee;
public:
    Date();
    Date(unsigned short,unsigned short,unsigned short);
    unsigned short getjour()const {return jour;};
    unsigned short getmois()const {return mois;};
    unsigned short getannee()const {return annee;};
    void setday(unsigned short);
    void setmonth(unsigned short);
    void setyear(unsigned short);
    bool verifdate();
    bool compare_date(Date df);
    friend ostream& operator<<(ostream& flux, Date& d );
    friend istream& operator>> (istream& flux , Date& d );
    friend  bool operator>(const Date& d1,const Date&d2) ;
    friend  bool operator==(const Date& d1,const Date& d2);
    friend bool operator< (const Date& d1,const Date &d2);
    Date operator++(int ){
            if (this->jour<31){this->jour++;}
                else if  (this->mois<12){this->mois++;this->jour=1;} else  {this->mois=1;this->jour=1;this->annee++;}return *this ;}
};

////////////////////////////////////////////////////////////

class Prixjournalier{
    Date dateprixjour;
    string nomaction;
    double prixaction;
public:
   Prixjournalier(Date, string,double);
Prixjournalier();
Date getdateprixjour()const {return dateprixjour;};
    string getnomaction()const {return nomaction;};
    double getprixaction()const{return prixaction;};
    void setprixaction(double);
    friend ostream& operator<<(ostream& flux,Prixjournalier& p);
    friend istream& operator>>(istream& flux,Prixjournalier& p);
};

//////////////////////////////////////////////////////////////////

class titre{
    string nomaction;
    int quantite;
    void ajouterquantite(int);
    void retirerquantite(int);
public:
    titre(string,int);
    int getquantite()const{return quantite;};
    string getnomactiontitre();
    friend ostream& operator<<(ostream& flux,titre& t);
    friend class Portefeuille;
    friend class simulation;

};

////////////////////////////////////////////////////////////////////////

class Portefeuille{


    string nomportefeuille;
    vector <titre*> portf ;
    double solde;
    int taille;
    void ajoutertitre(string,int);
    void ajoutersolde(double);
    void retirertitre(string,int);
public:
    Portefeuille(string);
    int indicetitre(string);
    int gettaille()const {return taille;};
    vector<titre*> getportf()const {return portf;};
    double getsolde(){return (double)solde;};
    friend ostream& operator<<(ostream& flux,Portefeuille &p);
    friend class simulation;
};

////////////////////////////////////////////////////////////

enum Typetransaction {acheter,vendre,rien};

class Transaction{
Typetransaction type;
string nomaction;
int quantite;
public:
    string getnomaction()const {return nomaction;};
    int getquantite()const {return quantite;};
    Typetransaction gettype()const {return type;};
    Transaction(){};
    Transaction(Typetransaction ,string ,int);
    friend ostream& operator <<(ostream& o,Transaction& t);
};

//////////////////////////////////////////////////////////////////////

class Bourse {
protected:
    Date datecourante;
public:
    Date getdatecourante()const{return datecourante;}
    Bourse(){}
    Bourse(Date d):datecourante(d){}
    virtual vector <Prixjournalier> listeactionperiode(Date,Date)=0;
    virtual  vector <Prixjournalier> listeactiondatecourante()=0;
    virtual vector<Prixjournalier>listeactiondate(Date)=0;
    virtual double donnerprixactiondate(string,Date)=0 ;
    friend class simulation;

};

/////////////////////////////////////////////////////////////////

class Boursemap : public Bourse {

    map<Date,vector<Prixjournalier>> mymap;
    public:
    Boursemap(Date d,vector<Prixjournalier>& h);
    Boursemap(){};
    vector <Prixjournalier> listeactionperiode(Date,Date);
    vector <Prixjournalier> listeactiondatecourante();
    vector<Prixjournalier>listeactiondate(Date);
    double donnerprixactiondate(string,Date) ;
    friend class simulation;

};
///////////////////////////////////////////////////////

class Boursevector: public Bourse {
    vector <Prixjournalier> b;
    public:

    Boursevector(){}
    Boursevector(Date d,vector<Prixjournalier>& h):Bourse(d),b(h){};
    vector <Prixjournalier> listeactionperiode(Date,Date);
    vector <Prixjournalier> listeactiondatecourante();
    vector<Prixjournalier>listeactiondate(Date);
    double donnerprixactiondate(string,Date) ;
        friend class simulation;

};

///////////////////////////////////////////////////////////

class trader {
public :
    string nomtrader ;
    trader(string m):nomtrader(m){};
    virtual Transaction fairechoix(Bourse &b,Portefeuille p)=0;
};

//////////////////////////////////////////////////////////////////////////////

class traderaleatoire :public trader{
public:
traderaleatoire(string j):trader(j){};
Transaction fairechoix(Bourse &b,Portefeuille p) ;
};
/////////////////////////////////////////////////////////////////////
class traderhumain:public trader{
public:
    Transaction fairechoix(Bourse& b,Portefeuille p);
traderhumain(string h):trader(h){};


};
///////////////////////////////////////
class traderalgorithmique2 :public trader{
public:
int verif;int verif2;
traderalgorithmique2(string m) :trader(m){verif=0;verif2=0;};
Transaction fairechoix(Bourse& b,Portefeuille p);
 friend class simulation;
};

////////////////////////////////////////////

class traderalgorithmique :public trader{
public:
int verif;int verif2;
traderalgorithmique(string m) :trader(m){verif=0;verif2=0;};
Transaction fairechoix(Bourse& b,Portefeuille p);
};

///////////////////////////////////////////////////////////////////////:
struct prixgreaterinverse
{
    bool operator()( const Prixjournalier& lx, const Prixjournalier& rx ) const {
    return lx.getprixaction()< rx.getprixaction();
    }
};
//////////////////////////////////////////////////////

struct prixgreater
{
    bool operator()( const Prixjournalier& lx, const Prixjournalier& rx ) const {
    return lx.getprixaction()> rx.getprixaction();
    }
};

/////////////////////////////////////////////////

class simulation {

     trader* trd;
     Date datedebut;
     Date datefin;
     Date datecourante ;
     Portefeuille portf ;
     double soldeinitial ;
     Bourse* boursee;
     void vendreaction (string,int);
     void acheteraction(string,int);
     void passerjoursuivant();
         void demanderchoixtrader();


public:
     simulation (trader*,Date ddep,Date dfin,double,Bourse*,Portefeuille );
     void lancersimulation();
     double calculgain();
     Date chercherdernierdatetrans(string);

};
////////////////////////////////////////
class gestionhistorique{
public:
static vector<Prixjournalier> creerhistorique();
};
