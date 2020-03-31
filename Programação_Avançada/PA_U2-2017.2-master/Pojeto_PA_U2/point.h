#ifndef POINT_H
#define POINT_H

/**
 * @brief A classe Point implementa vetores 2D como representação de pontos no espaço bidimensional.
 * Esta classe serve para oferecer suporte no gerenciamento de operações que envolvem pontos..
 */
class Point
{
private:
    /**
     * @brief Poligono é o construtor da classe de mesmo nome, é usado para inicializar os itens da classe.
    */
    float x,y;

public:
    /**
     * @brief Point é o construtor da classe de mesmo nome, é usado para inicializar os itens da classe.
     * @param _x recebe o valor definido pelo usuario para previamente preencher o valor x do ponto.
     * Caso não haja o fornecimento de um valor para _x, x receberá altomaticamente o valor 0 (zero).
     * @param _y recebe o valor definido pelo usuario para previamente preencher o valor y do ponto.
     * Caso não haja o fornecimento de um valor para _y, y receberá altomaticamente o valor 0 (zero).
    */
    Point(float _x=0, float _y=0);

    /**
     *@brief ~Point é o destrutor da classe Point, é usado para finalizar os itens da classe.
    */
    ~Point();

    /**
     * @brief setX serve para definir um valor ao x do ponto.
     * @param _x recebe um valor fornecido pelo usuario para ser atribuido ao x do ponto.
     */
    void setX(float _x);

    /**
     * @brief setY serve para definir um valor ao y do ponto.
     * @param _y recebe um valor fornecido pelo usuario para ser atribuido ao y do ponto.
     */
    void setY(float _y);

    /**
     * @brief setXY serve para definir um valor ao x e um y do ponto, em uma mesma função.
     * @param _x recebe um valor fornecido pelo usuario para ser atribuido ao x do ponto
     * @param _y recebe um valor fornecido pelo usuario para ser atribuido ao y do ponto.
     */
    void setXY(float _x, float _y);

    /**
     * @brief getX serve para recuperar o valor de x do ponto.
     * @return O valor de x do ponto.
     */
    float getX();

    /**
     * @brief getY serve para recuperar o valor de Y do ponto.
     * @return O valor de y do ponto.
     */
    float getY();

    /**
     * @brief add adiciona as coordenadas (x,y) do Point com as coordenadas de um Point P1(x1,y1) fornecido,
     * armazenando o resultado (x+x1,y+y1) nas coordenadas de um novo Point,
     * que deverá ser retornado para o cliente da classe.
     * @param p1 (ponto com as coordenadas a serem adicionadas ao ponto que fez a chamada da função).
     * @return Ponto com coordenadas (x+x1,y+y1).
     */
    Point add(Point p1);

    /**
     * @brief sub subtrai as coordenadas (x,y) do Point com as coordenadas de um Point P1(x1,y1) fornecido,
     * armazenando o resultado (x−x1,y−y1) nas coordenadas de um novo Point,
     * que deverá ser retornado para o cliente da classe.
     * @param p1 (ponto com as coordenadas a serem subtraidas do ponto que fez a chamada da função).
     * @return Ponto com coordenadas (x+x1,y+y1).
     */
    Point sub(Point p1);

    /**
     * @brief norma calcula a distância do ponto para a origem do sistema de coordenadas.
     * @return Distância entre o ponto e o origem.
     */
    float norma();

    /**
     * @brief Translada o Point (x,y) de (+a,+b) de modo que, após a execução do método,
     * as coordenadas do Point serão (x+a,y+b).
     * @param a quntidade da qual x será deslocado.
     * @param b quntidade da qual y será deslocado.
     */
    void transladaPoint(float a, float b);

    /**
     * @brief Imprime o ponto no forma (x,y).
     */
    void printPoint();
};
#endif // POINT_H
