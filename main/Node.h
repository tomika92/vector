#pragma once
#include "MCoord.h"
class Node :
    public MCoord
{
    int numb; //numer wierzcholka
    char str[512]; //nazwa wierzcholka
public:
    Node(int nb, char* st, double xx, double yy); //Tworzy Node przechowujacy konkretne wartosci
    Node(); //Tworzy pusty Node
    Node(const Node& wzorzec); //Konstruktor kopiuj¹cy
    Node& operator=(const Node& ww); //Przeci¹¿enie operatora =
    bool operator==(const int lhs); //Przeci¹zenie operatora ==
    friend istream& operator >> (istream& stream, Node &ob); //Przeci¹¿enie operatora >>
    friend ostream& operator << (ostream& stream, const Node &ob); //Przeci¹¿enie operatora <<
};
