#ifndef RETANGULO_H
#define RETANGULO_H

#include "Poligono.h"

/**
 * @brief A classe Retangulo é usada para representar retangulos.
 * Esta classe serve para oferecer suporte no gerenciamento de operações com polígonos convexos de quatro lados.
 * É uma classe herdeira da classe Poligono..
 */
class Retangulo : public Poligono
{
public:

    /**
     * @brief Retangulo é um construtor da classe de mesmo nome, é usado para
     * inicializar os itens da classe quando o usuario não informa parametros.
    */
    Retangulo();

    /**
     * @brief Retangulo(float _x, float _y, float largura, float altura) é um construtor da classe de mesmo nome,
     * é usado para inicializar os itens da classe com parametros informados pelo usuario.
     * @param _x recebe o valor definido pelo usuario para previamente preencher o valor x do ponto.
     * Caso não haja o fornecimento de um valor para _x, x receberá altomaticamente o valor 0 (zero).
     * @param _y recebe o valor definido pelo usuario para previamente preencher o valor y do ponto.
     * Caso não haja o fornecimento de um valor para _y, y receberá altomaticamente o valor 0 (zero).
     * @param largura recebe a largura do Retangulo a ser criado.
     * @param altura recebe a altura do Retangulo a ser criado.
    */
    Retangulo(float _x=0, float _y=0, float largura =0, float altura=0);

    /**
     * @brief ~Retangulo é o destrutor da classe Retangulo, é usado para
     * finalizar os itens da classe.
    */
    ~Retangulo();
};

#endif // RETANGULO_H
