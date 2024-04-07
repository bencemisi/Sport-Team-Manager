
#include"Foci_Csapat.h"
#include "Kosar_Csapat.h"
#include "Kezi_Csapat.h"
#include <fstream>
#include<iostream>
#include"memtrace.h"
#include <cstring>
#include "Menukezeles.h"
#include <fstream>
#include "Csapat.h"

struct Csapat_listaelem				//Maga a lista(heterogen kollekcio) felepitese
{
	Csapat* Csapatom;
	Csapat_listaelem* kov;
};
class Lista
{
	Csapat_listaelem* listam;
	
public:
	//Parameter nelkuli konstruktor
	Lista() : listam(nullptr) {};

	//Beolvassa felépíti, majd beépíti a listába a foci csapatokat
	void Csapat_lista_foci( const char* fajlnev);

	//Beolvassa felépíti, majd beépíti a listába a kosar csapatokat
	void Csapat_lista_kosar( const char* fajlnev);

	//Beolvassa felépíti, majd beépíti a listába a kezi csapatokat
	void Csapat_lista_kezi( const char* fajlnev);

	//Hozzafuz a lista vegehez egy uj csapatot
	void add(Csapat* uj);

	//Vegigmegy a listan, megnezi hogy talal-e teljesen egyezo csapatot a megadott parameterekkel
	//ha talal akkor torli, ha nem akkor tajekoztatja a felhasznalot
	void torol(Csapat* torlendo);

	//Visszaadja a lista elejere mutato pointert
	Csapat_listaelem* Getlistam() const { return listam; }

	//Kiirja a bekert sportaghoz tartozo adattagokat
	void kiir()const;

	//Elmenti a lista adott sportaghoz tartalmazo elemeit a hozzajuk tartozo fajlba (felulirja a fajl tartalmat)
	void mentes(const char* fajlnev, Sportag a)const;

	//Felszabaditja a listat
	void Listafelszabadit();

	//Teszteleshez hasznalt fuggveny
	bool keres(Csapat* keresendo);

};

//Megszamolja hany sor van egy fajlban
int sorszamlalo(const char* fajlnev);

//Beolvas egy sort a fajlbol
char* sorbeolvas(std::ifstream& fajl);

//Beolvas es dinamikusan eltarolja a felhasznalo altal megadott adatokat
char* adatbeolvas();

//Beker egy letszamot a felhasznalotol es ellenorzi, hogy a megadott hatarok kozott van-e az ertek
int letszamkeres();

//A megadott adatok alapjan felepit egy Foci_Csapat típusú csapatot es visszaadja a ra mutato pointert
Csapat* Foci_bejegyez();

//Hasonlot csinal, viszont Kosar_Csapatot epit fel
Csapat* Kosar_bejegyez();

//Kezi_Csapatot epit fel
Csapat* Kezi_bejegyez();	

//Hivja a 3 bejegyez fuggvenyt es itt valaszt a felhasznalo hogy milyen csapatot akar felvenni
Csapat*  Csapat_kivalaszt();		

