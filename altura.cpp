#include <iostream>
#include <bits/stdc++.h>
#include "arbol.h"

using namespace std;

Arbol* nodoBuscado;

int obtenerAltura(Arbol *raiz) {
  if (raiz == NULL){
      return -1;
  }

  int alturaIzqu = obtenerAltura(raiz->izqu);
  int alturaDere = obtenerAltura(raiz->dere); 

  if (alturaIzqu > alturaDere){
      return alturaIzqu + 1;
  }
  else {
      return alturaDere + 1;
  }
}

int main() {
    
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
   
    cout<<"La altura del Arbol es :" <<obtenerAltura(arbolTernario);
    return 0;
}
