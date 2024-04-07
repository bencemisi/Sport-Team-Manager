
#include "Csapat_felvetel.h"
#include "memtrace.h"

int sorszamlalo(const char* fajlnev)
{
	std::ifstream file(fajlnev);
	if (!file.is_open()) {
		std::cerr << "Hiba: nem sikerult megnyitni a fajt!" << fajlnev << '\n';						//Hiba kezeles
		return -1;
	}

	int sorok = 0;
	char c;
	while (file.get(c)) {					//Szamolja a '\n' karaktereket, így meghatarozza hany sorbol all a txt
		if (c == '\n') {
			++sorok;
		}
	}

	file.close();

	return sorok;		//+1 az utolsó sor után már nincs enter


}
char* sorbeolvas(std::ifstream& fajl)
{


	if (!fajl)
	{
		std::cerr << "Hiba: nincs megnyitva a fajl sorolvasashoz" << std::endl;
	}

	char* sor = nullptr;
	int hossz = 0;
	char jelenlegi;
	fajl >> std::skipws >> jelenlegi;					//Eldobjuk a whitespace karaktereket
	while (jelenlegi != '#')							//Fajlban ez a sorzaro karakter
	{
		char* temp = new char[hossz + 2];				//Atmeneti tarolo letrehozasa
		if (sor != nullptr)
		{
			strcpy(temp, sor);							//Masolas
		}
		temp[hossz] = jelenlegi;						//Plusz karakter hozzafuzese
		temp[hossz + 1] = '\0';							//Lezaras
		if (sor != nullptr)								
		{
			delete[] sor;								//Regi torlese
		}
		sor = new char[hossz + 2];						//Lefoglalas
		strcpy(sor, temp);								//Masolas
		delete[] temp;									//Atmeneti tarolo torlese
		fajl >> std::noskipws >> jelenlegi;				//Whitespace karaktereket nem dobjuk el es olvassuk a kovetkezo karaktert
		hossz++;
	}
	
	return sor;

}
char* adatbeolvas()//Függveny overload, ez nem fajlbol olvas hanem a felhasznalo altal begepelt adatokat dolgozza fel
{
	    char* beolvas = nullptr;
	    int hossz = 0;
	    char jelenlegi ;
		
		while ((jelenlegi = getchar()) != '\n')
		{
			char* temp = new char[hossz + 2];
			if (beolvas != nullptr)
			{
				strcpy(temp, beolvas);
			}
			temp[hossz] = jelenlegi;
			temp[hossz + 1] = '\0';
			if (beolvas != nullptr)
			{
				delete[] beolvas;
			}
			beolvas = new char[hossz + 2];
			strcpy(beolvas, temp);
			delete[] temp;

			hossz++;
		}
	

		return beolvas;
}
void Lista::Csapat_lista_foci(const char* fajlnev)
{
	std::ifstream fajl(fajlnev);
	if (!fajl)							//Hiba a fajlt nem tudjuk megnyitni
	{
		throw "Nincs ilyen fajl";
	}
	int sorszam = sorszamlalo(fajlnev);
	for (int i = 0; i < sorszam;i++)
	{
		Csapat_listaelem* ujelem = new Csapat_listaelem;				
		Foci_Csapat* ujcsapat = new Foci_Csapat;
		char* sor = sorbeolvas(fajl);
		char* token = std::strtok(sor, ";");				//Feldarabolja a beolvasott sort, majd Setterek használata a mentésre
		ujcsapat->SetNev(token);
		token = std::strtok(NULL, ";");
		try {
			ujcsapat->SetLetszam(std::atoi(token));
		}
		catch (std::out_of_range)
		{
			std::cout << "Tullepett a hataron" << std::endl;
		}
		token = std::strtok(NULL, ";");
		ujcsapat->SetEdzo(token);
		token = std::strtok(NULL, ";");
		ujcsapat->SetPot(token);						//Foci_Csapat-ra egyedulallo adattag
		ujelem->Csapatom = ujcsapat;
		ujelem->kov = nullptr;

		if (listam == nullptr)							//Ha a lista ures
		{
			listam = ujelem;
		}
		else {											//Ha a lista nem ures
			Csapat_listaelem* mozgo = listam;
			while (mozgo->kov != nullptr)
				mozgo = mozgo->kov;
			mozgo->kov = ujelem;
		}
		delete[] sor;									//Dinamikusan foglalt tomb felszabaditasa

	}
	fajl.close();										//Fajl bezarasa
}
void Lista::Csapat_lista_kosar(const char* fajlnev) {

	std::ifstream kosar_fajl(fajlnev);
	if (!kosar_fajl)
	{
		throw "Nincs ilyen fajl";
	}

	int sorszam = sorszamlalo(fajlnev);
	for (int i = 0; i < sorszam;i++)
	{
		Csapat_listaelem* ujelem = new Csapat_listaelem;
		Kosar_Csapat* ujcsapat = new Kosar_Csapat;

		char* sor = sorbeolvas(kosar_fajl);
		char* token = std::strtok(sor, ";");
		ujcsapat->SetNev(token);
		token = std::strtok(NULL, ";");
		try {
			ujcsapat->SetLetszam(std::atoi(token));
		}
		catch (std::out_of_range)
		{
			std::cout << "Tullepett a hataron" << std::endl;
		}
		token = std::strtok(NULL, ";");
		ujcsapat->SetEdzo(token);
		token = std::strtok(NULL, ";");
		ujcsapat->SetPompom(std::atoi(token));				//Kosar_Csapat-ra egyedulallo adattag
		ujelem->Csapatom = ujcsapat;
		ujelem->kov = nullptr;

		if (listam == nullptr)
		{
			listam = ujelem;
		}
		else {
			Csapat_listaelem* mozgo = listam;
			while (mozgo->kov != nullptr)
				mozgo = mozgo->kov;
			mozgo->kov = ujelem;
		}
		delete[] sor;

	}
	kosar_fajl.close();

}
void Lista::Csapat_lista_kezi( const char* fajlnev)
{
	std::ifstream kezi_fajl(fajlnev);
	if (!kezi_fajl)
	{
		throw "Nincs ilyen fajl";
	}

	int sorszam = sorszamlalo(fajlnev);
	for (int i = 0; i < sorszam;i++)
	{
		Csapat_listaelem* ujelem = new Csapat_listaelem;
		Kezi_Csapat* ujcsapat = new Kezi_Csapat;
		char* sor = sorbeolvas(kezi_fajl);
		char* token = std::strtok(sor, ";");
		ujcsapat->SetNev(token);
		token = std::strtok(NULL, ";");
		try {
			ujcsapat->SetLetszam(std::atoi(token));
		}
		catch (std::out_of_range)
		{
			std::cout << "Tullepett a hataron" << std::endl;
		}
		token = std::strtok(NULL, ";");
		ujcsapat->SetEdzo(token);
		token = std::strtok(NULL, ";");
		ujcsapat->SetTam(std::atoi(token));							//Kezi_Csapat-ra egyedulallo adattag
		ujelem->Csapatom = ujcsapat;
		ujelem->kov = nullptr;
		if (listam == nullptr)
		{
			listam = ujelem;
		}
		else {
			Csapat_listaelem* mozgo = listam;
			while (mozgo->kov != nullptr)
				mozgo = mozgo->kov;
			mozgo->kov = ujelem;
		}
		delete[] sor;
	}
	kezi_fajl.close();
}
void Lista::add(Csapat* uj)
{
	if (uj == nullptr)
		return;
	Csapat_listaelem* ujelem = new Csapat_listaelem;
	ujelem->Csapatom = uj;							//Elmenti az adatot
	ujelem->kov = nullptr;
	if (listam == nullptr)			//Ha a lista ures akkor a lista eleje lesz az uj
	{
		listam = ujelem;
	}
	else {
		Csapat_listaelem* mozgo = listam;
		while (mozgo->kov != nullptr)		//Ha nem ures akkor a vegere teszem az uj adattagot
		{
			mozgo = mozgo->kov;
		}
		mozgo->kov = ujelem;
	}

}
void Lista::Listafelszabadit()
{
	Csapat_listaelem* mozgo = listam;			//Lista felszabaditasa
	while (mozgo != nullptr)
	{
		Csapat_listaelem* kov = mozgo->kov;
		delete mozgo->Csapatom;
		delete mozgo;

		mozgo = kov;
	}

}
void Lista::kiir() const
{
	std::cout << "Melyik sportag csapatait szeretned kilistazni: " << std::endl;				
	
	Sportag sport = Sportag::Foci;		//Ne legyen inicializálatlan, de ugyis felul fogom irni
	int mind;;
	std::cout << "Minden csapatot ki szeretnel iratni:(0 vagy karakter -nem, szamok-igen)";
	std::cin >> mind;
	while(!std::cin)
	{
		std::cin >> mind;
		std::cin.clear();    //Hiba flag resetelese
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		continue;
	}
	if (!mind)
	{
		Csapatkiiras();
		switch (menupontvalasztas())		//Kivalasztja milyen sportagban levo csapatokat szeretne kiiratni
		{
		case 1: sport = Sportag::Foci;break;
		case 2: sport = Sportag::Kosar;break;
		case 3: sport = Sportag::Kezi;break;
		case 4: return;break;					//Visszalepes
		}
	}

		Csapat_listaelem* mozgo = listam;
		while (mozgo != nullptr)
		{
			if (mind)					//Kiirja az osszes adatot
			{
				mozgo->Csapatom->kiir();
				mozgo = mozgo->kov;
			}
			else												//Csak egy adott sportag csapatait irja ki
			{
				if(mozgo->Csapatom->GetSportag() == sport)		//A sportag ellenorzese
					mozgo->Csapatom->kiir();

				mozgo = mozgo->kov;
			}
		}
		system("pause");				//Az adatok olvasasara ido hagyas, enter leutesig
	
}
void letszamkeres(Csapat* csapat) {
	int letszam;
	do {
		if (!(std::cin >> letszam))   // A beolvasas eredmenyet is ellenorizzuk
		{
			std::cout << "Nem szamot adott meg. Kerem adja meg ismet: " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;   // Visszaterüuk a ciklus elejere, és nem folytatjuk a feltetelek ellenorzeset
		}
		try {
			csapat->SetLetszam(letszam);
		}
		catch (std::out_of_range)
		{
			std::cout << "Tullepett a hataron. Kerem adja meg ujra: " << std::endl;
			continue;
		}

	} while (letszam >= 1000 || letszam <= 0);

}
Csapat* Foci_bejegyez()
{
												//Adatok egymas utan felepítese, majd Csapat* visszada
	Foci_Csapat* ujcsapat = new Foci_Csapat;
	std::cout << "Kerem adja meg a csapat nevet: ";
	char* nev = adatbeolvas();
	while (nev == nullptr) {
		nev = adatbeolvas();
	}
	ujcsapat->SetNev(nev);
	delete[] nev;					//torles, hogy ne legyen memoriaszivargas
	std::cout << "Kerem adja meg a csapat letszamat: ";
	letszamkeres(ujcsapat);
	std::cin.clear();
	std::cout << "Kerem adja meg a edzo nevet: ";
	nev = adatbeolvas();
	while (nev == nullptr) {		//Ne lehessen hibas erteket megadni
		nev = adatbeolvas();
	}
	ujcsapat->SetEdzo(nev);
	delete[] nev;
	std::cout << "Kerem adja meg a potedzo nevet: ";
	nev = adatbeolvas();
	while (nev == nullptr) {
		nev = adatbeolvas();
	}
	ujcsapat->SetPot(nev);				//Foci_Csapatra egyedi adattag
	delete[] nev;
	
	return ujcsapat;

}
Csapat* Kosar_bejegyez()
{


	Kosar_Csapat* ujcsapat = new Kosar_Csapat;
	std::cout << "Kerem adja meg a csapat nevet: ";
	char* nev = adatbeolvas();
	while (nev == nullptr) {
		nev = adatbeolvas();
	}
	ujcsapat->SetNev(nev);
	delete[] nev;
	std::cout << "Kerem adja meg a csapat letszamat: ";
	letszamkeres(ujcsapat);
	std::cin.clear();
	std::cout << "Kerem adja meg a edzo nevet: ";
	nev = adatbeolvas();
	while (nev == nullptr) {
		nev = adatbeolvas();
	}
	ujcsapat->SetEdzo(nev);
	delete[] nev;
	std::cout << "Kerem adja meg a Pompom lanyok szamat: ";				//Kosar_Csapatra egyedi adattag
	int letszam= 0;
	std::cin >> letszam;
	while (letszam < 0 || letszam>500) {					//Itt a hatar mas mint a letszam-nal, itt külön ellenörzöm
		std::cout << "A pompomlanyok nem lehetnek 500-nal tobben, kerem adja meg ismét: " << std::endl;
		std::cin >> letszam;
	}
	ujcsapat->SetPompom(letszam);
	

	return ujcsapat;

}
Csapat* Kezi_bejegyez()
{


	Kezi_Csapat* ujcsapat = new Kezi_Csapat;
	std::cout << "Kerem adja meg a csapat nevet: ";
	char* nev = adatbeolvas();
	while (nev == nullptr) {
		nev = adatbeolvas();
	}
	ujcsapat->SetNev(nev);
	delete[] nev;
	std::cout << "Kerem adja meg a csapat letszamat: ";
	
	letszamkeres(ujcsapat);
	std::cin.clear();
	std::cout << "Kerem adja meg a edzo nevet: ";
	nev = adatbeolvas();
	while (nev == nullptr) {
		nev = adatbeolvas();
	}
	ujcsapat->SetEdzo(nev);
	delete[] nev;
	std::cout << "Kerem adja meg a tamogatas osszeget: ";			//Kosar_Csapatra egyedi adattag
	int tam= -1;													//-1 nem lehet a tamogatas erteke
	while (tam < 0) {												//Amig hibas erteket kap addig ujraolvas
		std::cin >> tam;
	}
	ujcsapat->SetTam(tam);


	return ujcsapat;
}
Csapat* Csapat_kivalaszt()				//Itt kérek be adatokat a Usertõl, határokat szabok meg
{

		Csapatkiiras();

		switch (menupontvalasztas())
		{
		case 1: return Foci_bejegyez();break;			//Foci_Csapat* kepez
		case 2: return Kosar_bejegyez();break;			//Kosar_Csapat* kepez
		case 3: return Kezi_bejegyez();break;			//Kezi_Csapat* kepez
		case 4: return nullptr;break;									//Visszalepes
		}
		return nullptr;
}
void Lista::torol(Csapat* torlendo)
{
	if (torlendo == nullptr)
		return;
	Csapat_listaelem* lemarado = nullptr;
	Csapat_listaelem* mozgo = listam;				
	while (mozgo != nullptr && *mozgo->Csapatom != *torlendo) {
		lemarado = mozgo;
		mozgo = mozgo->kov;
	}
	if (mozgo == nullptr) { // Ha nincs ilyen csapat
		std::cout << "A " << torlendo->GetNev() << " csapat nincs a listaban." << std::endl;
		delete torlendo;
		return;
	}

	if (lemarado == nullptr) { // Ha az elso elemet kell torolni
		listam = mozgo->kov;
	}
	else { // Ha kozeprol vagy vegerol kell torolni
		lemarado->kov = mozgo->kov;
	}

	std::cout << "A " << torlendo->GetNev() << " csapatot torolve." << std::endl;

	delete mozgo->Csapatom;
	delete mozgo;
	if (torlendo != nullptr)
	{
		delete torlendo;
	}
}
void Lista::mentes(const char* fajlnev, Sportag sport)const
{
	std::ofstream ofs(fajlnev);
	if (!ofs)							//Hiba a fajlt nem tudjuk megnyitni
	{
		
		std::cerr << "Hiba: nem sikerult megnyitni a " << fajlnev << "fajlt mentesre." << std::endl;

	}

	Csapat_listaelem* mozgo = listam;
	while (mozgo != nullptr)
	{
		if (mozgo->Csapatom->GetSportag() == sport)		//A sportag ellenorzese
			mozgo->Csapatom->fajlbair(ofs);				//Fajlba iras

		mozgo = mozgo->kov;
	}

	ofs.close();
}
bool Lista::keres(Csapat* keresendo)
{
	
	if (keresendo == nullptr)
		return false;
	Csapat_listaelem* mozgo = listam;
	if (mozgo == nullptr)
	{
		return false;
	}
	while (mozgo != nullptr) {
		if (*mozgo->Csapatom == *keresendo)
		{
			return true;
		}
		mozgo = mozgo->kov;
	}
	return false;
}