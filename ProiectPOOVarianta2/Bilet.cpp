#include "Bilet.h"
#include "Eveniment.h"
#include <iostream>
#include <string>
using namespace std;

int Bilet::bilete_totale = 0;

Bilet::Bilet()
{
	Bilet::bilete_totale++;
	this->id_bilet = bilete_totale;
	this->loc = 0;
	this->zona = new char[1];
	strcpy_s(zona, 1, "");
	Eveniment e;

}

Bilet::Bilet(int id_bilet, int loc, char* zona, Eveniment e):Bilet()
{
	
	this->loc = loc;
	if (zona != nullptr) {
		this->zona = new char[strlen(zona) + 1];
		strcpy_s(this->zona, strlen(zona) + 1, zona);
	}
	this->e = e;
}

Bilet:: Bilet (const Bilet& b)
{
	this->id_bilet = b.id_bilet;
	this->loc = b.loc;
	if (b.zona != nullptr)
	{
		this->zona = new char[strlen(b.zona) + 1];
		strcpy_s(this->zona, strlen(b.zona) + 1, b.zona);
	}
	this->e = b.e;
}


Bilet::~Bilet()
{
	delete[] this->zona;
	
}

//operator egal

Bilet& Bilet::operator=(const Bilet& b)
{
	if (this != &b)
	{
		delete[] this->zona;
		this->id_bilet = b.id_bilet;
		this->loc = b.loc;
		if (b.zona != nullptr)
		{
			this->zona = new char[strlen(b.zona) + 1];
			strcpy_s(this->zona, strlen(b.zona) + 1, b.zona);
		}
	}
	this->e = b.e;
	return *this;
}




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
	if (b.id_bilet < e.getBileteDisp())
		return e.getBileteDisp() - b.id_bilet;
	else
		return 0;
}


string Bilet::ValidareBilete(Bilet& b)
{
	string validare = "bilet valid";
	string incorect = "bilet invalid";
	if(b.id_bilet>e.getBileteDisp())
		return incorect;
	else
		return validare;
}



//supraincarcare operatori

Bilet Bilet::operator--(int i)
{
	Bilet copie = *this;
	this->id_bilet--;
	return copie;
}


Bilet::operator int()
{
	return id_bilet;
}




istream& operator >> (istream& in, Bilet& b)
{
	in >> b.loc;

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
	if (b.zona != nullptr)
		out << b.zona << endl;
	out << endl;
	return out;
}

