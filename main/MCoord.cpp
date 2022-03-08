#include "MCoord.h"
#include "Mess.h"
MCoord::MCoord(double xx, double yy)//Tworzy MCoord przechowujacy x i y
{
	try
	{
		pcoord = new double[2];
	}
	catch (bad_alloc)
	{
		my_mess.mess(MEMORY_ALLOC_ERROR);
	}

	pcoord[0] = xx;
	pcoord[1] = yy;
}

MCoord::~MCoord()//Zwalnia pamiêc
{
	if (pcoord)
	{
		delete[] pcoord;
	}
}

MCoord::MCoord(const MCoord& wzor)//Konstruktor kopiujacy
{
	try
	{
		pcoord = new double[2];
	}
	catch (bad_alloc)
	{
		my_mess.mess(MEMORY_ALLOC_ERROR);
	}

	for (int nr = 0; nr < 2; ++nr)
	{
		pcoord[nr] = wzor.pcoord[nr];
	}
}

MCoord& MCoord::operator=(const MCoord& wz)//Przecia¿enie operatora =
{
	if (this != &wz)
	{
		delete pcoord;
		try
		{
			pcoord = new double[2];
		}
		catch (bad_alloc)
		{
			my_mess.mess(MEMORY_ALLOC_ERROR);
		}

		pcoord[0] = wz.pcoord[0];
		pcoord[1] = wz.pcoord[1];
	}
	return *this;
}

double MCoord:: getcoord() const//Odczytuje x
{
	return pcoord[0];
}

double MCoord::getcoord2() const//Odczytuje y
{
	return pcoord[1];
}

void MCoord::setcoord(double zm)//Zapisuje x
{
	pcoord[0] = zm;
}

void MCoord::setcoord2(double zm)//Zapisuje y
{
	pcoord[1] = zm;
}