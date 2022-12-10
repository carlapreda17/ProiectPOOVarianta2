#pragma once
#include "Bilet.h"
#include <iostream>
#include <string>
using namespace std;
class Eveniment
{
private:
	
	string locatie;
	static string oras;
	string data;
	string ora;
	string nume_eveniment;
	int bilete_disponibile;
	//Bilet b;


public:

	
	Eveniment();
	Eveniment(string locatie, string data, string ora, string nume_eveniment, int bilete_disponibile);
	Eveniment(const Eveniment& f);


	void setLocatie(string LocatieNoua);
	string getLocatie();
	void setData(string DataNoua);
	string getData();
	void setOra(string OraNoua);
	string getOra();
	void setNumeEveniment(string NumeEveniment);
	string getNumeEveniment();
	void setBileteDisp(int BileteDisp);
	int getBileteDisp();
	static void setOras(string orasNou);
	static string getOras();

	static string schimbareOras(Eveniment* e);

//	string ValidareBilete(Eveniment& e);
//string ValidareEveniment(Eveniment& e);


	

	friend istream& operator>>(istream& in, Eveniment& f);
	friend ostream& operator<<(ostream& out, Eveniment f);
	friend class Bilet;

}; 


