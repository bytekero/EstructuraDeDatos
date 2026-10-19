#include "NodoCola.h"

NodoCola::NodoCola(Pedido p)
{
    pedido = p;
    siguiente=NULL;
}

NodoCola::NodoCola(Pedido p, NodoCola*sig)
{
    pedido = p;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
//dtor
}

Pedido NodoCola::get_pedido()
{
    return pedido;
}
