#include "Bilet.h"

#include <iostream>
#include <string>
using namespace std;

int Bilet::bilete_totale = 0;

Bilet::Bilet()
{
	Bilet::bilete_totale++;
	this->id_bilet = bilete_totale;
	this->loc = 0;
	this->nume_eveniment = "";
	this->zona = new char[1];
	strcpy_s(zona, 1, "");

}

Bilet::Bilet(int id_bilet, int loc, string nume_eveniment, char* zona):Bilet()
{
	
	this->loc = loc;
	this->nume_eveniment = nume_eveniment;
	if (zona != nullptr) {
		this->zona = new char[strlen(zona) + 1];
		strcpy_s(this->zona, strlen(zona) + 1, zona);
	}
}

Bilet:: Bilet (const Bilet& b)
{
	this->id_bilet = b.id_bilet;
	this->loc = b.loc;
	this->nume_eveniment = b.nume_eveniment;
	if (b.zona != nullptr)
	{
		this->zona = new char[strlen(b.zona) + 1];
		strcpy_s(this->zona, strlen(b.zona) + 1, b.zona);
	}
}

Bilet::~Bilet()
{
	delete[] this->zona;
}

//operator egal


//setteri si getteri
void Bilet::setIdBilet(int id_bilet_nou)
{
	this->id_bilet = id_bilet_nou;
}

int Bilet::getIdBilet()
{
	return this->id_bilet;
}

void Bilet::setLoc(int loc_nou)
{
	this->loc = loc_nou;
}

int Bilet::getLoc()
{
	return this->loc;
}

void Bilet::setNumeEveniment(string NumeEveniment)
{
	this->nume_eveniment = NumeEveniment;
}

string Bilet::getNumeEveniment()
{
	return this->nume_eveniment;
}

void Bilet::setZona(char* zonaNoua)
{
	if (zonaNoua != nullptr)
	{
		this->zona = new char[strlen(zonaNoua) + 1];
		strcpy_s(this->zona, strlen(zonaNoua) + 1, zonaNoua);
	}
}

char* Bilet::getZona()
{
	return this->zona;
}

//metode generice

int Bilet::BileteDisponibile(Bilet& b)
{
	if (b.id_bilet < e.bilete_disponibile)
		return e.bilete_disponibile - b.id_bilet;
	else
		return 0;
}



//supraincarcare operatori

Bilet::operator string()
{
	return  nume_eveniment;
}

//+operator --

istream& operator >> (istream& in, Bilet& b)
{
	in >> b.loc;
	in >> b.nume_eveniment;
	delete[] b.zona;
	char sir[100];
	in >> sir;
	b.zona = new char[strlen(sir) + 1];
	strcpy_s(b.zona, strlen(sir) + 1, sir);

	return in;
}

ostream& operator<<(ostream& out, Bilet b)
{
	out << b.id_bilet << endl;
	out << b.loc << endl;
	out << b.nume_eveniment << endl;
	if (b.zona != nullptr)
		out << b.zona << endl;
	out << endl;
	return out;
}

