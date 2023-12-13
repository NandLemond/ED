#include <iostream>
#include <bits/stdc++.h>
#include "arbol.h"

void recorridoPreorden(Arbol *raiz) {
    if (raiz == NULL) {
        return;
    }
    std::cout << raiz->valor << ",";
    recorridoPreorden(raiz->izqu);
    recorridoPreorden(raiz->med);
    recorridoPreorden(raiz->dere);
}

void recorridoInorden(Arbol *raiz) {
    if (raiz == NULL) {
        return;
    }
    recorridoInorden(raiz->izqu);
    std::cout << raiz->valor << ",";
    recorridoInorden(raiz->med);
    recorridoInorden(raiz->dere);
}

void recorridoPosorden(Arbol *raiz) {
    if (raiz == NULL) {
        return;
    }
    recorridoPosorden(raiz->izqu);
    recorridoPosorden(raiz->med);
    recorridoPosorden(raiz->dere);
    std::cout << raiz->valor << ",";
}

int main() {
    Arbol *arbolTernario = new Arbol('F');

    arbolTernario->izqu = new Arbol('E');
    arbolTernario->med = new Arbol('D');
    arbolTernario->dere = new Arbol('B');

    arbolTernario->izqu->izqu = new Arbol('R');
    arbolTernario->izqu->med = new Arbol('N');
    arbolTernario->izqu->dere = new Arbol('N');
    
    arbolTernario->med->izqu = new Arbol('O');
    arbolTernario->med->dere = new Arbol('I');
    arbolTernario->dere->izqu = new Arbol('A');
    
    arbolTernario->izqu->izqu->izqu = new Arbol('N');
    arbolTernario->izqu->izqu->dere = new Arbol('A');
    arbolTernario->izqu->med->izqu = new Arbol('N');
    arbolTernario->med->izqu->izqu = new Arbol('A');
    arbolTernario->med->izqu->dere = new Arbol('N');
    arbolTernario->dere->izqu->izqu = new Arbol('L');
    arbolTernario->dere->izqu->dere = new Arbol('S'); 

    // Realizar recorridos
    std::cout << "Recorrido Preorden: ";
    recorridoPreorden(arbolTernario);
    std::cout << std::endl;

    std::cout << "Recorrido Inorden: ";
    recorridoInorden(arbolTernario);
    std::cout << std::endl;

    std::cout << "Recorrido Postorden: ";
    recorridoPosorden(arbolTernario);
    std::cout << std::endl;

      return 0;
}





