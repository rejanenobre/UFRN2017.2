#ifndef POLIGONO_H
#define POLIGONO_H

#include "Point.h"

/**
 * @brief A classe Poligono é usada para representar polígonos convexos de até 100 vertice no espaço bidimensional
 * atraves do uso de vetores 2D como representação dos vertice de tal poligono.
 * Esta classe serve para oferecer suporte no gerenciamento de operações com polígonos convexos..
 */

class Poligono
{
protected:
    /**
     * @brief Vertices armazena os vertices inserido no poligono trabalhado.
    */
    Point *Vertices;

    /**
     * @brief nVert armazena o número de vertices que o poligono trabalhado possui.
    */
    int nVert;

public:
    /**
     * @brief Poligono é o construtor da classe de mesmo nome, é usado para inicializar os itens da classe.
    */
    Poligono();

    /**
     * @brief Poligono é o destrutor da classe Poligono, é usado para finalizar os itens da classe.
    */
    ~Poligono();

    /**
     * @brief addVertice é utilizada para inserir um novo vertice ao poligono que está sendo trabalhado.
     * @param p (ponto que está sendo agregado ao poligono como novo Vertice).
    */
    void addVertice(Point p);

    /**
     * @brief nVertices é utilizada para recuperar o numero de vertices que há no poligono trabalhado
     * @return Número de vertices do poligono.
    */
    int nVertices();

    /**
     * @brief Area é utilizada para calcular a área do poligono trabalhado.
     * @return Área do poligono trabalhado.
    */
    float Area();

    /**
     * @brief transladaPoligono transladar o polígono em (+a,+b).
     * @param a quntidade da qual as coordenadas x do poligono serão deslocados.
     * @param b quntidade da qual as coordenadas y do poligono serão deslocados.
    */
    void transladaPoligono(float a, float b);

    /**
     * @brief rotaciona serve para rotacionar o polígono de theta graus no sentido anti-horário
     * em torno de um ponto (x0,y0) fornecido pelo usuário.
     * @param theta (graus de rotação).
     * @param _x é a coordenada x do ponto do qual o poligono irá rotacionar.
     * @param _y é a coordenada y do ponto do qual o poligono irá rotacionar.
    */
    void rotaciona(float theta, float _x, float _y);

    /**
     * @brief printPoligono serve para Imprimir o polígono armazenado da forma
     * (x0,y0)->(x1,y1)->...->(xN−1,yN−1)->(x0,y0).
    */
    void printPoligono();
};

#endif // POLIGONO_H
