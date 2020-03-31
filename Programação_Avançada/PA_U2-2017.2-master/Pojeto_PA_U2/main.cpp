#include <iostream>
#include "Point.h"
#include "Poligono.h"
#include "Retangulo.h"

using namespace std;

int main(void)
{
    cout << "Exemplos-teste requeridos: " << endl;
    Retangulo r1(0,0,4,3);

    cout << "r1 = "; r1.printPoligono();
    cout << "Area de r1 = " << r1.Area() << endl << endl;

    r1.transladaPoligono(-3,4);
    cout << "r1_transladado = "; r1.printPoligono();
    cout << "Area de r1_transladado = " << r1.Area() << endl << endl;

    cout << "Area de r1 == Area de r1_transladado" << endl << endl;

    r1.rotaciona(30,-1,2.5);
    cout << "r1_rotacionado = "; r1.printPoligono();
    cout << "Area de r1_rotacionado = " << r1.Area() << endl << endl;

    cout << "Area de r1 == Area de r1_transladado == Area de r1_rotacionado" << endl << endl;
    return 0;
}

