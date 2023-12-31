#include <iostream>
#include <queue>
#include "arbol.h"
#include <vector>

using namespace std;
Arbol* nodePadre;
int n_nodos = 0;
char caracter_padre = ' ';
vector<char>hijos;
Arbol* padre_= nullptr;
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
void padre_de(Arbol* raiz, char letra, Arbol* padre ) {
  if (raiz == NULL) {
	return;
  }

  if (raiz->valor == letra) {
      //nodoBuscado = raiz;
       padre_ = padre;
      return ; 
  }

  padre_de (raiz->izqu,letra,raiz);
  padre_de (raiz->med, letra,raiz);
  padre_de (raiz->dere, letra,raiz);
}

void node_inme(Arbol* raiz,Arbol* node,char x){
  char aux = ' ';
  if(node == NULL){
      return;
  }
 padre_de(raiz,node->valor,NULL); 
 
 if(padre_ == NULL){
    aux = ' ';
 }
 else {
    aux = padre_->valor;
 }

  if(  aux == x && padre_!= NULL){
      hijos.push_back(node->valor);

      return;
  }
 
  node_inme(raiz,node->izqu,x);
  node_inme(raiz,node->med,x);
  node_inme(raiz, node->dere,x);
}
void imprimirVector(const vector<char>& vec) {
    cout << "Elementos del vector: ";
    for (const auto& elemento : vec) {
        std::cout << elemento << " ";
    }
    cout << endl;
}
void BFS(Arbol* Tree) {
    if (Tree == nullptr) {
        cout << "El árbol es nulo." << endl;
        return;
    }

    queue<Arbol*> fila;
    vector<Arbol*> mark;
    mark.push_back(Tree);
    fila.push(Tree);

    while (!fila.empty()) {
        Arbol* node_x = fila.front();
        fila.pop();

        if (node_x != nullptr) {
            caracter_padre = node_x->valor;
            node_inme(Tree, node_x, caracter_padre);
            imprimirVector(hijos);
        }
    }
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
    BFS(arbolTernario);
}
