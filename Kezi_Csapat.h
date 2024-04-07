#pragma once
#include "Csapat.h"
#include <fstream>
#include "memtrace.h"
class Kezi_Csapat : public Csapat
{
	 int tamogatas;			//Csapat tamogatasanak osszege, a Kezi osztaly sajatossaga
public:
	//Parameter nelkuli konstruktor
	Kezi_Csapat() :Csapat(), tamogatas(0) {}	

	//Parameteres konstruktor
	Kezi_Csapat(const char* nev, int letszam, const char* edzo, int tamogatas) : Csapat(nev, letszam, edzo), tamogatas(tamogatas) {}

	//Visszaadja a tamogatas adattagot
	int GetTam() const { return this->tamogatas; }

	//Beallitja a tamogatas adattagot
	void SetTam(int tam) { this->tamogatas = tam; }

	//Kiirja a csapathoz tartozo adatokat
	void kiir() const;

	//Fajlba irashoz fogom hasznalni
	void fajlbair(std::ofstream& fajl) const;

	bool operator==(const Kezi_Csapat& cs)const;

	//Visszavezetve az == operatorra
	bool operator!=(const Kezi_Csapat& cs)const;

	//Visszadja a csapathoz tartozo sportagat, jelen esetben a Kezi-t
	Sportag GetSportag() const { return Sportag::Kezi; }

};


