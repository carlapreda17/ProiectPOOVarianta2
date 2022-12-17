#pragma once
#include "Eveniment.h"
#include <iostream>
#include <string>
using namespace std;



class Bilet
{
private:
	static int bilete_totale;
	int id_bilet;
	int loc;
	char* zona;
	Eveniment e;

public:

	//constructori
	Bilet();
	Bilet(int id_bilet, int loc, char* zona, Eveniment e);
	Bilet(const Bilet& b);
	~Bilet();
	Bilet& operator=(const Bilet& b);

	//setterisigetteri
	void setIdBilet(int id_bilet_nou);
	int getIdBilet();
	void setLoc(int loc_nou);
	int getLoc();
	void setZona(char* zonaNoua);
	char* getZona();

	//metode
	string ValidareBilete();
	int BileteDisponibile();
	
	//operatori
	Bilet operator--(int i);
	operator int();
	

	friend istream& operator >> (istream& in, Bilet& b);
	friend ostream& operator<<(ostream& out, Bilet b);
	

};