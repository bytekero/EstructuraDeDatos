#ifndef NODOPILA_H
#define NODOPILA_H
#include <iostream>
#include "pizzeria.h"

class NodoPila
{
    friend class Pila;
private:
    Pedido pedido;
    NodoPila *siguiente;
public:
    NodoPila(Pedido p);
    NodoPila(Pedido p, NodoPila *sig);
    ~NodoPila();
    Pedido get_pedido();
};
typedef NodoPila *pnodo;

#endif // NODOPILA_H
