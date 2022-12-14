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
	else
	{
		this->nr_randuri = 0;
		this->nr_locuri_pe_rand = nullptr;
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
	else
	{
		this->nr_randuri = 0;
		this->nr_locuri_pe_rand = nullptr;
	}
}

//destructor
Locatie::~Locatie() 
{
	delete[] this->nr_locuri_pe_rand;
}

//opertaor egal

Locatie& Locatie::operator=(const Locatie& l)
{
	if (this != &l)
	{
		
		delete[] nr_locuri_pe_rand;
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
	return *this;
}


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
		if (l.nr_locuri_pe_rand[i] > l.nr_maxim_locuri)
			return false;
	}
	return true;
}

//metoda ocupa loc nr loc nr rand-in bilet o apelez

 //metoda generica2-popularea matricei cu locuri in functie de locul ales in bilet -creez metoda ocupa loc si o apelez in bilet cand vreau sa schimb locul in 0-1


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
			locuri[i][j] = 0;
	}
	

	return locuri;
}





//supraincarcare operatori
int Locatie:: operator[](int index)
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
	cout << "Id locatie: ";
	in >> l.id_locatie;
	cout << "Numar de randuri: ";
	in >> l.nr_randuri;

	cout << "Numar de locuri pe fiecare rand: ";
	delete[] l.nr_locuri_pe_rand;
	l.nr_locuri_pe_rand = new int[l.nr_randuri];
	for (int i = 0; i < l.nr_randuri; i++)
	{
		in >> l.nr_locuri_pe_rand[i];
	}

	return in;
}
ostream& operator<<(ostream& out, Locatie l) {
	out <<"Id locatie: "<<l.id_locatie << endl;
	out <<"Numar maxim de locuri: "<<l.nr_maxim_locuri << endl;
	out <<"Numar de randuri: "<<l.nr_randuri << endl;
	
	out << "Numar de locuri pe fiecare rand: ";
	if (l.nr_locuri_pe_rand != nullptr)
	{
		for (int i = 0; i < l.nr_randuri; i++)
		{
			out << l.nr_locuri_pe_rand[i] << " ";
		}
	}
	cout << endl;
	
	return out;
}