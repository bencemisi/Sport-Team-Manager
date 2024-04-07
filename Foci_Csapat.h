#pragma once
#include "Csapat.h"
#include <fstream>
#include "memtrace.h"
class Foci_Csapat : public Csapat
{
	char* potedzo;				//Csapat potedzojere mutato pointer, ez a Foci osztaly sajatossaga
public:
	//Parameter nelkuli konstruktor
	Foci_Csapat() :Csapat(), potedzo(nullptr) {}					

	//Parameteres konstruktor
	Foci_Csapat(const char* nev, int letszam, const char* edzo, const char* potedzo);		
	
	//Visszaadja a potedzo adattagot
	char* GetPot() const { return this->potedzo; }				

	//Beallitja a potedzo adattagot, dinamikusan helyet foglal es feltolt
	void SetPot(const char* potedzoneve)
	{
		this->potedzo = new char[strlen(potedzoneve) + 1];
		strcpy(potedzo, potedzoneve);
	}

	//Kiirja a csapathoz tartozo adatokat
	void kiir() const;

	//Fajlba irashoz fogom hasznalni
	void fajlbair(std::ofstream& fajl) const;

	// == operator overload
	bool operator==(const Foci_Csapat& cs)const;

	//Visszavezetve az == operatorra
	bool operator!=(const Foci_Csapat& cs)const;

	//Visszadja a csapathoz tartozo sportagat, jelen esetben a Foci-t
	Sportag GetSportag() const { return Sportag::Foci; }

	//Destruktor
	~Foci_Csapat() { delete[] potedzo; }
};


