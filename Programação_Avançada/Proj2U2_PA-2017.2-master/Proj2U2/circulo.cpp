#include "circulo.h"
#include "screen.h"
#include "reta.h"

#include <iostream>

using namespace std;

Circulo::Circulo(int _xc, int _yc, int _raio, int _estado)
{
    xc = _xc;
    yc = _yc;
    raio = _raio;
    estado = _estado;
}

Circulo::~Circulo()
{
}

void Circulo::draw(Screen &t)
{
    int x, y, d, deltaE, deltaSE;
        x = 0;
        y = raio;
        d = 1 - raio;
        deltaE = 3;
        deltaSE = -2*raio + 5;

        t.setPixel(xc+x,yc+y); t.setPixel(xc+x,yc-y);
        t.setPixel(xc-x,yc+y); t.setPixel(xc-x,yc-y);
        t.setPixel(yc+y,xc+x); t.setPixel(yc+y,xc-x);
        t.setPixel(yc-y,xc+x); t.setPixel(yc-y,xc-x);

        while (y > x)
        {
            if (d < 0)
            {
                d = d + deltaE;
                deltaE = deltaE + 2;
                deltaSE = deltaSE + 2;
                x++;
            }
            else
            {
                d = d + deltaSE;
                deltaE = deltaE + 2;
                deltaSE = deltaSE + 4;
                x++;
                y--;
            }

            t.setPixel(xc+x,yc+y); t.setPixel(xc+x,yc-y);
            t.setPixel(xc-x,yc+y); t.setPixel(xc-x,yc-y);
            t.setPixel(yc+y,xc+x); t.setPixel(yc+y,xc-x);
            t.setPixel(yc-y,xc+x); t.setPixel(yc-y,xc-x);
        }

        if(estado>0)
        {
            int a;
            for(int i=(xc-raio); i<(xc+raio); i++)
            {
                for(int j=(yc-raio); j<(yc+raio); j++)
                {
                    a = ((xc-i)*(xc-i)+(yc-j)*(yc-j)- raio*raio);
                    if(a<=0) t.setPixel(i,j);
                }
             }
        }
}
