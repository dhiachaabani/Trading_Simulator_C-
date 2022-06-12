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
double Boursevector::donnerprixactiondate(string nmact,Date d){
    vector<Prixjournalier> v=listeactiondatecourante();
    for (int i=0;i<v.size();i++){
        if (nmact==v[i].getnomaction()){return v[i].getprixaction();}
}
}

/////////////////////////////////////////////////////////////////

vector<Prixjournalier> Boursevector::listeactiondate(Date d){
    vector<Prixjournalier> v;
    for (int i=0;i<b.size();i++){
    if ((d<datecourante)&&(d==b[i].getdateprixjour())){v.push_back(b[i]);}
    if ((d< b[i].getdateprixjour())||(datecourante<d)){break;}
}
return v;
}
//////////////////////////////////////////////////////////////////////

vector<Prixjournalier> Boursevector::listeactiondatecourante(){
    vector<Prixjournalier> v;
    cout<<datecourante<<endl;
    for (int i=0;i<b.size();i++){Date s=b[i].getdateprixjour();
    if (s==datecourante){v.push_back(b[i]);}

}
return v;
}
///////////////////////////////////////////////////////////////////////////

vector<Prixjournalier> Boursevector::listeactionperiode(Date deb,Date fin){
    vector<Prixjournalier> v;
for (int i=0;i<b.size();i++){
        if(((deb<b[i].getdateprixjour()))&&((b[i].getdateprixjour()<fin)||b[i].getdateprixjour()==fin))
           {v.push_back(b[i]);}

}
return v;
}
