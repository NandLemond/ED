#include <iostream>
#include <queue>
#include "arbol.h"
#include <vector>

using namespace std;
Arbol* nodePadre;
char caracter_padre = ' ';
vector<Arbol*>hijos;
Arbol* padre_= nullptr;

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
      hijos.push_back(node);

      return;
  }
 
  node_inme(raiz,node->izqu,x);
  node_inme(raiz,node->med,x);
  node_inme(raiz, node->dere,x);
}
void imprimirVector(const vector<Arbol*>& vec) {
    cout << "marcado :";
    for (const auto& elemento : vec) {
        std::cout << elemento->valor << " ";
    }
    cout << endl;
}
void imprimirCola(const queue<Arbol*>& cola) {
    queue<Arbol*> copiaCola = cola;
    cout<<"fila: ";
    while (!copiaCola.empty()) {
        cout << (copiaCola.front())->valor << " ";
        copiaCola.pop();
    }

    cout << endl;
}

bool nodo_visitado(Arbol* hijo, vector<Arbol*> visited){
    bool visitado = false;
    for(const Arbol* item : visited){
      if(item->valor == hijo->valor)
	  visitado = true;
    }
    return visitado;
}

void BFS(Arbol* Tree,char valor_de_busq) {
    if (Tree == nullptr) {
        cout << "El árbol es nulo." << endl;
        return;
    }
    if(valor_de_busq == Tree-> valor){
	  cout<<valor_de_busq<<" es el nodo raiz del arbol"<<endl;
	  return;
	}


    queue<Arbol*> fila;
    vector<Arbol*> mark;
    mark.push_back(Tree);
    fila.push(Tree);
    imprimirCola(fila);
    imprimirVector(mark);
    cout<<endl;
    bool encontrado = false;

    while (!fila.empty()&& !encontrado) {
        hijos.clear();
        Arbol* node_x = fila.front();
        fila.pop();
        caracter_padre = node_x->valor;
        node_inme(Tree, node_x, caracter_padre);
      
	for(const auto& elemento :hijos){
	  if(elemento->valor == valor_de_busq){
		cout<<node_x->valor<<"->"<<elemento->valor<<endl;
		encontrado = true;
		return;
	  }
	  if(!nodo_visitado(elemento,mark) && !encontrado){
		fila.push(elemento);
		mark.push_back(elemento);
	  }
	}
	if(!encontrado){
	  imprimirCola(fila);
	  imprimirVector(mark);
	  cout<<endl;
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
    arbolTernario->med->dere = new Arbol('S');

    arbolTernario->dere->izqu = new Arbol('U');


    arbolTernario->izqu->izqu->izqu = new Arbol('C');
    arbolTernario->izqu->izqu->dere = new Arbol('W');
    
    arbolTernario->izqu->med->izqu = new Arbol('Q');

    arbolTernario->med->izqu->izqu = new Arbol('V');
    arbolTernario->med->izqu->dere = new Arbol('Y');


    arbolTernario->dere->izqu->izqu = new Arbol('Z');
    arbolTernario->dere->izqu->dere = new Arbol('X');

    char node_buscar;
    cout<<"Ingrese el nodo: ";
    cin>>node_buscar;
    cout<<"Busqueda primero por anchura"<<endl;
    BFS(arbolTernario,node_buscar);
}
