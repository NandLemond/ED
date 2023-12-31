#include <array>
#include <iostream>
#include <bits/stdc++.h>
#include "arbol.h"

using namespace std;
int cant = 0;
char* arreglo = new char[100];
int n_hojas=0;
int altura=0;
bool verificador=false;

Arbol* nodoBuscado;
Arbol* nodoPadre;

void inicializar_Arreglo(int cant){
  arreglo = new char[cant];
}
void equilibrio_arbol(int altura_nod){
  if(altura_nod == altura || altura_nod == altura-1)
    verificador = true;
  else
    verificador = false;
}

void nodosHoja(Arbol* raiz){
  if (raiz == NULL) {
    return;
  }

  if(raiz->izqu == NULL && raiz->dere == NULL && raiz->med == NULL){
      arreglo[n_hojas]=raiz->valor;
      n_hojas++;
  }

  nodosHoja(raiz->izqu);
  nodosHoja(raiz->med);
  nodosHoja(raiz->dere);
}

void busqueda(Arbol* raiz, char letra, Arbol* padre) {
  if (raiz == NULL) {
	return ;
  }

  if (raiz->valor == letra) {
      nodoBuscado = raiz;
      nodoPadre = padre;

      return;
  }

  busqueda (raiz->izqu, letra,raiz);
  busqueda (raiz->med, letra,raiz);
  busqueda (raiz->dere, letra,raiz);
}

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

void altura_nodos_hoja(Arbol* arbolTernario){
  for(int i=0;i<n_hojas;i++){
    busqueda(arbolTernario, arreglo[i],NULL);
    cout<< "Nodo hoja " << arreglo[i] << ": ";
    while(nodoPadre != NULL) {
	//cout<< nodoPadre->valor << endl;
	busqueda(arbolTernario, nodoPadre->valor,NULL);
	cant++;
    }
    cout<<"altura es: "<<cant<<endl;
    equilibrio_arbol(cant);
    cant=0;
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
    altura=obtenerAltura(arbolTernario);
    nodosHoja(arbolTernario);
    cout<<endl;
    
    altura_nodos_hoja(arbolTernario);  
  
    if(verificador)
      cout<<"arbol SI esta equilibrado"<<endl;
    else if(verificador==false)
      cout<<"el arbol no esta equilibrado"<<endl;
    return 0;

}

