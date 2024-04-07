#include "Kosar_Csapat.h"
#include "memtrace.h"

void Kosar_Csapat::kiir()const
{
	if (nev != nullptr) {
		std::cout << "A csapat neve: " << nev << "\nLetszama: " << letszam << " fo\nEdzoje: " << edzo << "\nPom-pom lanyok szama: " << Pom_pom_lanyok<<std::endl << std::endl;
	}
	else
		std::cout << "A csapat adatai hibasak" << std::endl;
}
bool Kosar_Csapat::operator==(const Kosar_Csapat& masik)const
{
	if (strcmp(nev, masik.nev) == 0 && letszam == masik.letszam && strcmp(edzo, masik.edzo) == 0 && (Pom_pom_lanyok==masik.Pom_pom_lanyok))
		return true;
	return false;

}
//Visszavezetve az == operatorra
bool Kosar_Csapat::operator!=(const Kosar_Csapat& masik)const {

	if (*this == masik)
	{
		return false;
	}
	return true;
}
void Kosar_Csapat::fajlbair(std::ofstream& fajl) const { fajl << nev << ";" << letszam << ";" << edzo << ";" << Pom_pom_lanyok << ";#\n"; };

