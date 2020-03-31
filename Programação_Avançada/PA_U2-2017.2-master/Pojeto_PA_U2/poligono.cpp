#include "Poligono.h"
#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

Poligono::Poligono()
{
    nVert=0;
    Vertices = new Point[100];
    //cout usado em demonstrações e testes
    //cout << "Novo Poligono criado" << endl;
}

Poligono::~Poligono()
{
    delete [] Vertices;
    //cout usado em demonstrações e testes
    //cout << "Poligono Destruido" << endl;
}

void Poligono::addVertice(Point p)
{
    if(nVert<100)
    {
        Vertices[nVert] = p;
        nVert=nVert+1;
    }
    else cout << "O novo vertice nao foi salvo, o limite de insercao de 100 vertices foi atingido." << endl;
}

int Poligono::nVertices()
{
    return nVert;
}

float Poligono::Area()
{
    float somaX, somaY, Area, xAux, yAux;

    xAux = Vertices[nVert-1].getX();
    yAux = Vertices[0].getY();
    somaX = xAux*yAux;

    xAux = Vertices[0].getX();
    yAux = Vertices[nVert-1].getY();
    somaY = yAux*xAux;

    for(int i=0; i<nVert-1; i++)
    {
        xAux = Vertices[i].getX();
        yAux = Vertices[i+1].getY();
        somaX = somaX + xAux*yAux;

        xAux = Vertices[i+1].getX();
        yAux = Vertices[i].getY();
        somaY = somaY + yAux*xAux;
    }

    Area = (somaY - somaX)/2;

    if(Area >= 0) return Area;
    else return (-Area);
}

void Poligono::transladaPoligono(float a, float b)
{
    for(int i=0; i<nVert; i++) Vertices[i].transladaPoint(a, b);
}

void Poligono::rotaciona(float theta, float _x, float _y)
{
    float xAux, yAux, xr, yr;

    transladaPoligono(-_x,-_y);

    for(int i=0; i<nVert; i++)
    {
        xAux = Vertices[i].getX();
        yAux = Vertices[i].getY();

        xr = xAux * cos(theta) - yAux * sin(theta);
        yr = xAux * sin(theta) + yAux * cos(theta);

        Vertices[i].setXY(xr,yr);
    }

    transladaPoligono(_x,_y);
}

void Poligono::printPoligono()
{
    for(int i=0; i<nVert; i++)
    {
        if(i != nVert-1)
        {
            Vertices[i].printPoint();
            cout << " -> ";
         }
        else
        {
            Vertices[i].printPoint();
            cout << " -> ";
            Vertices[0].printPoint();
        }
    }

    cout << endl;
}
