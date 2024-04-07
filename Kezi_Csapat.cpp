#include "Kezi_Csapat.h"
#include "memtrace.h"

void Kezi_Csapat::kiir()const
{
	if (nev != nullptr) {
		std::cout << "A csapat neve: " << nev << "\nLetszama: " << letszam << " fo\nEdzoje: " << edzo << "\nTamogatas osszege: " << tamogatas <<" Ft"<<std::endl <<std::endl;
	}
	else
		std::cout << "A csapat adatai hibasak" << std::endl;
}
bool Kezi_Csapat::operator==(const Kezi_Csapat& masik)const
{
	if (strcmp(nev, masik.nev) == 0 && letszam == masik.letszam && strcmp(edzo, masik.edzo) == 0 && (tamogatas == masik.tamogatas))
		return true;
	return false;

}
//Visszavezetve az == operatorra
bool Kezi_Csapat::operator!=(const Kezi_Csapat& cs)const {

	if(*this==cs)
	{
		return false;
	}
	return true;
}
void Kezi_Csapat::fajlbair(std::ofstream& fajl) const { fajl << nev << ";" << letszam << ";" << edzo << ";" << tamogatas << ";#\n"; };