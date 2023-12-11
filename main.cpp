#include <iostream>

using namespace std;
#include <bits/stdc++.h>
#include "arbol.h"

void recorridoPreorden (Arbol *raiz){
  if (raiz == NULL){
    return;
  }
  cout<< raiz ->valor <<",";
  recorridoPreorden (raiz->izqu);
  recorridoPreorden(raiz->dere);
}

void recorridoInorden (Arbol *raiz){
  if (raiz == NULL){
    return;
  }
  cout<< raiz ->valor <<",";
  recorridoInorden (raiz->izqu);
  recorridoInorden(raiz->dere);
}

