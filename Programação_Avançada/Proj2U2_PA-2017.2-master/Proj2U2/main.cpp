#include <iostream>
#include <vector>

#include "circulo.h"
#include "figuraGeometrica.h"
#include "reta.h"
#include "retangulo.h"
#include "screen.h"


using namespace std;

int main(void)
{
    Screen tela(16,16);

    //Teste para arquivo
    //Arquipo com comandos
    string id_entrada = "C:/Users/Rejane Nobre/Desktop/proj2U2_1.0.5/Proj2U2_R.txt";

    //Arquipo onde o desenho será impresso
    string id_saida = "C:/Users/Rejane Nobre/Desktop/proj2U2_1.0.5/Proj2U2_W.txt";

    tela.readDraw(tela, id_entrada);
    tela.print_txt(tela, id_saida);
    tela.clear();

    //teste para tela
    tela.setBrush('H');
    Retangulo rg(0,14, 14,14, 0);
    rg.draw(tela);

    tela.setBrush('\\');
    Circulo c1(7,7,5,1);
    c1.draw(tela);

    tela.setBrush('8');
    Reta rt1(2,5,13,5);
    rt1.draw(tela);

    Reta rt2(3,6,7,6);
    rt2.draw(tela);
    Reta rt3(8,6,12,6);
    rt3.draw(tela);

    Reta rt4(4,7,6,7);
    rt4.draw(tela);
    Reta rt5(9,7,11,7);
    rt5.draw(tela);

    tela.setBrush('#');
    Reta rt6(5,9,10,9);
    rt6.draw(tela);
    Reta rt7(6,10,9,10);
    rt7.draw(tela);
    cout << tela;
}
