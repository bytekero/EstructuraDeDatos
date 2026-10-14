#include "NodoCola.h"

NodoCola::NodoCola(Pedido p)
{
    pedido = p;
    siguiente=NULL;
//constructor por defecto
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
