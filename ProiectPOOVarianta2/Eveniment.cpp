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
	Locatie l;
}
Eveniment::Eveniment( string locatie, string data, string ora, string nume_eveniment, int bilete_disponibile, Locatie l)
{

	this->locatie = locatie;
	this->data = data;
	this->ora = ora;
	this->nume_eveniment = nume_eveniment;
	this->bilete_disponibile = bilete_disponibile;
	this->l = l;
}
Eveniment::Eveniment(const Eveniment& f)
{
	
	this->locatie = f.locatie;
	this->data = f.data;
	this->ora = f.ora;
	this->nume_eveniment = f.nume_eveniment;
	this->bilete_disponibile = f.bilete_disponibile;
	this->l = l;
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
 
 string Eveniment:: ValidareSpatiu(Eveniment& e)
 {
	 string valid = "Spatiul este disponibil";
	 string invalid = "Spatiul este prea mic";
	 if (e.bilete_disponibile < l.getNrMaximLocuri())
	 {
		 return valid;
	 }
	 else
	 {
		 return invalid;
	 }

 }

 int Eveniment::Stadion_Arena(Eveniment& e)
 {
	 if (e.locatie == "Stadion_National_Arena")
	 {
		 e.bilete_disponibile = l.getNrMaximLocuri();
		 return e.bilete_disponibile;
	 }

}

//supraincarcare operatori
 
 Eveniment Eveniment::operator++(int i)
 {
	 Eveniment copie = *this;
	 this->bilete_disponibile++;
	 return copie;
 }


 Eveniment Eveniment::operator+(Eveniment f)
 {
	 Eveniment copie = *this;
	 copie.bilete_disponibile = bilete_disponibile + f.bilete_disponibile;
	 return copie;
 }

 istream&  operator>>(istream& in, Eveniment& f)
 {
	cout<<"Nume locatie : ";
	 in >> f.locatie;
	 cout << "Data eveniment: ";
	 in >> f.data;
	 cout << "Ora eveniment: ";
	 in >> f.ora;
	 cout << "Nume eveniment: ";
	 in >> f.nume_eveniment;
	 cout << "Bilete disponibile ";
	 in >> f.bilete_disponibile;
	 return in;
 }
 ostream& operator<<(ostream& out, Eveniment f)
 {
	 out <<"Oras: "<< f.oras << endl;
	 out <<"Nume locatie : "<< f.locatie << endl;
	 out <<"Data eveniment: "<< f.data << endl;
	 out << "Ora eveniment: "<<f.ora << endl;
	 out << "Nume eveniment: "<<f.nume_eveniment << endl;
	 out << "Bilete disponibile "<<f.bilete_disponibile << endl;
	 return out;

 }
