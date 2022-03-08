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
    Node(const Node& wzorzec); //Konstruktor kopiuj�cy
    Node& operator=(const Node& ww); //Przeci��enie operatora =
    bool operator==(const int lhs); //Przeci�zenie operatora ==
    friend istream& operator >> (istream& stream, Node &ob); //Przeci��enie operatora >>
    friend ostream& operator << (ostream& stream, const Node &ob); //Przeci��enie operatora <<
};
