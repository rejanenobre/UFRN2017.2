#include "retangulo.h"
#include "reta.h"
#include "screen.h"

#include <iostream>

using namespace std;

Retangulo::Retangulo(int _x, int _y, int _largura, int _altura, int _estado)
{
    x1 = _x;
    y1 = _y;
    largura = _largura;
    altura = _altura;
    estado = _estado;

    Reta r1Aux(x1,y1, x1,y1-altura), r2Aux(x1,y1-altura, x1+largura,y1-altura);
    Reta r3Aux(x1+largura,y1-altura, x1+largura,y1), r4Aux(x1+largura, y1, x1,y1);

    r1 = r1Aux;
    r2 = r2Aux;
    r3 = r3Aux;
    r4 = r4Aux;
}

Retangulo::~Retangulo()
{
}

void Retangulo::draw(Screen &t)
{
    r1.draw(t);
    r2.draw(t);
    r3.draw(t);
    r4.draw(t);

    if(estado>0)
    {
        for(int j = y1; j > (y1-altura); j--)
        {
            for(int i = x1; i < (x1+largura); i++) t.setPixel(i,j);
        }
    }
}
