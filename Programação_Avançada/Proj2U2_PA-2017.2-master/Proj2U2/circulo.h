#ifndef CIRCULO_H
#define CIRCULO_H

#include "FiguraGeometrica.h"
#include "screen.h"
#include "reta.h"

/**
 * @brief A classe Circulo oferece suporte para a construção e desenho de Figuras Geométricas do tipo Círculo.
 */
class Circulo : public FiguraGeometrica
{
private:
    int xc, yc, raio, estado;

public:
    /**
     * @brief Circulo é o construtor da classe de mesmo nome, é usado para inicializar os itens da classe.
     * @param _xc recebe o valor definido pelo usuario para preencher o valor x da coordenada do centro do círculo.
     * @param _yc recebe o valor definido pelo usuario para preencher o valor y da coordenada do centro do círculo.
     * @param _raio recebe o valor definido pelo usuario para definir o tamanho do raio da circunferencia.
     * @param _estado recebe o valor definido pelo usuario para definir se a classe deverá tratar com um círculo preenchido (_estados=1)
     * ou apenas com uma circunferencia (_estados=0).
    */
    Circulo(int _xc, int _yc, int _raio, int _estado);

    /**
     * @brief ~Circulo é o destrutor da Classe Circulo.
    */
    ~Circulo();

    /**
     * @brief draw é uma função que permite que a figura geométrica circulo seja desenhada na tela a partir
     *  do Algoritmo da Circunferencia de Bresenham, adaptado para que haja a possibilidade de se desenhar um
     *  circulo preenchido.
     * @param &t representa a tela na qual desejamos desenhar.
    */
    void draw(Screen &t);
};

#endif // CIRCULO_H
