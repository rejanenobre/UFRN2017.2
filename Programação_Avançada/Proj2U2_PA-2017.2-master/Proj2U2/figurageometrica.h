#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "screen.h"

/**
 * @brief Classe Abstrata FiguraGeometrica oferece suporte para a para representação de objetos primitivos genéricos Geometricos.
 */
class FiguraGeometrica
{
public:
    /**
     * @brief FiguraGeometrica é o contrutor da Classe de mesmo nome.
    */
    FiguraGeometrica();

    /**
     * @brief draw é uma função virtual pura que obriga as Classes Herdeiras da Classe Abstrata FiguraGeometrica a
     * possuirem uma função draw(Screen &t) propria. A função draw das herdeiras permite que uma figura geométrica
     * seja desenhada na tela t. (Nota: As Classes Herdeiras da Classe Abstrata FiguraGeometrica são as Classes: Circulo,
     * Reta e Retangulo.)
     * @param t é a tela na qual desejamos desenhar.
    */
    virtual void draw(Screen &t)=0;//força a criação da função nas herdeiras
};

#endif // FIGURAGEOMETRICA_H
