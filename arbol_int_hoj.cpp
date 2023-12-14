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
  //RAIZ
    Arbol* arbolTernario = new Arbol('A');

  // SEGUNDO NIVEL
    arbolTernario->izqu = new Arbol('B');
    arbolTernario->med = new Arbol('C');
    arbolTernario->dere = new Arbol('D');

  // TERCER NIVEL
    arbolTernario->izqu->izqu = new Arbol('E');
    arbolTernario->izqu->med = new Arbol('F');
    arbolTernario->izqu->dere = new Arbol('G');
    
    arbolTernario->dere->izqu = new Arbol('H');
    arbolTernario->dere->med = new Arbol('I');
    arbolTernario->dere->dere = new Arbol('J');
    
  // CUARTO NIVEL 
    arbolTernario->izqu->izqu->izqu = new Arbol('K');
    arbolTernario->izqu->izqu->med = new Arbol('L');
    arbolTernario->izqu->izqu->dere = new Arbol('M');


    nodosInternos(arbolTernario);
    cout<<endl;
    cout<<"cantidad de nodos internos: "<<n_internos<<endl;

    nodosHoja(arbolTernario);
    cout<<endl;
    cout<<"cantidad de nodos hoja: "<<n_hojas<<endl;

    cout<<"total de nodos : "<<n_internos+n_hojas<<endl;
      return 0;
      
}





