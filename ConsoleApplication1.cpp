// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstring>
#include "memtrace.h"
#include"Csapat.h"
#include"Foci_Csapat.h"
#include "Kosar_Csapat.h"
#include "Kezi_Csapat.h"
#include"Csapat_felvetel.h"
#include"Menukezeles.h"
#include "gtest_lite.h"


//teszteléshez vedd ki a kommentet
//#define CPORTA
int releaseMain(int argc, char** argv) {
    Lista lista;
    try {
        lista.Csapat_lista_foci("foci.txt");                //Lista feltoltes
        lista.Csapat_lista_kosar("kosar.txt");
        lista.Csapat_lista_kezi("kezi.txt");
    }
    catch (const char*)
    {
        std::cout << "Nem lehet megnyitni a fajlt" << std::endl;
        return 0;
    }
    bool vege = false;

    while (!vege)
    {
        menukiiras();                                   //Maga a program
        try {                                           // Ha kivétel keletkezik akkor csak itt keletkezhet a menupontvalasztas fv miatt
            switch (menupontvalasztas())
            {

            case 1: std::cout << std::endl << "Milyen csapatot szeretne felvenni a nyilvantartasba?" << std::endl;
                lista.add(Csapat_kivalaszt());break;
            case 2: 	std::cout << std::endl << "Milyen csapatot szeretnel torolni" << std::endl;
                lista.torol(Csapat_kivalaszt());break;
            case 3: lista.kiir();break;

            case 4: std::cout << "Koszonom hogy a programomat hasznalta!" << std::endl;vege = true;break;
            }

        }
        catch (const char* p)                          //Kivetel elkapasa
        {
            std::cout << p << std::endl;
            system("pause");				//A hiba olvasasara ido hagyas, enter leutesig
        }


    }

    Sportag a = Sportag::Foci;                      //Mentes fajlba
    lista.mentes("foci.txt", a);
    a = Sportag::Kosar;
    lista.mentes("kosar.txt", a);
    a = Sportag::Kezi;
    lista.mentes("kezi.txt", a);
    Csapat* alma = new Foci_Csapat("alma", 12, "alma", "alma");
    lista.add(alma);
    std::cout << lista.keres(alma) << std::endl;
    lista.Listafelszabadit();
    return 0;
}

int testMain() {

    
   

    TEST(Fajlmegnyitas, Kivetelt varunk)
        Lista lista;
    EXPECT_ANY_THROW(lista.Csapat_lista_foci("foci2.txt");) << "Kivetelt vartunk" << std::endl;
    ENDM;

    TEST(Fajlmegnyitas, Nem varunk kivetelt)
        Lista lista;
    EXPECT_NO_THROW(lista.Csapat_lista_foci("foci.txt")) << "Nem lehetett megnyitni a fajlt" << std::endl;
    lista.Listafelszabadit();
    ENDM;
    TEST(Fajlmegnyitas majd beolvasas es listazas, Listazas)
        Lista lista;
    lista.Csapat_lista_foci("foci.txt");
    lista.Csapat_lista_kosar("kosar.txt");
    lista.Csapat_lista_kezi("kezi.txt");
    lista.kiir();
    lista.kiir();
    lista.kiir();
    lista.kiir();
    Sportag a = Sportag::Foci;
    lista.mentes("foci.txt",a);
    lista.Listafelszabadit();
    ENDM;

    TEST(Rossz menupont, Kivetelt varunk)
    menukiiras();
        EXPECT_ANY_THROW(menupontvalasztas()) << "Kivetelt vartunk" << std::endl;
    ENDM;

    TEST(Hozzaadas + Keres, Sikeresen)
        Lista lista;
  
    Csapat* teszt = new Foci_Csapat("alma", 12, "alma", "alma");
    lista.add(teszt);
    EXPECT_TRUE(lista.keres(teszt)) << "Kerestunk de nem talaltunk" << std::endl;
    lista.Listafelszabadit();

    ENDM;
    TEST(Keres, Sikertelenul)
        Lista lista;
    Csapat* teszt = new Foci_Csapat("alma", 12, "alma", "alma");
    EXPECT_FALSE(lista.keres(teszt)) << "Olyat kerestunk ami nem lehet benne de talaltuk" << std::endl;
    delete teszt;
    ENDM;

    TEST(Foci_Torles, Hozzaadas->Torles)
        Lista lista;
    Csapat* teszt = new Foci_Csapat("proba", 11, "proba", "proba");
    lista.add(teszt);
    std::cout << "\nHozzaadtam egy olyan focicsapatot a listahoz aminek a parameterei a kovetkezok : proba, 11, proba, proba" << std::endl;
    std::cout << "Most toroljuk ki ezt a foci csapatot" << std::endl;
    std::cout << "\nValasszuk az 1-es menupontot es irjuk be a parameterket: proba, 11, proba, proba\n" << std::endl;

    Csapat* teszt_torlendo = Csapat_kivalaszt();
    while (teszt_torlendo == nullptr || strcmp(teszt_torlendo->GetNev(), "proba") != 0)
    {
        std::cout << "Kerem a kovetkezoketadja valassza: 1-es menupontot es a parameterk: proba, 11, proba, proba" << std::endl;
        delete teszt_torlendo;
        teszt_torlendo = Csapat_kivalaszt();
    }
    std::cout << "Ezek a bevitt ertekek" << std::endl;
    teszt->kiir();
    lista.torol(teszt_torlendo);
    EXPECT_FALSE(lista.keres(teszt_torlendo)) << "Hozzaadtuk, majd kitoroltuk, nem talalhatjuk meg" << std::endl;

    lista.Listafelszabadit();
    ENDM;

    TEST(Kosar_Torles, Hozzaadas->Torles)
        Lista lista;
    Csapat* teszt = new Kosar_Csapat("proba", 11, "proba", 11);
    lista.add(teszt);
    std::cout << "\nHozzaadtam egy olyan kosarcsapatot a listahoz aminek a parameterei a kovetkezok : proba, 11, proba, 11" << std::endl;
    std::cout << "Most toroljuk ki ezt a kosar csapatot" << std::endl;
    std::cout << "\nValasszuk az 2-es menupontot es irjuk be a parameterket: proba, 11, proba, 11\n" << std::endl;

    Csapat* teszt_torlendo = Csapat_kivalaszt();
    while (teszt_torlendo == nullptr || strcmp(teszt_torlendo->GetNev(), "proba") != 0)
    {
        std::cout << "Kerem a kovetkezoketadja valassza: 2-es menupontot es a parameterk: proba, 11, proba, 11" << std::endl;
        delete teszt_torlendo;
        teszt_torlendo = Csapat_kivalaszt();
    }
    std::cout << "Ezek a bevitt ertekek" << std::endl;
    teszt->kiir();
    lista.torol(teszt_torlendo);
    EXPECT_FALSE(lista.keres(teszt_torlendo)) << "Hozzaadtuk, majd kitoroltuk, nem talalhatjuk meg" << std::endl;

    lista.Listafelszabadit();
    ENDM;

    TEST(Kezi_Torles, Hozzaadas->Torles)
        Lista lista;
    Csapat* teszt = new Kosar_Csapat("proba", 11, "proba", 1111);
    lista.add(teszt);
    std::cout << "\nHozzaadtam egy olyan kezicsapatot a listahoz aminek a parameterei a kovetkezok : proba, 11, proba, 1111" << std::endl;
    std::cout << "Most toroljuk ki ezt a kosar csapatot" << std::endl;
    std::cout << "\nValasszuk az 3-es menupontot es irjuk be a parameterket: proba, 11, proba, 1111\n" << std::endl;

    Csapat* teszt_torlendo = Csapat_kivalaszt();
    while (teszt_torlendo == nullptr || strcmp(teszt_torlendo->GetNev(), "proba") != 0)
    {
        std::cout << "Kerem a kovetkezoketadja valassza: 3-es menupontot es a parameterk: proba, 11, proba, 1111" << std::endl;
        delete teszt_torlendo;
        teszt_torlendo = Csapat_kivalaszt();
    }
    std::cout << "Ezek a bevitt ertekek" << std::endl;
    teszt->kiir();
    lista.torol(teszt_torlendo);
    EXPECT_FALSE(lista.keres(teszt_torlendo)) << "Hozzaadtuk, majd kitoroltuk, nem talalhatjuk meg" << std::endl;

    lista.Listafelszabadit();
    ENDM;

    TEST(Operator !=, Overload test)
       
        int helyes = 0;
    Foci_Csapat* foci1 = new Foci_Csapat("a", 1, "a", "a");
    Foci_Csapat* foci2 = new  Foci_Csapat("b", 2, "b", "b");
    if (*foci1 != *foci2)
        helyes++;
   Kosar_Csapat* kosar1 = new Kosar_Csapat("a", 1, "a", 1);
   Kosar_Csapat* kosar2 = new Kosar_Csapat("b", 2, "b", 2);
    if (*kosar1 != *kosar2)
        helyes++;
    Kezi_Csapat* kezi1 = new Kezi_Csapat("a", 1, "a", 100);
    Kezi_Csapat* kezi2 = new Kezi_Csapat("b", 2, "b", 200);
    if (*kezi1 != *kezi2)
        helyes++;
    delete foci1;
    delete foci2;
    delete kosar1;
    delete kosar2;
    delete kezi1;
    delete kezi2;
    EXPECT_TRUE(helyes == 3);
    ENDM;


    return 0;
}

int main(int argc, char** argv) {
#if defined(CPORTA)
    testMain();
#else
    releaseMain(argc, argv);
#endif
}
