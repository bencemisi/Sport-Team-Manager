#pragma once

#include<cstring>
#include<iostream>
#include "memtrace.h"

enum class Sportag {Foci, Kosar, Kezi};			//Sportagak konyebb kezelesehez

//Absztrakt osztaly, mivel minden csapatnak kell valamilyen sportaghoz tartoznia
class Csapat
{
protected:
	char* nev;				//Csapat nevere mutato pointer
	int letszam;			//Csapat letszama
	char* edzo;				//Csapat edzojere mutato pointer

public:																
	//Paraméter nélkül hívható konstruktor
	Csapat() :nev(nullptr), letszam(0), edzo(nullptr) {}	 

	// Paraméteres Konstruktor, 
	Csapat(const char* nev, int letszam,const char* edzo);	


	//Visszaadja a nev adattagot
	char* GetNev() const { return nev; }				

	//Visszaadja a letszam adattagot
	int GetLetszam() const{ return letszam; }	

	//Visszaadja az edzo adattagot
	char* GetEdzo() const{ return edzo; }		

	//Beallitja a nev adattagot, dinamikusan helyet foglal es feltolt
	void SetNev(const char* szoveg) {
		this->nev = new char[strlen(szoveg) + 1];
		strcpy(nev, szoveg);
	}
	//Beallitja a letszam adattagot
	void SetLetszam(int szam) {
		if (szam < 0 || szam>1000)
			throw std::out_of_range("Tullepett a hataron");
		letszam = szam; 
	}

	//Beallitja az edzo adattagot, dinamikusan helyet foglal es feltolt
	void SetEdzo(const char* szoveg) {
		this->edzo = new char[strlen(szoveg) + 1];
		strcpy(edzo, szoveg);
	}
	//Visszadja a csapathoz tartozo sportagat, absztrakt osztalyt hoz letre
	virtual Sportag GetSportag() const = 0;

	//operator overloadok
	virtual bool operator==(const Csapat& cs)const;

	//Visszavezetve az == operatorra
	virtual bool operator!=(const Csapat& cs)const;

	//Kiirja a csapathoz tartozo adatokat, minden osztalynal kulonbozo modon
	virtual void kiir() const = 0;

	//A megfelelo tarolashoz txt fajlban hasznalom
	virtual void fajlbair(std::ofstream& fajl) const=0;
	

	//virtualis destruktor
	virtual ~Csapat() { delete[] nev; delete[] edzo; }
};

