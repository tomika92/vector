#include <iostream>
#include <fstream>
#include "Vector.h"
#include "VectorFile.h"
#include "MCoord.h"
#include "Node.h"
#include "Mess.h"

using namespace std;

int main()
{
	bool do_while = true;
	VectorFile<Node> dane;
	
	int wyb;
	while (do_while)
	{
		cout << "1 - dodanie obiektu\n2 - usuniecie obiektu\n3 - czyszczenie tablicy obiektow\n4 - modyfikacja obiektu\n5 - usuniecie konkretnego obiektu\n6 - znalezienie obiektow zgodnych z kluczem\n7 - zapisanie danych na dysk\n8 - odczyt danych z dysku\n9 - wyswietlenie danych na ekranie\n0 - zakonczenie programu\n";
		cin >> wyb;
		switch (wyb)
		{
			case 1:
			{
				printf("Podaj x, y, numer wierzcholka i nazwe wierzcholka\n");
				Node zmien; 
				cin >> zmien;
				dane.pushBack(zmien);
				break;
			}
			case 2:
				dane.popBack();
				break;
			case 3:
				dane.clear();
				break;
			case 4:
			{
				int number;
				cout << "Podaj nr obiektu do modyfikacji\n";
				cin >> number;
				if (number <= dane.size() && number > 0)
				{
					printf("Podaj x, y, numer wierzcholka i nazwe wierzcholka\n");
					Node* t = NULL;
					t = dane.at(number - 1);
					cin >> *t;
				}
				else
				{
					my_mess.mess(OUT_OF_RANGE_WARN);
				}
			}
				break;
			case 5:
			{
				int number;
				cout << "Podaj obiekt do usuniecia\n";
				cin >> number;
				if (number <= dane.size() && number > 0)
				{
					dane.erase(number - 1);
				}
				else
				{
					my_mess.mess(OUT_OF_RANGE_WARN);
				}
				break;
			}
			case 6:
			{
				int number;
				cout << "Podaj szukana liczbe\n";
				cin >> number;
				bool szuk = false;
				Node* t = dane.front();
				while ((t = ::find(t, dane.back(), number)))
				{
					cout << *t << endl;
					szuk = true;
					t++;
				}
				if (!szuk)
				{
					cout << "Nie znaleziono danych o zadanej wartosci\n";
				}
				break;
			}
			case 7:
			{
				ofstream plik;
				plik.open("mydata.dat", ios::out | ios::binary);
				if (!plik.is_open())
				{
					my_mess.mess(OPEN_FILE_ERROR);
				}
				plik << &dane;
				plik.close();
				break;
			}
			case 8:
			{
				ifstream plik2;
				plik2.open("mydata.dat", ios::in | ios::binary);
				if (!plik2.is_open())
				{
					my_mess.mess(OPEN_FILE_ERROR);
				}
				plik2 >> &dane;
				plik2.close();
				break;
			}
			case 9:
			{
				int p=1;
				for (Node* first = dane.front(); first <= dane.back(); ++first, ++p)
				{
					cout << p << ". " << *first << endl;
				}
				break;
			}
			case 0:
				do_while = false;
				break;
			default:
				cout << "Nie ma takiej opcji\n";
		}
	}
}