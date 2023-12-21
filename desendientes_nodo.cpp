#include <iostream>
#include <bits/stdc++.h>
#include "arbol.h"

using namespace std;

Arbol* nodoBuscado;

void recorridoPreorden(Arbol* raiz){
  if (raiz == NULL){
      return ;
  }

  cout << raiz->valor<< ';';
  recorridoPreorden(raiz->izqu);
  recorridoPreorden(raiz->med);
  recorridoPreorden(raiz->dere);
}

void busqueda(Arbol* raiz, char letra) {
  if (raiz == NULL) {
	return ;
  }

  if (raiz->valor == letra) {
      nodoBuscado = raiz;
      return;
  }

  busqueda (raiz->izqu, letra);
  busqueda (raiz->med, letra);
  busqueda (raiz->dere, letra);
}

int main() {
    char letra;
    Arbol* arbolTernario = new Arbol('F');

    arbolTernario->izqu = new Arbol('E');
    arbolTernario->med = new Arbol('D');
    arbolTernario->dere = new Arbol('B');

    arbolTernario->izqu->izqu = new Arbol('R');
    arbolTernario->izqu->med = new Arbol('Z');
    arbolTernario->izqu->dere = new Arbol('N');
    
    arbolTernario->med->izqu = new Arbol('O');
    arbolTernario->med->dere = new Arbol('I');

    arbolTernario->dere->izqu = new Arbol('A');
    
    arbolTernario->izqu->izqu->izqu = new Arbol('Q');
    arbolTernario->izqu->izqu->dere = new Arbol('X');
    arbolTernario->izqu->med->izqu = new Arbol('H');
    arbolTernario->med->izqu->izqu = new Arbol('M');
    arbolTernario->med->izqu->dere = new Arbol('W');
    arbolTernario->dere->izqu->izqu = new Arbol('L');
    arbolTernario->dere->izqu->dere = new Arbol('S'); 
    
    cout<<"ingrese el nodo: ";
    cin.get(letra);

    busqueda(arbolTernario, letra);

    if (nodoBuscado == NULL) {
	cout<< "El nodo "<<letra << "no existe.";
	return 0;
    }

    cout<< "los nodos desendientes de " << letra << "son: ";
    recorridoPreorden(nodoBuscado->izqu);
    recorridoPreorden(nodoBuscado->med);
    recorridoPreorden(nodoBuscado->dere);

    return 0;
}
