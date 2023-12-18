#include <iostream>
#include <bits/stdc++.h>
#include "arbol.h"
using namespace std;

int n_internos = 0;
int n_hojas = 0;


void  nodosInternos(Arbol *raiz){
  if (raiz == NULL) {
    return;
  }
  if (raiz->izqu != NULL || raiz->dere != NULL || raiz->med !=NULL){
    cout << raiz->valor <<',';
    n_internos++;
  }

  nodosInternos(raiz->izqu);
  nodosInternos(raiz->med);
  nodosInternos(raiz->dere);
  
}

void nodosHoja(Arbol* raiz){
  if (raiz == NULL) {
    return;
  }

  if(raiz->izqu == NULL && raiz->dere == NULL && raiz->med == NULL){
      cout<< raiz->valor << ',';
      n_hojas++;
  }

  nodosHoja(raiz->izqu);
  nodosHoja(raiz->med);
  nodosHoja(raiz->dere);
}

int main() {
    Arbol* arbolTernario = new Arbol('F');

    arbolTernario->izqu = new Arbol('E');
    arbolTernario->med = new Arbol('R');
    arbolTernario->dere = new Arbol('N');


    arbolTernario->izqu->izqu = new Arbol('A');
    arbolTernario->izqu->med = new Arbol('N');
    arbolTernario->izqu->dere = new Arbol('D');

    arbolTernario->med->izqu = new Arbol('O');
    arbolTernario->med->dere = new Arbol('A');

    arbolTernario->dere->izqu = new Arbol('N');
    arbolTernario->dere->dere = new Arbol('I');


    arbolTernario->izqu->izqu->izqu = new Arbol('B');
    arbolTernario->izqu->izqu->dere = new Arbol('A');
    
    arbolTernario->izqu->dere->izqu = new Arbol('L');

    arbolTernario->dere->izqu->izqu = new Arbol('s');
    arbolTernario->dere->izqu->dere = new Arbol('U');


    arbolTernario->dere->izqu->izqu->izqu = new Arbol('c');


    nodosInternos(arbolTernario);
    cout<<endl;
    cout<<"cantidad de nodos internos: "<<n_internos<<endl;

    nodosHoja(arbolTernario);
    cout<<endl;
    cout<<"cantidad de nodos hoja: "<<n_hojas<<endl;

    cout<<"total de nodos : "<<n_internos+n_hojas<<endl;
      return 0;
      
}





