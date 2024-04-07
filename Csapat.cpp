#include "Csapat.h"
#include "memtrace.h"
#include <cstring>

Csapat::Csapat(const char* nev, int letszam,const char* edzo)
{
	if(nev!=nullptr)								//Ellenorzi hogy a nev ne legyen ures, ha ures akkor hibas az adatmegadas
	{	this->nev = new char[strlen(nev) + 1];		//Dinamiusan lefoglal teruletet, majd belemasolja az adattagokat
		strcpy(this->nev, nev);							
		this->letszam = letszam;
		this->edzo = new char[strlen(edzo) + 1];
		strcpy(this->edzo, edzo);
	}else                                            //Ha rossz az adatmegadas akkor mindent kezdo ertekbe allit
	{
		this->nev = nullptr;
		this->letszam = 0;
		this->edzo = nullptr;
	}
	
}
bool Csapat::operator==(const Csapat& masik)const
{
	if (strcmp(nev, masik.nev) == 0 && letszam == masik.letszam && strcmp(edzo, masik.edzo) == 0)
	{
		return true;
	}
	return false;

}

bool Csapat::operator!=(const Csapat& masik)const
{
	if (*this == masik)				//Visszavezetem az == operatorra
	{
		return false;
	}
	return true;

}