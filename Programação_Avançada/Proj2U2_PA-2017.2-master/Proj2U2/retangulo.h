#ifndef RETANGULO_H
#define RETANGULO_H

#include "FiguraGeometrica.h"
#include "reta.h"

/**
 * @brief Classe Abstrata FiguraGeometrica oferece suporte para a para representação de
 *  objetos primitivos genéricos Geometricos.
 */
class Retangulo : public FiguraGeometrica
{
private:
    Reta r1,r2,r3,r4;
    int x1, y1, largura, altura, estado;
public:
    /**
     * @brief Retangulo é o contrutor da Classe de mesmo nome.
     * @param x recebe o valor definido pelo usuario para preencher o valor que definirá a coordenada x do
     * vertice superior esquerdo que é o ponto de origem do retângulo na tela, a partir do qual o retângulo será desenhado.
     * @param y recebe o valor definido pelo usuario para preencher o valor que definirá a coordenada y do
     * vertice superior esquerdo que é o ponto de origem do retângulo na tela, a partir do qual o retângulo será desenhado.
     * @param largura recebe o valor definido pelo usuario para preencher o valor que definirá a largura do retângulo na tela.
     * @param altura recebe o valor definido pelo usuario para preencher o valor que definirá a altura do retângulo na tela.
     * @param _estado recebe o valor definido pelo usuario para sinalizar de o retangulo será preencher ou vazio.
    */
    Retangulo(int _x, int _y, int _largura, int _altura, int _estado);

    /**
     * @brief ~Retangulo é o destrutor da Classe Retangulo.
    */
    ~Retangulo();

    /**
     * @brief draw é uma função que permite que a figura geométrica retângulo seja desenhada na tela, com o auxílio da Classe Reta.
     * @param t é a tela na qual desejamos desenhar.
    */
    void draw(Screen &t);
};

#endif // RETANGULO_H
