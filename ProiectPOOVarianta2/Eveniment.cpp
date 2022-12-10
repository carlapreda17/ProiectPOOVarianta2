#include "Eveniment.h"
#include <iostream>
#include <string>
using namespace std;

string Eveniment::oras = "Bucuresti";

Eveniment::Eveniment() 
{

	this->locatie = "";
	this->data = "";
	this->ora = "";
	this->nume_eveniment = "";
	this->bilete_disponibile = 0;
}
Eveniment::Eveniment( string locatie, string data, string ora, string nume_eveniment, int bilete_disponibile)
{

	this->locatie = locatie;
	this->data = data;
	this->ora = ora;
	this->nume_eveniment = nume_eveniment;
	this->bilete_disponibile = bilete_disponibile;
}
Eveniment::Eveniment(const Eveniment& f)
{
	
	this->locatie = f.locatie;
	this->data = f.data;
	this->ora = f.ora;
	this->nume_eveniment = f.nume_eveniment;
	this->bilete_disponibile = f.bilete_disponibile;
}

//setteri si getteri
void Eveniment::setLocatie(string LocatieNoua)
{
	this->locatie = LocatieNoua;
}
string Eveniment::getLocatie()
{
	return this->locatie;
}
void Eveniment::setData(string DataNoua)
{
	this->data = DataNoua;
}
string Eveniment::getData()
{
	return this->data;
}

void Eveniment::setOra(string OraNoua)
{
	this->ora = OraNoua;
}

string Eveniment::getOra()
{
	return this->ora;
}

void Eveniment::setNumeEveniment(string NumeEvNou)
{
	this->nume_eveniment = NumeEvNou;
}

string Eveniment::getNumeEveniment()
{
	return this->nume_eveniment;
}
void Eveniment::setBileteDisp(int BileteDisp)
{
	this->bilete_disponibile = BileteDisp;
}
int Eveniment::getBileteDisp()
{
	return this->bilete_disponibile;
}

 void Eveniment::setOras(string orasNou)
{
	Eveniment::oras = orasNou;
}

 string Eveniment::getOras()
{
	return oras;
}
 
 //metoda statica
 string Eveniment::schimbareOras(Eveniment* e)
 {
	 string anunt;
	 anunt = "Va asteptam in " + e->oras + " pentru " + e->nume_eveniment + " la" + e->data + " ora:" + e->ora;
	 return anunt;
 }

 //metode generice

 string Eveniment::ValidareBilete(Eveniment& e)
 {
	 string validare = "bilet valid";
	 string incorect = "bilet invalid";
	 if (b.getIdBilet() > e.bilete_disponibile)
		 return incorect;
	 else
		 return validare;
 }

 string Eveniment::ValidareEveniment(Eveniment& e)
 {
	 string validare = "Felicitari! Biletul corespunde cu evenimentul";
	 string incorect = "Ne pare rau! Nu este evinemntul potrivit";
	 if (b.getNumeEveniment() == e.nume_eveniment)
	 {
		 return validare;
	 }
	 else return incorect;
	
 }


//supraincarcare operatori
 

 

 istream& operator>>(istream& in, Eveniment& f)
 {
	
	 in >> f.locatie;
	 in >> f.data;
	 in >> f.ora;
	 in >> f.bilete_disponibile;
	 in >> f.nume_eveniment;
	 return in;
 }
 ostream& operator<<(ostream& out, Eveniment f)
 {
	
	 out << f.locatie << endl;
	 out << f.oras<<endl;
	 out << f.data << endl;
	 out << f.ora << endl;
	 out << f.nume_eveniment << endl;
	 out << f.bilete_disponibile << endl;
	 return out;

 }
