#include "Locatie.h"
#include <iostream>
#include <string>
using namespace std;
Locatie::Locatie()
{
	id_locatie = 0;
	nr_randuri = 0;
	this->nr_locuri_pe_rand = nullptr;
}

Locatie::Locatie(int id_locatie, int nr_maxim_locuri, int nr_randuri, int* nr_locuri_pe_rand) :nr_maxim_locuri(nr_maxim_locuri)
{
	this->id_locatie = id_locatie;
	if (nr_locuri_pe_rand != nullptr && nr_randuri > 0)
	{
		this->nr_locuri_pe_rand = new int[nr_randuri];
		for (int i = 0; i < nr_randuri; i++)
		{
			this->nr_locuri_pe_rand[i] = nr_locuri_pe_rand[i];

		}
		this->nr_randuri = nr_randuri;
	}
}

Locatie::Locatie(const Locatie& l) :nr_maxim_locuri(l.nr_maxim_locuri)
{
	this->id_locatie = l.id_locatie;
	
	if (l.nr_locuri_pe_rand != nullptr && l.nr_randuri > 0)
	{
		this->nr_locuri_pe_rand = new int[l.nr_randuri];
		for (int i = 0; i < l.nr_randuri; i++)
		{
			this->nr_locuri_pe_rand[i] = l.nr_locuri_pe_rand[i];

		}
		this->nr_randuri = l.nr_randuri;
	}
}

//destructor
Locatie::~Locatie() 
{
	delete[] this->nr_locuri_pe_rand;
}

//opertaor egal



//getter setteri
void Locatie::setIdLocatie(int id_loc)
{
	this->id_locatie = id_loc;
}
int Locatie::getIdLocatie()
{
	return this->id_locatie;
}
void Locatie::setNrRanduri(int nrRanduri)
{
	this->nr_randuri = nrRanduri;
}
int Locatie::getNrRanduri()
{
	return this->nr_randuri;
}
void Locatie::setNrLocuriPeRand(int* nr_locuri_pe_randNou, int nr_randuri)
{
	if (nr_locuri_pe_randNou != nullptr && nr_randuri != 0)
	{
		this->nr_randuri = nr_randuri;
		if (this->nr_locuri_pe_rand != nullptr)
		{
			delete[] this->nr_locuri_pe_rand;

		}
		this->nr_locuri_pe_rand = new int[nr_randuri];
		for (int i = 0; i < nr_randuri; i++)
		{
			this->nr_locuri_pe_rand[i] = nr_locuri_pe_randNou[i];
		}
	}
}
int* Locatie::getNrLocuriPeRand()
{
	return this->nr_locuri_pe_rand;
}
int Locatie::getNrMaximLocuri()
{
	return nr_maxim_locuri;
}
//metoda generica1
bool Locatie::validareNrLocuri(Locatie& l)
{
	for (int i = 0; i < l.nr_randuri; i++)
	{
		if (l.nr_locuri_pe_rand[i] > nr_maxim_locuri)
			return false;
	}
	return true;
}


 //metoda generica2-popularea matricei cu locuri in functie de locul ales in bilet

int** Locatie::MatriceLocuri(Locatie& l)
{
	int** locuri = new int* [l.nr_randuri];
	for (int i = 0; i < l.nr_randuri; i++)
	{
		locuri[i] = new int[l.nr_locuri_pe_rand[i]];
	}
	for (int i = 0; i < l.nr_randuri; i++)
	{
		for (int j = 0; j < l.nr_locuri_pe_rand[i]; j++)
		{
			if (*(*(locuri + i) + j)== b.getLoc())
			{
				locuri[i][j] = 1;
			}
			else locuri[i][j] = 0;
		}
	}
	return locuri;
}




//supraincarcare operatori
int& Locatie:: operator[](int index)
{
	int invalid;
	invalid = -1;
	if (this->nr_locuri_pe_rand != nullptr && index >= 0 && index < this->nr_randuri)
	{
		return this->nr_locuri_pe_rand[index];
	}
	else
	{
		return invalid;
	}
}

bool Locatie:: operator!()
{
	return nr_randuri > 0;
}

//citire afisare
istream& operator>>(istream& in, Locatie& l)
{
	in >> l.id_locatie;
	in >> l.nr_randuri;

	delete[] l.nr_locuri_pe_rand;
	l.nr_locuri_pe_rand = new int[l.nr_randuri];
	for (int i = 0; i < l.nr_randuri; i++)
	{
		in >> l.nr_locuri_pe_rand[i];
	}

	return in;
}
ostream& operator<<(ostream& out, Locatie l) {
	out << l.id_locatie << endl;
	out << l.nr_maxim_locuri << endl;
	out << l.nr_randuri << endl;
	
	if (l.nr_locuri_pe_rand != nullptr)
	{
		for (int i = 0; i < l.nr_randuri; i++)
		{
			out << l.nr_locuri_pe_rand[i] << " ";
		}
	}
	return out;
}