
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
