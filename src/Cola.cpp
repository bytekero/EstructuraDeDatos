#include <iostream>
#include "Cola.h"
#include "pizzeria.h"

using namespace std;

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() { }

void Cola::encolar(Pedido pedido)
{
    NodoCola *nuevo_nodo = new
    NodoCola(pedido);
    if(es_vacia())
    {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    else
    {
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;
}

Pedido Cola::desencolar()
{
    if(!es_vacia())
    {
        Pedido pedido = primero->pedido;
        NodoCola *aux = primero;
        if((primero == ultimo) && (primero->siguiente == NULL))
        {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        longitud--;
        return pedido;
    }
    else
    {
        Pedido pedidoVacio;
        pedidoVacio.id_pedido = "-1";
        pedidoVacio.estado = "null";

        return pedidoVacio;
    }
}

Pedido Cola::inicio()
{
    if(!es_vacia())
    {
        return primero->pedido;
    }
}

Pedido Cola::fin()
{
    if(!es_vacia())
    {
        return ultimo->pedido;
    }
}

int Cola::get_longitud()
{
    return longitud;
}

bool Cola::es_vacia()
{
    return ((primero==NULL) && (ultimo==NULL));
}

void Cola::mostrarCola()
//No es correcto, la cola solo puede verse mostrando el primero y desencolando, se implementa para comprobar código facilmente.
{
    NodoCola *aux = primero;
    if (es_vacia())
    {
        cout<<"Cola Vacía: "<<endl;
    }
    else
    {
        cout<<"Datos de la Cola: "<<endl;
        while (aux)
        {
            cout << aux->pedido.id_pedido<<endl;
            aux = aux->siguiente;
        }
    }
}
