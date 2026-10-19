#include <iostream>
#include <string>
#include "pizzeria.h"
#include "Cola.h"
#include <windows.h>
#include <ctime>

using namespace std;

Cola colaRecibidos;

int leerEnteroSeguro(string mensaje)
{
    int numero;
    cout << mensaje;
    while (!(cin >> numero))
    {
        cout << "Debe introducir un numero: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return numero;
}

void generar_pedidos()
{
    int cantidad = leerEnteroSeguro("¿Cuantos pedidos desea generar? ");

    if (cantidad > 0)
    {
        for(int i = 0; i < cantidad; i++)
        {
            Pedido nuevoPedido;
            colaRecibidos.encolar(nuevoPedido);
        }
        cout << ">> Se han generado y encolado " << cantidad << " pedidos correctamente." << endl;
    }
    else
    {
        cout << ">> Cantidad no valida." << endl;
    }
}

string alinear(string texto, int ancho)
{
    if (texto.length() >= (size_t)ancho)
    {
        return texto;
    }
    return texto + string(ancho - texto.length(), ' ');
}

void mostrar_pedidos()
{
    if (colaRecibidos.es_vacia())
    {
        cout << ">> La cola de pedidos esta vacia." << endl;
    }
    else
    {
        cout << alinear("Pedido", 10)
             << alinear("Cliente", 10)
             << alinear("Pizza", 15)
             << alinear("Tamano", 12)
             << alinear("Zona", 10)
             << alinear("Pers", 8)
             << alinear("Estado", 10) << endl;

        int tam = colaRecibidos.get_longitud();
        for(int i = 0; i < tam; i++)
        {
            Pedido p = colaRecibidos.desencolar();

            cout << alinear(p.id_pedido, 10)
                 << alinear(to_string(p.id_cliente), 10)
                 << alinear(p.tipo_pizza, 15)
                 << alinear(p.tamano, 12)
                 << alinear(p.zona_reparto, 10)
                 << alinear((p.personalizada ? "Si" : "No"), 8)
                 << alinear(p.estado, 10) << endl;
            colaRecibidos.encolar(p);
        }
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Total de pedidos en cola: " << tam << endl;
    }
}

void mostrar_menu()
{
    int op;
    do
    {
        cout << "1. Generar pedidos" << endl;
        cout << "2. Mostrar pedidos recibidos" << endl;
        cout << "0. Salir" << endl;
        cout << "-----------------------------------------" << endl;
        op = leerEnteroSeguro("Seleccione una opcion: ");
        cout << endl;

        switch(op)
        {
        case 1:
        {
            generar_pedidos();
            break;
        }
        case 2:
        {
            mostrar_pedidos();
            break;
        }
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;

        }
    }
    while(op!=0);
}

int main()
{
    mostrar_menu();
    return 0;
}
