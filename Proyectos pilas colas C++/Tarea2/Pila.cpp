#include <iostream>
#include "Pila.h"
using namespace std;

int main()
{
	Pila pila;
	int valor_elemento;
	int op;
	cout << "Pila\n";
	cout << "0: Agregar elemento\t";
	cout << "1: Sacar elemento\n";
	cout << "2: Cuantos?\t\t";
	cout << "3: Pintar\n";
	cout << "-1: Salir\n\n";

	while(op != -1){
	    cout << "Op: ";
        cin >> op;
        switch (op){
            case 0:
                cout << "Elemento a agregar: ";
                cin >> valor_elemento;
                pila.push(valor_elemento);
                break;
            case 1:
                if(pila.get_cuantos() != 0){
                    cout << "Se saco el elemento " << pila.pop() <<"\n";
                }else{
                    cout << "La pila esta vacia.\n";
                }
                break;
            case 2:
                cout << "La lista tiene "<< pila.get_cuantos() << " elementos\n";
                break;
            case 3:
                pila.pintar();
                break;
        }
	}
	return 0;
}
