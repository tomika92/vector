#pragma once
#include <new>
#include <iostream>
#include "Mess.h"
using namespace std;
template <typename type> class Vector
{
protected:
    type* data; //wskaŸnik s³u¿¹cy do przechowywania danych
    size_t allocatedDataSize; //rozmiar (liczba elementów) zaalokowanej pamiêci
    size_t usingDataSize; //rozmiar (liczba) u¿ywanych elementów

public:
    Vector(); //Tworzy pusty wektor
    Vector(size_t usingDataSize);//Tworzy wektor o podanym rozmiarze (usingDataSize)
    ~Vector(); //Zwalnia pamiêæ
	void pushBack(type newRecord); //Dodaje nowy element na koniec wektora
	void popBack(); //Usuwa ostatni element wektora
	type* front(); //Pobiera adres pierwszego elementu
	type* back(); //Pobiera adres ostatniego elementu
	size_t size(); //Zwraca rozmiar u¿ywanego wektora
	bool isEmpty(); //Sprawdza czy wektor jest pusty
	void shrinkToFit(); //Realokouje pamiêæ, aby dopasowaco do wielkosci uzywanego wektora
	void clear(); //Usuwa wszystkie elementy
	void erase(size_t index); //Usuwa element o wskazanym indeksie
	type* at(size_t index); //Pobiera element o danym indeksie
};

template <typename type>
Vector<type>::Vector() //Tworzy pusty wektor
{
	usingDataSize = 0;
	allocatedDataSize = 3;
	try
	{
		data = new type[allocatedDataSize];
	}
	catch (bad_alloc)
	{
		my_mess.mess(MEMORY_ALLOC_ERROR);
	}
}

template <typename type>
Vector<type>::Vector(size_t usingDataSize) : usingDataSize(usingDataSize)//Tworzy wektor o podanym rozmiarze (usingDataSize)
{
	allocatedDataSize = usingDataSize;
	try
	{
		data = new type[allocatedDataSize];
	}
	catch (bad_alloc)
	{
		my_mess.mess(MEMORY_ALLOC_ERROR);
	}
}

template<typename type>
Vector<type>::~Vector()//Zwalnia pamiêæ
{
	if (data)
	{
		delete[] data;
		data = NULL;
	}
}

template<typename type>
void Vector<type>::pushBack(type newRecord)//Dodaje nowy element na koniec wektora
{
	if (usingDataSize >= allocatedDataSize)
	{
		type* newData = NULL;
		try
		{
			newData = new type[usingDataSize + 5];
		}
		catch(bad_alloc)
		{
			my_mess.mess(MEMORY_ALLOC_ERROR);
		}
		for (int i = 0; i < usingDataSize; ++i)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		allocatedDataSize = usingDataSize + 5;
		data[usingDataSize] = newRecord;
		usingDataSize++;
	}
	else
	{
		data[usingDataSize] = newRecord;
		usingDataSize++;
	}
}

template<typename type>
void Vector<type>::popBack()//Usuwa ostatni element wektora
{
	if (usingDataSize > 0)
	{
		usingDataSize--;
	}
	else
	{
		my_mess.mess(EMPTY_ARRAY_WARN);
	}
}

template<typename type>
type* Vector<type>::front()//Pobiera adres pierwszego elementu
{
	return data;
}

template<typename type>
type* Vector<type>::back()//Pobiera adres ostatniego elementu
{
	return data + (usingDataSize - 1);
}

template<typename type>
size_t Vector<type>::size()//Zwraca rozmiar u¿ywanego wektora
{
	return usingDataSize;
}

template<typename type>
bool Vector<type>::isEmpty()//Sprawdza czy wektor jest pusty
{
	if (usingDataSize > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

template<typename type>
void Vector<type>::shrinkToFit()//Realokouje pamiêæ, aby dopasowaco do wielkosci uzywanego wektora
{
	if (usingDataSize < allocatedDataSize)
	{
		type* newData = NULL;
		try 
		{
			newData = new type[usingDataSize];
		}
		catch (bad_alloc)
		{
			my_mess.mess(MEMORY_ALLOC_ERROR);
		}
		
		for (int i = 0; i < usingDataSize; ++i)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		allocatedDataSize = usingDataSize;
	}
}

template<typename type>
void Vector<type>::clear()//Usuwa wszystkie elementy
{
	delete[] data;
	usingDataSize = 0;
	allocatedDataSize = 5;
	try
	{
		data = new type[allocatedDataSize];
	}
	catch(bad_alloc)
	{
		my_mess.mess(MEMORY_ALLOC_ERROR);
	}
}

template<typename type>
void Vector<type>::erase(size_t index)//Usuwa element o wskazanym indeksie
{
	if (usingDataSize <= index)
	{
		cout << "Nie ma takiego elementu wektora\n";
	}
	else
	{
		for (size_t i = index+1; i < usingDataSize; i++)
		{
			data[i-1] = data[i];
		}
		usingDataSize--;
	}
}

template<typename type>
type* Vector<type>::at(size_t index)//Pobiera element o danym indeksie
{
	if (index < usingDataSize)
	{
		return &data[index];
	}
	else
	{
		cout << "Nie ma takiego elementu wektora\n";
	}
}

template<class T, class Key>
T* find(const T* p_begin, const T* p_end, const Key& k)//Wyszukuje elementy w tablicy
{
	for (T* begin = const_cast<T*>(p_begin); begin <= p_end; begin++)
	{
		if (*begin == k)
		{
			return begin;
		}
	}
	return NULL;
}