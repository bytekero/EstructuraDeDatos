#include "Pila.h"
#include "NodoPila.h"

Pila::Pila()
{
    cima = NULL;
}
Pila::~Pila()
{
    while(cima) desapilar();
}
bool Pila::esVacia()
{
    return cima == NULL;
}
void Pila::apilar(int v)
{
    pnodo nuevo = new NodoPila(v, cima);
    cima = nuevo;
}
void Pila::desapilar()
{
    pnodo nodo;
    if(cima)
        nodo = cima;
    cima = nodo->siguiente;
    delete nodo;
}
int Pila::mostrar()
{
    if(esVacia())
    {
        cout << "Pila vacia"<<endl;
    }
    else
    {
        cout << "Cima pila: "<< cima->valor<<endl;
    }
    return 0;
}
