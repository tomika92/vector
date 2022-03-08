#pragma once
#include <iostream>
using namespace std;
class MCoord
{
protected:
	double* pcoord;
public:
	MCoord(double xx, double yy); //Tworzy MCoord przechowujacy x i y
	MCoord() { pcoord = NULL; } //Tworzy pusty Mcoord
	~MCoord(); //Zwalnia pamiêc
	MCoord(const MCoord& wzor); //Konstruktor kopiujacy
	MCoord& operator=(const MCoord& wz); //Przecia¿enie operatora =
	double getcoord() const; //Odczytuje x
	double getcoord2() const; //Odczytuje y
	void setcoord(double zm); //Zapisuje x
	void setcoord2(double zm); //Zapisuje y
};

