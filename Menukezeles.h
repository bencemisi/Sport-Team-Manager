#pragma once
#include <iostream>

//Ebben a .h-ban csak olyan fuggvenyek vannak ,amik csak "rajzolnak" a console ablakra, illetve egy ami a menupontvalasztasert felel
void logo_rajz();				//Ez a logot rajzolja
void menukiiras();				//Ez a kezdomenut rajzolja
int menupontvalasztas();		//Ezt sok helyen hasznalom mert mindig 4 valasztasa van a felhasznalonak
void Csapatkiiras();			//Kiirja a valasztasi lehetosegeket, a menupontvalasztasok utan