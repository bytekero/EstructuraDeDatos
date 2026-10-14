#ifndef PIZZERIA_H_INCLUDED
#define PIZZERIA_H_INCLUDED

#include <string>

struct Pedido
{
    std::string id_pedido;
    int id_cliente;
    std::string tipo_pizza;
    std::string tamano;
    std::string zona_reparto;
    bool personalizada;
    std::string estado;

    Pedido();
};

#endif // PIZZERIA_H_INCLUDED
