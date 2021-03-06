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
    Node(const Node& wzorzec); //Konstruktor kopiujący
    Node& operator=(const Node& ww); //Przeciążenie operatora =
    bool operator==(const int lhs); //Przeciązenie operatora ==
    friend istream& operator >> (istream& stream, Node &ob); //Przeciążenie operatora >>
    friend ostream& operator << (ostream& stream, const Node &ob); //Przeciążenie operatora <<
};
