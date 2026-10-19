#include <iostream>
#include <string>
#include "pizzeria.h"
#include "Cola.h"
#include <windows.h>
#include <ctime>

#define PROB_PERSONALIZACION 20
#define N_PEDIDOS_PASO 10

using namespace std;

Cola colaRecibidos ("Recibidos");
Cola preparacionEspecial("Preparacion especial");
Cola cocina("Cocina");
Cola expedicionNorte("Expedicion norte");
Cola expedicionSur("Expedicion sur");
Cola expedicionEste("Expedicion este");
Cola expedicionOeste("Expedicion oeste");

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
        int contPers = cantidad * PROB_PERSONALIZACION / 100;
        for(int i = 0; i < cantidad; i++)
        {
            bool pers = false;
            if (contPers > 0)
            {
                pers = true;
                contPers--;
            }
            Pedido nuevoPedido(pers);
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
    Cola colas[7] = {colaRecibidos, preparacionEspecial, cocina, expedicionNorte, expedicionSur, expedicionEste, expedicionOeste};
    Cola colaAux;
    for (int i= 0; i < 7; i++)
    {
        colaAux = colas[i];
        if (colaAux.es_vacia())
        {
            cout << ">> La cola " << colaAux.get_nombre() << " esta vacia." << endl;
        }
        else
        {
            cout << "COLA " << colaAux.get_nombre() << endl;
            cout << alinear("Pedido", 10)
                 << alinear("Cliente", 10)
                 << alinear("Pizza", 15)
                 << alinear("Tamano", 12)
                 << alinear("Zona", 10)
                 << alinear("Pers", 8)
                 << alinear("Estado", 10) << endl;

            int tam = colaAux.get_longitud();
            for(int i = 0; i < tam; i++)
            {
                Pedido p = colaAux.desencolar();

                cout << alinear(p.id_pedido, 10)
                     << alinear(to_string(p.id_cliente), 10)
                     << alinear(p.tipo_pizza, 15)
                     << alinear(p.tamano, 12)
                     << alinear(p.zona_reparto, 10)
                     << alinear((p.personalizada ? "Si" : "No"), 8)
                     << alinear(p.estado, 10) << endl;
                colaAux.encolar(p);
            }
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Total de pedidos en cola: " << tam << endl;
        }
    }

}

void paso_expedicion()
{
    for (int i = 0; i<N_PEDIDOS_PASO; i++) {

    }
}

void paso_cocina()
{
    for (int i = 0; i<N_PEDIDOS_PASO; i++) {

    }
}

void paso_preparacion_especial()
{
    for (int i = 0; i<N_PEDIDOS_PASO; i++) {

    }
}

void ejecutar_paso()
{
    paso_expedicion();
    paso_cocina();
    paso_preparacion_especial();
}

void mostrar_menu()
{
    int op;
    do
    {
        cout << "1. Generar N pedidos" << endl;
        cout << "2. Ejecutar un paso de simulacion" << endl;
        cout << "3. Mostrar el estado del  sistema" << endl;
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
        case 3:
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
