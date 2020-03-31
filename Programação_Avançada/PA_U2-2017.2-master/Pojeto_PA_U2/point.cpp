#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point(float _x, float _y)
{
    //cout usado em demonstrações e testes
    //cout << "Novo Ponto construido" << endl;
    x=_x;
    y=_y;
}

Point::~Point()
{
    //cout usado em demonstrações e testes
    //cout << "Ponto destruido" << endl;
}

void Point::setX(float _x)
{
    //Mudança da coordenada x para _x, cout usado em demonstrações e testes
    //cout << "Point(" << x << ",y) <-> Point(" << _x <<",y)\n";
    x = _x;
}

void Point::setY(float _y)
{
    //Mudança da coordenada y para _y, cout usado em demonstrações e testes
    //cout << "Point(x," << y << ") <-> Point(x," << _y <<")\n";
    y = _y;
}

void Point::setXY(float _x, float _y)
{
    //Mudança da coordenada x para _x e y para _y, cout usado em demonstrações e testes
    //cout << "Point(" << x << "," << y << ") <-> Point(" << x << "," << _y <<")\n";
    x = _x;
    y = _y;
}

float Point::getX()
{
    return x;
}

float Point::getY()
{
   return y;
}

Point Point::add(Point p1)
{
    Point pAux;
    pAux.x = x + p1.x;
    pAux.y = y + p1.y;
    return pAux;
}

Point Point::sub(Point p1)
{
    Point pAux;
    pAux.x = x - p1.x;
    pAux.y = y - p1.y;
    return pAux;
}

float Point::norma()
{
    return sqrt(x*x+y*y);
}

void Point::transladaPoint(float a, float b)
{
    x=x+a;
    y=y+b;
}

void Point::printPoint()
{
    cout << "(" << x << "," << y << ")";
}
