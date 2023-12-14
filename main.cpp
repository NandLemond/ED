#include <iostream>
#include <bits/stdc++.h>
#include "arbol.h"
using namespace std;

int n_internos = 0;
int n_hojas = 0;

void recorridoPreorden(Arbol *raiz) {
    if (raiz == NULL) {
        return;
    }
    cout << raiz->valor << ",";
    recorridoPreorden(raiz->izqu);
    recorridoPreorden(raiz->med);
    recorridoPreorden(raiz->dere);
}

void recorridoInorden(Arbol *raiz) {
    if (raiz == NULL) {
        return;
    }
    recorridoInorden(raiz->izqu);
    cout << raiz->valor << ",";
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
    cout << raiz->valor << ",";
}

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

 /*   // Realizar recorridos
    cout << "Recorrido Preorden: ";
    recorridoPreorden(arbolTernario);
    std::cout << endl;

    cout << "Recorrido Inorden: ";
    recorridoInorden(arbolTernario);
    std::cout << endl; 

    cout << "Recorrido Postorden: ";
    recorridoPosorden(arbolTernario);
    cout << endl;
*/
    nodosInternos(arbolTernario);
    cout<<endl;
    cout<<"cantidad de nodos internos: "<<n_internos<<endl;

    nodosHoja(arbolTernario);
    cout<<endl;
    cout<<"cantidad de nodos hoja: "<<n_hojas<<endl;

    cout<<"total de nodos : "<<n_internos+n_hojas<<endl;
      return 0;
      
}





