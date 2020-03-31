#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <cmath>
#include <QDebug>
#include <vector>

using namespace std;

Plotter::Plotter(QWidget *parent) :
  QWidget(parent)
{
}

void Plotter::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  QBrush brush;
  QPen pen;
  int i;

  //para não parecer serilhado
  painter.setRenderHint((QPainter::Antialiasing));

  brush.setColor(QColor(255,255,200));
  brush.setStyle(Qt::SolidPattern);

  pen.setColor(QColor(255,0,0));
  pen.setWidth(3);

  painter.setBrush(brush);
  painter.setPen(pen);

  // desenha o fundo do plotter
  painter.drawRect(0,0,width(), height());

  pen.setColor(QColor(0,0,255));
  pen.setWidth(2);
  painter.setPen(pen);

  // desenha grafico
  if(times.size() == 0)
  {
      for(i=0; i<30; i++)
      {
          times.push_back(i);
          dados.push_back(0);
      }
  }

  double x1, y1, x2, y2;
  if (times.size() == dados.size())
  {
      qDebug() << "dado " << 0 << ": " << dados[0];

      for(i = 1; i < times.size(); i++)
      {
        qDebug() << "dado " << i << ": " << dados[i];
        x1 = times[i-1]*width();
        y1 = height() - dados[i-1]*height();

        x2 = times[i]*width();
        y2 = height() - dados[i]*height();

        painter.drawLine(x1,y1,x2,y2);
      }
   }
   else qDebug() << "Ei! times.size() != dados.size()";
}

void Plotter::carregaDados(vector<double> _times, vector<double> _dados)
{
    times.clear();
    dados.clear();

    int i=0;
    double t, d;

    while((_times.size() + i) < 30)
    {
            times.push_back(0);
            i++;
    }
    for(i; i < 30; i++)
    {
       t = (_times[i] - _times[0])  /  (  _times[_times.size()-1]  -   _times[0]  );
       times.push_back(t);
    }

    i=0;
    while((_dados.size() + i) < 30)
    {
            dados.push_back(0);
            i++;
    }
    for(i; i < 30; i++)
    {
        d = _dados[i]  /  99.0;
        dados.push_back(d);
    }
}



