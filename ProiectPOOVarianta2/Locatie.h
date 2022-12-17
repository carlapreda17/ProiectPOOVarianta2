#pragma once
#include <iostream>
#include <string>
using namespace std;
class Locatie
{
private:
	int id_locatie;
	const int nr_maxim_locuri=10000;
	int nr_randuri;
	int* nr_locuri_pe_rand;
	
public:
	Locatie();
	Locatie(int id_locatie, int nr_maxim_locuri, int nr_randuri, int* nr_locuri_pe_rand);
	Locatie(const Locatie& l);
	~Locatie();
	Locatie& operator=(const Locatie& l);

	//setteri+getteri
	void setIdLocatie(int id_loc);
	int getIdLocatie();
	void setNrRanduri(int nrRanduri);
	int getNrRanduri();
	void setNrLocuriPeRand(int* nr_locuri_pe_randNou, int nr_randuri);
	int* getNrLocuriPeRand();
	int getNrMaximLocuri();

	//metode
	bool validareNrLocuri();
	int** MatriceLocuri();

	//operatori
	int operator[](int index);
	bool operator!();

	//citire_afisare
	friend istream& operator>>(istream& in, Locatie& l);
	friend ostream& operator<<(ostream& out, Locatie l);
	
	
	
	
};

