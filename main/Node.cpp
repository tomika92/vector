#include "Node.h"
#include "Mess.h"

Node::Node(): MCoord()//Tworzy pusty Node
{
    numb = 0;
    *str = NULL;
    if (pcoord == NULL)
    {
        try
        {
            pcoord = new double[2];
        }
        catch (bad_alloc)
        {
            my_mess.mess(MEMORY_ALLOC_ERROR);
        }

        pcoord[0] = 0;
        pcoord[1] = 0;
    }
}

Node::Node(int nb, char* st, double xx, double yy) : MCoord(xx, yy)//Tworzy Node przechowujacy konkretne wartosci
{
    numb = nb;
    *str = *st;
}

Node::Node(const Node& wzorzec) : MCoord(wzorzec)//Konstruktor kopiuj¹cy
{
    numb = wzorzec.numb;
    memcpy(str, wzorzec.str, 512 * sizeof(char));
}

Node& Node::operator=(const Node& ww)//Przeci¹¿enie operatora =
{
    if (this != &ww)
    {
        MCoord::operator=(ww);
        numb = ww.numb;
        memcpy(str, ww.str, 512 * sizeof(char));
    }
    return *this;
}

bool Node::operator==(const int lhs)//Przeci¹zenie operatora ==
{
    return numb == lhs;
}

istream& operator >> (istream& stream, Node &ob)//Przeci¹¿enie operatora >>
{
    double a, b;
    stream >> a >> b >> ob.numb >> ob.str;
    ob.setcoord(a);
    ob.setcoord2(b);
    return stream;
}
ostream& operator << (ostream& stream, const Node &ob)//Przeci¹¿enie operatora <<
{
    //x,y,numb,str
    double a, b;
    a = ob.getcoord();
    b = ob.getcoord2();
    stream << "x = " << a << ", y = " << b << ", nr wierzcholka = " << ob.numb << ", nazwa wierzcholka = " << ob.str;
    return stream;
}

