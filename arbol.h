#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED



class Arbol
{
  public:
    char valor;
    Arbol *izqu;
    Arbol *dere;
    Arbol *med;

    Arbol(char valor);
    void recorridoPreorden(Arbol *raiz);
    void recorridoInorden(Arbol *raiz);
    void recorridoPosorden(Arbol *raiz);
};
#endif// ARBOL_H_INCLUDED 
