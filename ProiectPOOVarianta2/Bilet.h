#pragma once
#include "Eveniment.h"
#include <iostream>
#include <string>
using namespace std;

class Eveniment;

class Bilet
{
private:
	static int bilete_totale;
	int id_bilet;
	int loc;
	string nume_eveniment;
	char* zona;
	Eveniment* e;

public:
	Bilet();
	Bilet(int id_bilet, int loc, string nume_eveniment, char* zona);
	Bilet(const Bilet& b);
	~Bilet();
	Bilet& operator=(const Bilet& b);


	void setIdBilet(int id_bilet_nou);
	int getIdBilet();
	void setLoc(int loc_nou);
	int getLoc();
	void setNumeEveniment(string NumeEveniment);
	string getNumeEveniment();
	void setZona(char* zonaNoua);
	char* getZona();


	int BileteDisponibile(Bilet& b);
	string ValidareIdUnic(Bilet& b);

	operator string();
	Bilet operator--(int i);

	friend istream& operator >> (istream& in, Bilet& b);
	friend ostream& operator<<(ostream& out, Bilet b);
	friend class Eveniment;

};