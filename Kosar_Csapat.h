#pragma once
#include "Csapat.h"
#include <fstream>
#include "memtrace.h"

class Kosar_Csapat :
    public Csapat
{
    int Pom_pom_lanyok;			//Csapat Pompomlanyainak szama, ez Kosar osztaly sajatossaga
public:
	//Parameter nelkuli konstruktor
	Kosar_Csapat() :Csapat(), Pom_pom_lanyok(0) {}

	//Parameteres konstruktor
	Kosar_Csapat(const char* nev, int letszam, const char* edzo, int lanyok) : Csapat(nev, letszam, edzo), Pom_pom_lanyok(lanyok) {}

	//Visszaadja a Pom_pom_lanyok adattagot
	int GetPompom() const { return this->Pom_pom_lanyok; }

	//Beallitja a Pom_pom_lanyok adattagot
	void SetPompom(int db) { this->Pom_pom_lanyok = db; }

	//Kiirja a csapathoz tartozo adatokat
	void kiir() const;

	//Fajlba irashoz fogom hasznalni
	void fajlbair(std::ofstream& fajl)  const;

	//operator overload
	bool operator==(const Kosar_Csapat& cs)const;

	//Visszavezetve az == operatorra
	bool operator!=(const Kosar_Csapat& masik)const;

	//Visszadja a csapathoz tartozo sportagat, jelen esetben a Kosar-t
	Sportag GetSportag() const { return Sportag::Kosar; }
};

