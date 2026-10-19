#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include <string>

class Cola
{
private:
    NodoCola * primero;
    NodoCola * ultimo;
    int longitud;
    std::string nombre;
public:
    Cola();
    Cola(std::string nom);
    ~Cola();
    void encolar(Pedido);
    Pedido inicio();
    Pedido fin();
    Pedido desencolar();
    int get_longitud();
    std::string get_nombre();
    bool es_vacia();
    void mostrarCola(); //No es correcto, se implementa para ver que está creada correctamente
};

#endif // COLA_H
