#include "reta.h"
#include "screen.h"

#include <iostream>
#include <cmath>

using namespace std;

int Reta::sgn(int x)
{
    if(x>0) return 1;
    else if(x<0) return -1;
    else return 0;
}

Reta::Reta(int _x1, int _y1, int _x2, int _y2)
{
    x1 = _x1;
    y1 = _y1;

    x2 = _x2;
    y2 = _y2;
}

Reta::~Reta()
{
}

void Reta::draw(Screen &t)
{
    /*http://agostinhobritojr.github.io/cursos/cg/linhas.html#(1)*/
    int x,y, Delta_x,Delta_y, Temp,Troca, s1,s2, new_e,i;
    x = x1;
    y = y1;

    Delta_x = abs(x2 - x1);
    Delta_y = abs(y2 - y1);

    s1 = sgn(x2 - x1);
    s2 = sgn(y2 - y1);

    if(Delta_y > Delta_x)
    {
      Temp = Delta_x;
      Delta_x = Delta_y;
      Delta_y = Temp;
      Troca = 1;
    }
    else Troca = 0;

    new_e = 2*Delta_y - Delta_x;
    for(i=1; i<= Delta_x; i++)
    {
      t.setPixel(x,y);
      while (new_e >= 0)
      {
        if(Troca == 1) x = x + s1;//Muda para a proxima linha de rasterização
        else y = y + s2;

        new_e = new_e - 2*Delta_x;
      }

      //Permanece nesta linha de rasterização
      if(Troca == 1) y = y + s2;
      else x = x + s1;

      new_e= new_e + 2*Delta_y;
    }
}

