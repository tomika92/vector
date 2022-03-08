#pragma once
#include <fstream>
#include "Vector.h"
template <typename type> class VectorFile :
    public Vector<type> //Przechowuje dane
{
public:
    VectorFile(); //Tworzy pusty VectorFile
    VectorFile(size_t usingDataSize); //Tworzy VectorFile o podanym rozmiarze (usingDataSize)
    friend ostream& operator << <>(ostream& os, VectorFile<type> *ob); //Zapisuje dane do pliku binarnego
    friend istream& operator >> <>(istream& os, VectorFile<type> *ob); //Odczytuje dane z pliku binarnego
};

template <typename type>
VectorFile<type>::VectorFile() :Vector<type>()//Tworzy pusty VectorFile
{

}

template <typename type>
VectorFile<type>::VectorFile(size_t usingDataSize) : Vector<type>(usingDataSize)//Tworzy VectorFile o podanym rozmiarze (usingDataSize)
{

}

template <typename type>
ostream& operator << <>(ostream& os, VectorFile<type> *ob)//Zapisuje dane do pliku binarnego
{
    os.write(reinterpret_cast<const char*>(ob), sizeof(ob));
    if (os.bad() || os.fail())
    {
        my_mess.mess(WRITE_FILE_ERROR);
    }

    for (type* first = ob->front(); first != NULL && first <= ob->back(); first++)
    {
        os << *first;
    }
    return os;
} 

template <typename type>
istream& operator >> <>(istream& os, VectorFile<type> *ob)//Odczytuje dane z pliku binarnego
{
    if (ob->data)
    {
        delete[] ob->data;
    }
    os.read(reinterpret_cast<char*>(ob), os.tellg());
    if (os.bad() || os.fail())
    {
        my_mess.mess(READ_FILE_ERROR);
    }

    try
    {
        ob->data = new type[ob->allocatedDataSize];
    }
    catch (bad_alloc)
    {
        my_mess.mess(MEMORY_ALLOC_ERROR);
    }

    for (type* first = ob->front(); first != NULL && first <= ob->back(); first++)
    {
        os >> *first;
    }
    return os;
}
