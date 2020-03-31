#include "screen.h"
#include "circulo.h"
#include "FiguraGeometrica.h"
#include "reta.h"
#include "retangulo.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Screen::Screen(int _nlin, int _ncol)
{
  nlin=_nlin;
  ncol=_ncol;
  mat = vector<vector<char>>(nlin, vector<char>(ncol,' '));
}

void Screen::setPixel(int x, int y)
{
    if(x>=0 && x<ncol && y>=0 && y<nlin) mat[y][x] = brush;
}

void Screen::clear()
{
    for(int i=0;i < nlin;i++)
    {
        for(int j=0;j < ncol;j++) mat[i][j] = ' ';
    }
}

void Screen::setBrush(char _brush)
{
    brush=_brush;
}

ostream& operator<<(ostream& os, Screen &t)
{
    for(int i=0;i < t.mat.size();i++)
    {
        for(int j=0;j < (t.mat[i].size());j++)
        {
            os << t.mat[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

void Screen::print_txt(Screen &tela, string &id_saida)
{
    ofstream saida;
    //abrindo o fluxo
    saida.open(id_saida);

    //verifiqca se o fluxo foi devidamente aberto
    if(saida.is_open()) cout << "abriu o arquivo\n";
    else cout << "Não abriu o arquivo\n";

    saida << tela;

    //fechar o fluxo
    saida.close();
}

void Screen::readDraw(Screen &tela, string &id_entrada)
{
    vector <FiguraGeometrica*> figuras;
    vector <char> newBrush;

    int a, b, c, d, e;
    char _brush;

    ifstream entrada;
    string s;

    entrada.open(id_entrada);
    if(entrada.is_open()) cout << "abriu arquivo de entrada\n";
    else cout << "nao abriu arquivo\n";

    while(entrada.good())
    {
        getline(entrada, s);

        stringstream ss(s);
        ss >> s;

        if(s=="circle")
        {
            ss >> a >> b >> c >> d;
            //Circulo(_xc, _yc, _raio, _estado)
            figuras.push_back(new Circulo(a,b,c,d));
            newBrush.push_back(brush);
         }
         else if(s=="rectangle")
         {
            ss >> a >> b >> c >> d >> e;
            //Retangulo( _x, _y, _largura, _altura, _estado)
            figuras.push_back(new Retangulo(a,b,c,d,e));
            newBrush.push_back(brush);
         }
         else if(s=="line")
         {
            ss >> a >> b >> c >> d;
            //Reta(_x1, _y1, _x2, _y2)
            figuras.push_back(new Reta(a,b,c,d));
            newBrush.push_back(brush);
         }
         else if (s=="dim")
         {
            ss >> ncol >> nlin;
         }
         else if (s=="brush")
         {
            ss >> _brush;
            if(ss.good()) brush=_brush;
            else brush=' ';
        }
    }

    //desenhar as figuras na tela
    vector <FiguraGeometrica*>::iterator it;
    int i =0;
    for(it=figuras.begin();it!=figuras.end();it++)
    {
        setBrush(newBrush[i]);
        (*it)->draw(tela);
        i++;
    }

    entrada.close();
}
