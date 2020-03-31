#include "Retangulo.h"
#include "Point.h"
#include "Poligono.h"
#include <iostream>

using namespace std;

Retangulo::Retangulo()
{
    //cout usado em demonstrações e testes
    //cout << "Retangulo criado, sem vertices\n";
}

Retangulo::Retangulo(float _x, float _y, float largura, float altura)
{
    //cout usado em demonstrações e testes
    //cout << "Retangulo criado\n";
    Point p(_x,_y);

    if (largura==0 ||altura==0)
    {
        addVertice(p);
    }
    else
    {
       addVertice(p);

       p.transladaPoint(0,-altura);
       addVertice(p);

       p.transladaPoint(largura,0);
       addVertice(p);

       p.transladaPoint(0,altura);
       addVertice(p);
    }
}

Retangulo::~Retangulo()
{
    //cout usado em demonstrações e testes
    //cout << "Retangulo destruido\n";
}
