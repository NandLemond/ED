#include <iostream>

using namespace std;



struct nodo{

	char letra;

	int cantidad;

	nodo* sig;

	nodo* izq;

	nodo* der;

};

typedef nodo* Inicio;



Inicio crearNodo(char c,int f)

{

	Inicio nuevoNodo = new(nodo);

	nuevoNodo->letra = c;

	nuevoNodo->cantidad = f;

	nuevoNodo->izq = 0;

	nuevoNodo->der = 0;

	nuevoNodo->sig = 0;

	return nuevoNodo;

}



void insertar(Inicio &arbol, char c,int f)

{

	if(arbol==NULL)

		arbol = crearNodo(c,f);

	else 

	{   

		Inicio temp = crearNodo(c,f);

		Inicio temp2 = arbol;

		while(temp2->sig!=NULL)

		{ 

			temp2=temp2->sig;

		}

		temp2->sig=temp;

	}

}



int main()

{

	Inicio arbol = NULL;

	insertar(arbol, 'f',5);

	insertar(arbol, 'e',9);

	insertar(arbol, 'c',12);


	cout << arbol->letra << endl;

	cout << arbol->cantidad << endl;


	cout << arbol->sig->letra << endl;

	cout << arbol->sig->cantidad << endl;


	cout << arbol->sig->sig->letra << endl;

	cout << arbol->sig->sig->cantidad << endl;


}
