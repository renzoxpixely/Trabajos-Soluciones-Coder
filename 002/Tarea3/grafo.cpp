/********************************************
*											*
*	Nombre: Dijkstra's Shortest Path		*
*	Autor:	Francisco Manuel Valle Ruiz		*
*	Fecha:	Abril 2013						*
*											*
*********************************************/

#include <iostream>
#include "Grafica.h"
using namespace std;

int main()
{
    Grafica G;

    cout << "\t--------------------------\n";
    cout << "\t1: Agregar nodo \n";
    cout << "\t2: Agregar arco \n";
    cout << "\t3: Pintar nodos \n";
    cout << "\t4: Pintar arcos \n";
    cout << "\t5: Pintar grafica \n";
    cout << "\t6: Encontrar ruta mas corta\n";
    cout << "\t-1: Salir \n";
    cout << "\t--------------------------\n";

    int op = 0;
    do{
        cout << "Que deseas hacer?: ";
        cin >> op;

        switch(op){
            case 1:
                int aux;
                cout << "Agregar nodo.\n";
                cout << "Cual es el num del nodo que desea agregar?: ";
                cin >> aux;
                G.agregar_nodo(aux);
                break;
            case 2:
                int aux_in, aux_out, aux_long;
                cout << "Agregar arco.\n";
                cout << "Nodo de salida?: ";
                cin >> aux_in;
                cout << "Nodo de entrada?: ";
                cin >> aux_out;
                cout << "Longitud?: ";
                cin >> aux_long;
                G.agregar_arco(aux_in, aux_out, aux_long);
                break;
            case 3:
                cout << "Pintar nodos. \n";
                cout << "Nodos: \n\t";
                G.pintar_nodos();
                break;
            case 4:
                cout << "Pintar arcos. \n";
                cout << "Arcos: \n\t" << endl;
                G.pintar_arcos();
                break;
            case 5:
                cout << "Pintar grafica. \n";
                cout << "Grafo: \n\t" << endl << endl;
                G.pintar();
                break;
            case 6:
                int aux_begin, aux_end;
                cout << "Encontrar ruta mas corta. \n";
                cout << "Desde que nodo?: ";
                cin >> aux_begin;
                cout << "Hasta que nodo?: ";
                cin >> aux_end;
                G.ruta_corta(aux_begin, aux_end);

                cout << "Gracias, vuelve pronto! :)\n";
                op = -1;
                break;
            case -1:
                cout << "Gracias, vuelve pronto! :)\n";
                break;
            default:
                cout << "Ingresa una opcion valida\n";
                break;
        }
        cout << "\n";
    }while(op != -1);


    cin.ignore();
    cin.get();
}
