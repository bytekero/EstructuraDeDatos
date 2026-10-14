#include "pizzeria.h"
#include <cstdlib>
#include <ctime>
#include <string>

#define PROB_PERSONALIZACION 20;

using namespace std;

Pedido::Pedido()
{
    string tipos[6] = {"Margarita", "Barbacoa", "Vegetal", "Hawaiana", "Romana", "Cuatro quesos"};
    string tamanos[2] = {"Mediana", "Grande"};
    string zonas[4] = {"Norte", "Sur", "Este", "Oeste"};

    id_pedido = "P";
    for (int i = 0; i < 5; i++) {
        int num = rand() % 10;
        id_pedido += to_string(num);
    }

    id_cliente = 100 + (rand() % 900);
    tipo_pizza = tipos[rand() % 6];
    tamano = tamanos[rand() % 2];
    zona_reparto = zonas[rand() % 4];
    personalizada = (rand() % 101) <= PROB_PERSONALIZACION;
    estado = "Recibido";
}
