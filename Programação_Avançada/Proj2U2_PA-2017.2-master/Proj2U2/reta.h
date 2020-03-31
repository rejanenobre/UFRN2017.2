#ifndef RETA_H
#define RETA_H

#include "FiguraGeometrica.h"
#include "screen.h"
/**
 * @brief A classe Reta oferece suporte para a construção e desenho de Figuras Geométricas do tipo Reta.
 */
class Reta : public FiguraGeometrica
{
private:
    int x1, y1, x2, y2;
    int sgn (int x);
public:
    /**
     * @brief Reta é o construtor da classe de mesmo nome, é usado para inicializar os itens da classe.
     * @param _x1 recebe o valor definido pelo usuario para preencher o valor x da coordenada do ponto inícial da reta.
     * @param _y1 recebe o valor definido pelo usuario para preencher o valor y da coordenada do ponto inícial da reta.
     * @param _x2 recebe o valor definido pelo usuario para preencher o valor x da coordenada do ponto final da reta.
     * @param _y2 recebe o valor definido pelo usuario para preencher o valor y da coordenada do ponto final da reta.
    */
    Reta(int _x1 =0, int _y1=0, int _x2=0, int _y2=0);

    /**
     * @brief ~Reta é o destrutor da Classe Reta.
    */
    ~Reta();

    /**
     * @brief draw é uma função que permite que a figura geométrica reta seja desenhada na tela a partir
     * do Algoritmo da Reta de Bresenham.
     * @param t é a tela na qual desejamos desenhar.
    */
    void draw(Screen &t);
};

#endif // RETA_H
