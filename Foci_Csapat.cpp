#include "Foci_Csapat.h"
#include "memtrace.h"



//Parameteres konstruktor
Foci_Csapat::Foci_Csapat(const char* nev, int letszam, const char* edzo, const char* potedzo) : Csapat(nev, letszam, edzo)
{
	this->potedzo = new char[strlen(potedzo) + 1];
	strcpy(this->potedzo, potedzo);

}
//Kiiras
void Foci_Csapat::kiir() const
{
	if (nev != nullptr) {
		std::cout << "A csapat neve: " << nev << "\nLetszama: " << letszam << " fo\nEdzoje: " << edzo << "\nPot Edzoje: " << potedzo << std::endl << std::endl;
	}
	else
		std::cout << "A csapat adatai hibasak" << std::endl;
}


bool Foci_Csapat::operator==(const Foci_Csapat& masik)const
{
	if (strcmp(nev, masik.nev) == 0 && letszam == masik.letszam && strcmp(edzo, masik.edzo) == 0 && strcmp(potedzo, masik.potedzo)==0)
	{
		return true;
	}
	return false;

}


//Visszavezetve az == operatorra
bool Foci_Csapat::operator!=(const Foci_Csapat& masik)const
{

	if (*this == masik)
	{
		return false;
	}
	return true;
}

void Foci_Csapat::fajlbair(std::ofstream& fajl) const { fajl << nev << ";" << letszam << ";" << edzo << ";" << potedzo << ";#\n"; };