#include "NodoPila.h"

NodoPila::NodoPila(Pedido p)
{
    pedido = p;
    siguiente=NULL;
}

NodoPila::NodoPila(Pedido p, NodoPila *sig)
{
    pedido = p;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
//dtor
}

Pedido NodoCola::get_pedido()
{
    return pedido;
}
