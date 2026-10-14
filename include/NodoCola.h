#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include "pizzeria.h"

class NodoCola
{
    friend class Cola;
private:
    NodoCola *siguiente;
    Pedido pedido;
public:
    NodoCola(Pedido p);
    NodoCola(Pedido p, NodoCola*sig);
    ~NodoCola();
};

#endif // NODOCOLA_H
