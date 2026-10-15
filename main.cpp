#include <iostream>
#include "pizzeria.h"
#include "Cola.h"
#include <windows.h>
#include <ctime>

using namespace std;

int main()
{


    Cola colaRecibidos;
    int op;
    do{
        cout << "1. Generar pedidos" << endl;
        cout << "2. Mostrar pedidos recibidos" << endl;
        cout << "0. Salir" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> op;

        cout << endl;

        switch(op)
        {
            case 1:
            {
                int cantidad;
                cout << "¿Cuantos pedidos desea generar? ";
                cin >> cantidad;

                if (cantidad > 0) {
                    for(int i = 0; i < cantidad; i++) {
                        Pedido nuevoPedido;
                        colaRecibidos.encolar(nuevoPedido);
                    }
                    cout << ">> Se han generado y encolado " << cantidad << " pedidos correctamente." << endl;
                } else {
                    cout << ">> Cantidad no valida." << endl;
                }
                break;
            }

            case 2:
            {
                if (colaRecibidos.es_vacia()) {
                    cout << ">> La cola de pedidos esta vacia." << endl;
                } else {

                   cout << "Pedido\tCliente\tPizza\t\tTamano\tZona\tPers\tEstado" << endl;


                    int tam = colaRecibidos.get_longitud();
                    for(int i = 0; i < tam; i++) {
                        Pedido p = colaRecibidos.desencolar();

                        cout << p.id_pedido << "\t"
                             << p.id_cliente << "\t"
                             << p.tipo_pizza << "\t"
                             << p.tamano << "\t"
                             << p.zona_reparto << "\t"
                             << (p.personalizada ? "Si" : "No") << "\t"
                             << p.estado << endl;
                        colaRecibidos.encolar(p);
                    }
                    cout << "------------------------------------------------------------------------" << endl;
                    cout << "Total de pedidos en cola: " << tam << endl;
                }
                break;
            }


            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;

        }
    }while(op!=0);

    return 0;
}
