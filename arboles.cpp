#include <iostream>
using namespace std;
#include "arbol.h"

Arbol::Arbol(char valor){
  this -> valor = valor;
  this -> izqu = NULL;
  this -> dere = NULL;
}

