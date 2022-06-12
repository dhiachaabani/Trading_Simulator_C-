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


Boursemap::Boursemap(Date d,vector<Prixjournalier>& h):Bourse(d){
    int i=0;
    int n=h.size()-1;

    Date test;Date test2;
    do {
    test = h[i].getdateprixjour();
    test2 = h[i].getdateprixjour();

    vector<Prixjournalier> v;
    do { v.push_back(h[i]);i++; test= h[i].getdateprixjour();
}
    while (test2==test);
    mymap[test2]=v;

}
    while (test2<h[n-1].getdateprixjour());

}

//////////////////////////////////////////////////////////////////////

vector <Prixjournalier>  Boursemap::listeactionperiode(Date dd,Date df){
    vector<Prixjournalier> v;
for (auto x=mymap.cbegin() ;x!=mymap.cend();++x) {
        //Date cle=x->first; vector <Prixjournalier> val=x->second; cout<<cle<<endl; for (int i=0;i<val.size();i++){cout<<val[i]<<endl;}
        if((( x->first==df )||(x->first<df))&&( (x->first==dd)||(x->first>dd)  ))
            {for (int j=0;j<x->second.size();j++){
                    v.push_back(x->second[j]);}}

}
v.pop_back();
return v;

};

////////////////////////////////////////////////////////////////

vector <Prixjournalier> Boursemap::listeactiondatecourante(){

    vector<Prixjournalier> v;
    for (auto x=mymap.cbegin() ;x!=mymap.cend();++x) {if (x->first==datecourante){
        {for (int j=0;j<x->second.size();j++){
                    v.push_back(x->second[j]);}} break;

}
}
    return v;
};
//////////////////////////////////////////////////////////

vector<Prixjournalier>Boursemap::listeactiondate(Date d){
    vector<Prixjournalier> v;
    for (auto x=mymap.cbegin() ;x!=mymap.cend();++x) {
            if (x->first==d){
                for (int j=0;j<x->second.size();j++){
                    v.push_back(x->second[j]);}
            break;}
    return v;

}};
//////////////////////////////////////////////////////////////

double Boursemap::donnerprixactiondate(string nmact ,Date d){
  vector<Prixjournalier> v=listeactiondatecourante();
    for (int i=0;i<v.size();i++){
        if (nmact==v[i].getnomaction()){return v[i].getprixaction();
        }
}
};
