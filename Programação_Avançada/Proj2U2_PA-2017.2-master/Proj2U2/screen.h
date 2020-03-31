#ifndef SCREEN_H
#define SCREEN_H

#include "screen.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
/**
 * @brief A Classe Screen prove suporte ao usuario para desenhar pontos em uma tela virtual.
 */
class Screen{
private:
  // armazenam o tamanho da tela de desenho, número de linhas e de colunas
  int nlin, ncol;

  // guarda o caractere usado para desenhar
  char brush;

  // armazena a matriz da tela
  vector< vector<char> > mat;

public:
  /**
   * @brief Screen é o contrutor da Classe de mesmo nome.
   * @param _nlin recebe o valor definido pelo usuario para preencher o valor que definirá a altura da tela criada.
   * @param _ncol recebe o valor definido pelo usuario para preencher o valor que definirá a largura da tela criada.
  */
  Screen(int _nlin, int _ncol);

  /**
   * @brief setPixel é uma função que permite que o usuário preencha a posição de coordenadas (x,y) da tela
   *  com o caractere armazenado em brush. (Nota: vide função setBrush)
   * @param x recebe o valor definido pelo usuario para a coordenada x a ser preenchida na tela.
   * @param y recebe o valor definido pelo usuario para a coordenada y a ser preenchida na tela.
  */
  void setPixel(int x, int y);

  /**
   * @brief clear é uma função que permite que o usuário "limpe" a tela ao substituir todos os espaço por ' ',
   * retornando ao estado inícial, sem Figuras Geometricas.
  */
  void clear();

  /**
   * @brief setBrush é uma função que permite que o usuário troque o simbolo utilizado para desenhar a tela.
   * @param _brush recebe o caractere definido pelo usuario para preencher os pixels da tela.
   * Caso não haja o fornecimento de um valor para _brush, brush receberá altomaticamente o valor '*'.
  */
  void setBrush(char _brush='*');

  /**
   * @brief Sobrecarca do operador "<<", é uma função-amiga que permite que tanto o usuario como o próprio
   *  programa envie a tela para uma stream de saida de uma forma simples.
   * @param &os variavel que recebe a informação do fluxo de saída.
   * @param &t variavel que recebe a informação do endereço da tela tratada.
   * @return o fluxo de saída modificado para apresentar a tela como uma stream na forma de uma matriz.
  */
  friend ostream& operator<<(ostream &os, Screen &t);  

  /**
   * @brief print_txt() é uma função que permite que o programa faça a impressão de tela em um arquivo(.txt) em lugar de no terminal.
   * @param &t variavel que recebe a informação do endereço da tela tratada.
   * @param &id_saida é variavel que recebe o endereço do arquivo onde o desenho será impresso.
  */
  void print_txt(Screen &tela, string &id_saida);

  /**
   * @brief print_txt() é uma função que permite que o programa faça a leitura de figuras diretamente de um arquivo(.txt)
   *  e desenhá-las conforme as instruções presentes.
   *
   * Instruções possiveis:
   * - "dim largura altura", definindo as dimenções do desenho. Ex: dim 60 20;
   * - "brush x", mudar o caractere de desenho para x;
   * - "line x0 y0 x1 y1", define uma linha do ponto (x0,y0) para (x1,y1). Ex: line 5 5 10 8;
   * - "rectangle x0 y0 largura altura", define um retângulo com ponto superior esquerdo em (x0,y0) e dimensões largura x altura.
   * Ex: rectangle 5 6 10 20;
   * - "circle x0 y0 raio fillmode", define um círculo com centro no ponto (x0,y0), raio especificado e sua forma de preenchimento.
   *  Se fillmode maior que zero, o círculo será totalmente preenchido. Caso contrário, apenas o contorno será desenhado.
   * Ex: circle 10 10 5 1 (circulo preenchido) ou Ex: circle 10 10 5 0 (apenas contorno do círculo).
   * @param &t variavel que recebe a informação do endereço da tela tratada.
   * @param &id_saida é variavel que recebe o endereço do arquivo onde estão escritos os comando a serem realizados.
  */
  void readDraw(Screen &tela, string &id_entrada);
};

#endif // SCREEN_H
