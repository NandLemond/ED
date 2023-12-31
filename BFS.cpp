#include <iostream>
#include <queue>
#include "arbol.h"
#include <vector>

using namespace std;

int n_nodos = 0;

void  nodosInternos(Arbol *raiz){
  if (raiz == NULL) {
    return;
  }
  if (raiz->izqu != NULL || raiz->dere != NULL || raiz->med !=NULL){
    n_nodos++;
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
      n_nodos++;
  }
  nodosHoja(raiz->izqu);
  nodosHoja(raiz->med);
  nodosHoja(raiz->dere);

}
void nodos_totales(Arbol* raiz){
  nodosHoja(raiz);
  nodosInternos(raiz);
}
void BFS(Arbol* Tree,char value){
   queue<char> fila;
   vector<char> mark;
   mark.push_back(Tree->valor);
   fila.push(Tree->valor);
  // cout<<fila.front()<<mark.at(0)<<endl;
   



}
int main(){
    Arbol* arbolTernario = new Arbol('F');

    arbolTernario->izqu = new Arbol('E');
    arbolTernario->med = new Arbol('R');
    arbolTernario->dere = new Arbol('N');


    arbolTernario->izqu->izqu = new Arbol('A');
    arbolTernario->izqu->med = new Arbol('M');
    arbolTernario->izqu->dere = new Arbol('D');

    arbolTernario->med->izqu = new Arbol('O');
    arbolTernario->med->dere = new Arbol('Z');

    arbolTernario->dere->izqu = new Arbol('Q');
    arbolTernario->dere->dere = new Arbol('I');


    arbolTernario->izqu->izqu->izqu = new Arbol('B');
    arbolTernario->izqu->izqu->dere = new Arbol('U');
    
    arbolTernario->izqu->dere->izqu = new Arbol('L');

    arbolTernario->dere->izqu->izqu = new Arbol('S');
    arbolTernario->dere->izqu->dere = new Arbol('V');


    arbolTernario->dere->izqu->izqu->izqu = new Arbol('P');
    nodos_totales(arbolTernario); 
    BFS(arbolTernario,'a');
}
