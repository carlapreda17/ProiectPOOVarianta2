#pragma once
#include "Locatie.h"
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
	Locatie l;

public:

	//constructori
	Eveniment();
	Eveniment(string locatie, string data, string ora, string nume_eveniment, int bilete_disponibile, Locatie l);
	Eveniment(const Eveniment& f);

	//setteri+getteri
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

	//metoda statica
	static string schimbareOras(Eveniment* e);

	//metode
	string ValidareSpatiu();
	int Stadion_Arena();


	//operatori
	Eveniment operator++(int i);
	Eveniment operator+(Eveniment f);

	//citire_afisare
	friend istream& operator>>(istream& in, Eveniment& f);
	friend ostream& operator<<(ostream& out, Eveniment f);
	

}; 


